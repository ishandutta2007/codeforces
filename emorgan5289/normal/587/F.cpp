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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct ahocorasick {

    struct node {
        int p; // the parent of this node in the transition graph
        int c; // the character by which p transitions to this node
        int link; // suffix link
        int exit; // exit link
        int leaf; // indicates how many words in the dictionary end here
        map<int, int> adj; // transitions of form {char, destination}
    };

    // state 0 = empty string

    int n = 1;
    vector<node> a;

    ahocorasick() : a({{0, 0, 0, -2, 0, {}}}) {}

    // adds a string to the dictionary of the automaton,
    // and returns the state corresponding to that string
    template<typename it>
    int insert(it first, it last) {
        int v = 0;
        for (it i = first; i != last; i++) {
            if (!a[v].adj.count(*i))
                a.push_back({v, *i, -1, -2, 0, {}}), a[v].adj[*i] = n++;
            v = a[v].adj[*i];
        } a[v].leaf++;
        return v;
    }

    int insert(string str) { return insert(str.begin(), str.end()); }

    // returns the state corresponding to the longest proper suffix
    // of x which is a prefix of one of the words in the dictionary.
    // runs in O(log(min(n, K))) time (amortized).
    int link(int x) {
        if (a[x].link != -1) return a[x].link;
        return a[x].link = a[x].p == 0 ? 0 : push(link(a[x].p), a[x].c);
    }

    // let x be the state corresponding to string s, then this returns
    // the state corresponding to the longest suffix of (s + character c)
    // which is a prefix of one of the words in the dictionary.
    // runs in O(log(min(n, K))) time (amortized).
    int push(int x, int c) {
        if (a[x].adj.count(c)) return a[x].adj[c];
        return a[x].adj[c] = x == 0 ? 0 : push(link(x), c);
    }

    // returns the state corresponding to the longest suffix
    // of x which is exactly equal to one of the words in the dictionary,
    // or -1 if no such suffix exists.
    // runs in O(log(min(n, K))) time (amortized).
    int exit(int x) {
        if (a[x].exit != -2) return a[x].exit;
        if (x == 0 && !a[x].leaf) return a[x].exit = -1;
        return a[x].exit = a[x].leaf ? x : exit(link(x));
    }

    // returns the state corresponding to the input string, runs in O(input).
    template<typename it>
    int find(it first, it last) {
        int x = 0;
        for (it i = first; i != last; i++)
            x = push(x, *i);
        return x;
    }

    int find(string str) { return find(str.begin(), str.end()); }

    // returns the string corresponding to state x, runs in O(output).
    string print(int x) {
        string str = "";
        while (x) str += a[x].c, x = a[x].p;
        reverse(str.begin(), str.end());
        return str;
    }
};

struct hld_single {

    vector<vector<int>> adj;
    vector<int> vin, vout, head, p, d, sz;
    vector<bool> hvy;
    int n, t = 0;

    void _assign(int i, int v) {
        if ((p[i] = v) != -1) d[i] = d[v]+1;
        for (int j : adj[i])
            if (j != v) _assign(j, i), sz[i] += sz[j];
        int b = -1;
        for (int j : adj[i])
            if (j != v && (b == -1 || sz[j] > sz[b])) b = j;
        if (b != -1) hvy[b] = 1;
    }

    void _dfs(int i) {
        vin[i] = t++;
        head[i] = hvy[i] ? head[p[i]] : i;
        for (int j : adj[i])
            if (j != p[i] && hvy[j]) _dfs(j);
        for (int j : adj[i])
            if (j != p[i] && !hvy[j]) _dfs(j);
        vout[i] = t-1;
    }

    hld_single(vector<vector<int>> _adj = {}, int root = 0) : adj(_adj), n(_adj.size()) {
        if (_adj.size() == 0) return;
        vin.resize(n), vout.resize(n), head.resize(n);
        p.assign(n, -1), d.assign(n, 0), sz.assign(n, 1), hvy.assign(n, 0);
        _assign(root, -1), _dfs(root);
    }

    // returns a single interval (inclusive of both ends) which
    // represents the subtree of vertex i.
    array<int, 2> subtree(int i) const {
        return {vin[i], vout[i]};
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to the root (inclusive of both).
    vector<array<int, 2>> path(int i) const {
        vector<array<int, 2>> out;
        for (; i != -1; i = p[head[i]])
            out.push_back({vin[head[i]], vin[i]});
        reverse(out.begin(), out.end());
        return out;
    }

    // returns a sorted list of disjoint intervals (inclusive of both ends).
    // the list has length O(logn) and the union of the intervals represents the
    // path from vertex i to vertex j (inclusive of both).
    vector<array<int, 2>> path(int i, int j) const {
        vector<array<int, 2>> tmp, out;
        for (; head[i] != head[j]; j = p[head[j]]) {
            if (d[head[i]] > d[head[j]]) swap(i, j);
            tmp.push_back({vin[head[j]], vin[j]});
        }
        if (d[i] > d[j]) swap(i, j);
        tmp.push_back({vin[i], vin[j]});
        sort(tmp.begin(), tmp.end());
        for (auto [l, r] : tmp) {
            if (!out.empty() && out.back()[1] == l-1)
                l = out.back()[0], out.pop_back();
            out.push_back({l, r});
        }
        return out;
    }
};

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
};


const ll N = 1e5+5;
ahocorasick a;
hld_single hld;
string s[N];
ll p[N], ans[N];
vector<int> adj_left[N], adj_right[N];
vector<array<ll, 3>> ev[N];
fenwick_multiset<N> light;
vector<fenwick_multiset<N>> heavy;
vector<ll> big;
ll bigans[N];

// add 1 on llerval [l, r] on right side
void upd(ll l, ll r) {
    light.insert(l);
    light.remove(r+1);
    for (ll i = 0; i < big.size(); i++)
        bigans[i] += heavy[i].index(r+1)-heavy[i].index(l);
}

// get the sum of the neighbors of i on left side
ll qry(ll i) {
    debug(i, big);
    ll out = 0;
    if (find(all(big), i) != big.end())
        return bigans[find(all(big), i)-big.begin()];
    else
        for (ll j : adj_left[i])
            out += light.index(j+1);
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> s[i];
        p[i] = a.insert(s[i]);
    }
    ll m = a.a.size();
    vector<vector<int>> adj_tree(m);
    for (ll i = 1; i < m; i++)
        adj_tree[a.link(i)].pb(i);
    hld = hld_single(adj_tree, 0);
    for (ll i = 0; i < n; i++) {
        ll x = 0;
        for (char c : s[i]) {
            x = a.push(x, c);
            adj_left[i].pb(hld.vin[x]);
            adj_right[hld.vin[x]].pb(i);
        }
        if (adj_left[i].size() > sqrt(N)) // change to sqrt(N)
            big.pb(i);
    }
    sort(all(big));
    heavy.resize(big.size());
    for (ll i = 0; i < big.size(); i++)
        for (ll j : adj_left[big[i]])
            heavy[i].insert(j);
    for (ll i = 0; i < q; i++) {
        ll l, r, k; cin >> l >> r >> k; l--, r--, k--;
        if (l > 0) ev[l-1].pb({i, k, -1});
        ev[r].pb({i, k, 1});
    }
    for (ll i = 0; i < n; i++) {
        upd(hld.vin[p[i]], hld.vout[p[i]]);
        for (auto [j, k, b] : ev[i])
            ans[j] += qry(k)*b;
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << "\n";
}