#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

#line 1 "structure/others/binary-indexed-tree.hpp"
/**
 * @brief Binary-Indexed-Tree(BIT)
 * @docs docs/binary-indexed-tree.md
 */
template< typename T >
struct BinaryIndexedTree {
private:
    int n;
    vector< T > data;

public:
    BinaryIndexedTree() = default;

    explicit BinaryIndexedTree(int n) : n(n) {
        data.assign(n + 1, T());
    }

    explicit BinaryIndexedTree(const vector< T > &v) :
            BinaryIndexedTree((int) v.size()) {
        build(v);
    }

    void build(const vector< T > &v) {
        assert(n == (int) v.size());
        for(int i = 1; i <= n; i++) data[i] = v[i - 1];
        for(int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if(j <= n) data[j] += data[i];
        }
    }

    void apply(int k, const T &x) {
        for(++k; k <= n; k += k & -k) data[k] += x;
    }

    T prod(int r) const {
        T ret = T();
        for(; r > 0; r -= r & -r) ret += data[r];
        return ret;
    }

    T prod(int l, int r) const {
        return prod(r) - prod(l);
    }

    int lower_bound(T x) const {
        int i = 0;
        for(int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if(i + k <= n && data[i + k] < x) {
                x -= data[i + k];
                i += k;
            }
        }
        return i;
    }

    int upper_bound(T x) const {
        int i = 0;
        for(int k = 1 << (__lg(n) + 1); k > 0; k >>= 1) {
            if(i + k <= n && data[i + k] <= x) {
                x -= data[i + k];
                i += k;
            }
        }
        return i;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector< int > A(N);
        for(auto& a : A) cin >> a;
        for(auto& a : A) --a;
        int64 ret = 0;
        BinaryIndexedTree< int > bit(N);
        for(int i = 0; i < N; i++) {
            if(A[i] < i) {
                ret += bit.prod(A[i]);
                bit.apply(i, 1);
            }
        }
        cout << ret << endl;
    }
}