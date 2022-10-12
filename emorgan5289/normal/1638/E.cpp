#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

// ordered statistic tree using fenwick tree.
// all operations take O(log(N)),
// where N is the limit on size of elements.
// see https://codeforces.com/blog/entry/61364

template<int N, typename T = int>
struct fenwick_multiset {

    T s = 0, tree[N+1];
    T size() const { return s; }
    fenwick_multiset() { fill(tree, tree+N+1, 0); }
    
    // insert x into the set with multiplicity k
    void insert(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const T k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    T index(int x) const {
        if (x <= 0) return 0;
        if (x >= N) return size();
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    T count_lower(int x) const {
        return index(x);
    }

    T count_greater(int x) const {
        return size()-index(x+1);
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
        if (x < 0 || x >= N) return 0;
        int y = x+1; T i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(T x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

const int N = 1e6+5;
ll n, q;
ll c_offset[N], group_c[N];
fenwick_multiset<N, ll> left_endpoint;
fenwick_multiset<N, ll> a_diff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    left_endpoint.insert(0);
    group_c[0] = 1;
    while (q--) {
        string s; cin >> s;
        if (s == "Color") {
            ll l, r, c; cin >> l >> r >> c; l--, r--;

            // cut l
            if (!left_endpoint.count(l)) {
                group_c[l] = group_c[left_endpoint.next_lower(l)];
                left_endpoint.insert(l);
            }

            // cut r
            if (!left_endpoint.count(r+1)) {
                group_c[r+1] = group_c[left_endpoint.next_lower(r+1)];
                left_endpoint.insert(r+1);
            }

            // recolor
            for (int i = l; i != r+1; i = left_endpoint.next_greater(i)) {
                a_diff.insert(i, c_offset[group_c[i]]-c_offset[c]);
                a_diff.insert(left_endpoint.next_greater(i), c_offset[c]-c_offset[group_c[i]]);
                group_c[i] = c;
            }

            // merge
            for (int i = left_endpoint.next_greater(l); i != r+1; i = left_endpoint.next_greater(i))
                left_endpoint.remove(i);
        }
        if (s == "Add") {
            ll c, x; cin >> c >> x;
            c_offset[c] += x;
        }
        if (s == "Query") {
            ll i; cin >> i; i--;
            ll c = group_c[left_endpoint.next_lower(i+1)];
            cout << a_diff.count_lower(i+1) + c_offset[c] << "\n";
        }
    }
}