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

const int N = 1e5+5;
fenwick_multiset<N> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;

        array<vector<int>, 26> v;

        for (int i = 0; i < n; i++) {
            f.insert(i);
            v[a[i]-'a'].pb(i);
        }
        for (int i = 0; i < 26; i++)
            reverse(all(v[i]));

        ll ans = inf_ll;
        ll r = 0;

        for (int i = 0; i < n; i++) {
            debug(i);
            // how much to move something lesser over?
            for (int j = 0; j < b[i]-'a'; j++) {
                if (!v[j].empty()) {
                    debug(j, v[j]);
                    cmin(ans, r+f.count_lower(v[j].back()));
                }
            }
            debug(i, ans);
            // greedily match
            if (v[b[i]-'a'].empty()) break;
            r += f.count_lower(v[b[i]-'a'].back());
            f.remove(v[b[i]-'a'].back());
            v[b[i]-'a'].pop_back();

            debug(i, r);
        }

        cout << (ans == inf_ll ? -1 : ans) << "\n";

        while (f.size() != 0) {
            debug(f.get(0));
            f.remove(f.get(0));
        }
    }
}