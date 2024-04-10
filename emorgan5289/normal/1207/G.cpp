#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

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
        bool leaf; // indicates if one of the words in the dictionary ends here
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
        } a[v].leaf = 1;
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

const int N = 4e5+5;
int e[N], ind[N], ans[N];
vector<int> grp[N];
vector<pair<char, int>> adj[N];
vector<int> adj2[N];
ahocorasick a;
fenwick_multiset<N> f;
int vin[N], vout[N], tt = 0;

void dfs2(int i) {
    vin[i] = tt++;
    for (auto& j : adj2[i]) dfs2(j);
    vout[i] = tt;
}

void dfs(int i, int x) {
    f.insert(vin[x]);
    for (auto& [c, j] : adj[i])
        dfs(j, a.push(x, c));
    for (auto& j : grp[i])
        ans[j] = f.index(vout[e[j]])-f.index(vin[e[j]]);
    f.remove(vin[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        if (t == 1) {
            char c; cin >> c;
            adj[0].pb({c, i});
        } else {
            int j; cin >> j;
            char c; cin >> c;
            adj[j].pb({c, i});
        }
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> ind[i] >> s;
        grp[ind[i]].pb(i);
        e[i] = a.insert(s);
    }
    for (int i = 1; i < a.a.size(); i++)
        adj2[a.link(i)].pb(i);
    dfs2(0);
    dfs(0, 0);
    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}