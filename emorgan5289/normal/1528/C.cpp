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
        T i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    T count(int x) const {
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

    // returns the smallest element of the set
    // which is > x, or N if no such element
    int next_greater(int x) {
        return get(index(x+1));
    }

    // returns the largest element of the set
    // which is < x, or -1 if no such element
    int next_lower(int x) {
        T i = index(x);
        return i == 0 ? -1 : get(i-1);
    }

    // returns the number of values in the set
    // in the semi-open interval [l, r)
    T count_interval(int l, int r) {
        return index(r)-index(l);
    }
};

const int N = 3e5+5;
fenwick_multiset<N> f, s;
vector<vector<int>> adja, adjb;
vector<int> vin, vout;
int tt, ans;

void dfs1(int i) {
    vin[i] = tt++;
    for (int j : adjb[i]) dfs1(j);
    vout[vin[i]] = tt;
}

void ins(int i) {
    debug("ins", i);
    if (f.count_interval(i, vout[i]))
        s.insert(i);
    else {
        f.insert(i);
        int j = f.next_lower(i);
        debug(j);
        if (j != -1 && f.count_interval(j, vout[j]) > 1)
            f.remove(j), s.insert(j);
    }
    debug(f.size());
    cmax(ans, f.size());
}

void rem(int i) {
    debug("rem", i);
    if (f.count(i)) {
        f.remove(i);
        int j = s.next_lower(i);
        if (j != -1 && !f.count_interval(j, vout[j]))
            s.remove(j), f.insert(j);
    } else s.remove(i);
}

void dfs2(int i) {
    ins(vin[i]);
    for (int j : adja[i]) dfs2(j);
    rem(vin[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        adja.assign(n, {});
        adjb.assign(n, {});
        vin.resize(n);
        vout.resize(n);
        ans = tt = 0;
        for (int i = 1; i < n; i++) {
            int x; cin >> x;
            adja[x-1].pb(i);
        }
        for (int i = 1; i < n; i++) {
            int x; cin >> x;
            adjb[x-1].pb(i);
        }
        dfs1(0);
        dfs2(0);
        cout << ans << "\n";
    }
}