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

const int N = 5005, B = 16;
int n, k, p[N], rs[1<<B], dp[N][256], w[B], rc[B+1];

fenwick_multiset<N> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        p[x-1] = i;
    }

    vector<int> s;
    for (int i = 0; i < (1<<(2*k)); i++)
        if (__builtin_popcount(i) == k) {
            int l = __builtin_ctz(i+1);
            int r = sizeof(int)*8 - 1 - __builtin_clz(i);
            if (r-l <= k) s.push_back(i);
        }

    fill(rs, rs+(1<<B), -1);
    for (int i = 0; i < s.size(); i++)
        rs[s[i]] = i;

    for (int i = 0; i <= n; i++)
        fill(dp[i], dp[i]+256, inf);
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j <= 2*k; j++)
            rc[j] = f.count_greater(p[i-k+j]);

        for (int x : s) {
            if (dp[i][rs[x]] == inf)
                continue;

            int t = 0;
            for (int j = 0; j < 2*k; j++)
                if (x&(1<<j) && i-k+j >= 0)
                    w[t++] = p[i-k+j];

            for (int j = 0; j <= 2*k; j++) {
                // 1. new slot must be empty
                // 2. after filling the new slot, the first slot should be filled
                // 3. distance between prev max slot and this slot is <= k
                if (!(x&(1<<j)) && i-k+j < n && rs[(x|(1<<j))>>1] != -1) {
                    int c = rc[j];
                    for (int l = 0; l < t; l++)
                        if (w[l] > p[i-k+j]) c++;
                    // debug(i, i-k+j, c, x, (x|(1<<j))>>1);
                    cmin(dp[i+1][rs[(x|(1<<j))>>1]], dp[i][rs[x]] + c);
                }
            }
        }

        if (i >= k) f.insert(p[i-k]);
    }

    cout << dp[n][0] << "\n";
}