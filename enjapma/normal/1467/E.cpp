#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll> > Pd;

const ll INF = 1e18;
const ll fact_table = 32008;

priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
// priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue <P, vector<P>, greater<P> > pqps;
//small priority queue
//top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i ++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {ll x = 1; while (b) {while (!(b & 1)) {(a *= a) %= m; b >>= 1;}(x *= a) %= m; b--;} return x;}
vec rv(ll read) { vec res(read); for (int i = 0; i < read; i++) { cin >> res[i]; } return res;}
void YES(bool cond) { if (cond) { p("YES");} else { p("NO");} return;}
void Yes(bool cond) { if (cond) { p("Yes");} else { p("No");} return;}
void line() { p("--------------------"); return;}

/*
ll fact[fact_table + 5], rfact[fact_table + 5];

void c3_init() {
    fact[0] = rfact[0] = 1;
    for (ll i = 1; i <= fact_table; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table], mod - 2, mod);
    for (ll i = fact_table; i >= 1; i--) {
        rfact[i - 1] = rfact[i] * i;
        rfact[i - 1] %= mod;
    }
    return;
}
ll c3(ll n, ll r) {
    return (((fact[n] * rfact[r]) % mod ) * rfact[n - r]) % mod;
}
*/

bool icpc = false;
bool multicase = false;

ll n, k, q;
ll x[200005];
ll c = 0;
ll from[200005], to[200005];
ll tin[200005], tout[200005], par[200005], euler[200005];
vec R[200005];
map<ll, vec> mp;
set<P> st;

// dp[i][j] := i  j 

template <class T> class ReRooting {
// : ReRooting<P> tree(n, P(0, 0));
private:
    int NodeCount = 0;
    int EdgeCount = 0;
    T Identity;
    // childSubtreeRes[v][i] := v  i  v 
    vector<vector<T>> childSubtreeRes;
    vector<T> resultList;
    vector<vector<int>> G;
    vector<vector<int>> Gi;
private:
    T merge(T l, T r, int v, int nv) {
        // 
        // max(l, r)
        return l + r;
    }
    T addNode(T value, int nodeId, int p) {
        // 
        // value + 1
        ll res = from[nodeId] - st.count(P(p, nodeId));
        return value + res;
    }
    void dfs1(int v, int p) {
        T result = Identity;
        int pidx = -1;
        for (int i = 0; i < (G[v]).size(); i++) {
            int nv = G[v][i];
            if (nv == p) {
                pidx = i;
                continue;
            }
            dfs1(nv, v);
            result = merge(result, childSubtreeRes[v][i], v, nv);
        }
        if (p != -1) childSubtreeRes[p][Gi[v][pidx]] = addNode(result, v, p);
        return;
    }
    void dfs2(int v, int p) {
        vector<T> fromTail = vector<T>(G[v].size(), Identity);
        for (int j = fromTail.size() - 1; j >= 1; j--) {
            fromTail[j - 1] = merge(childSubtreeRes[v][j], fromTail[j], v, G[v][j]);
        }
        T accum = Identity;
        for (int j = 0; j < fromTail.size(); j++) {
            T result = addNode(merge(accum, fromTail[j], v, G[v][j]), v, G[v][j]);
            childSubtreeRes[G[v][j]][Gi[v][j]] = result;
            accum = merge(accum, childSubtreeRes[v][j], v, G[v][j]);
        }
        resultList[v] = addNode(accum, v, -1);
        for (auto nv : G[v]) {
            if (nv == p) continue;
            dfs2(nv, v);
        }
    }
    void initialize() {
        rep(i, n) {
            childSubtreeRes[i].resize(G[i].size());
        }
    }
public:
    ReRooting(int n, T zero) {
        G.resize(n);
        Gi.resize(n);
        childSubtreeRes.resize(n);
        resultList.resize(n);
        Identity = zero;
        NodeCount = n;
    }
    void add_edge(int a, int b) {
        EdgeCount ++;
        assert(EdgeCount < NodeCount);
        assert(0 <= a && a < NodeCount);
        assert(0 <= b && b < NodeCount);
        Gi[a].pb(G[b].size());
        Gi[b].pb(G[a].size());
        G[a].pb(b);
        G[b].pb(a);
    }
    vector<T> result() {
        initialize();
        dfs1(0, -1);
        dfs2(0, -1);
        return resultList;
    }
    void debug() {
        line();
        for (int i = 0; i < n; i++) {
            for (auto e : childSubtreeRes[i]) {
                pe(e);
            }
            el;
        }
        line();
    }
};

void dfs(int v, int p = -1) {
    par[v] = p;
    tin[v] = c;
    euler[c++] = v;

    for (int i : R[v]) {
        if (i == p) continue;
        dfs(i, v);
        euler[c++] = v;
    }

    tout[v] = c - 1;
}

void check(int v, int p = -1) {
    int sum = 0;
    for (int nv : R[v]) {
        if (nv == p) continue;

        // auto ve = mp[x[v]];
        // sort(ve.begin(), ve.end());
        int count = lb(mp[x[v]].begin(), mp[x[v]].end(), tout[nv] + 1) - lb(mp[x[v]].begin(), mp[x[v]].end(), tin[nv]);

        // mp[x[v]]  tin[nv]  tout[nv] 
        sum += count;
        if (count > 0) {
            // v -> nv 
            from[v] ++;
            to[nv] ++;
            st.insert(P(v, nv));
        }
    }
    int r = mp[x[v]].size() - sum - 1;
    if (r > 0) {
        // v -> p 
        from[v] ++;
        to[p] ++;
        st.insert(P(v, p));
    }
    for (int nv : R[v]) {
        if (nv == p) continue;
        check(nv, v);
    }
    return;
}

bool solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ReRooting<int> tree(n, 0);

    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a --; b --;
        tree.add_edge(a, b);
        R[a].pb(b);
        R[b].pb(a);
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        mp[x[i]].pb(tin[i]);
    }

    for (auto e : mp) {
        vec u = e.second;
        sort(u.begin(), u.end());
        mp[e.first] = u;
    }


    check(0);

    auto res = tree.result();
    int ans = 0;
    int aim = st.size();

    for (int i = 0; i < n; i++) {
        if (res[i] == aim) ans ++;
    }

    p(ans);


    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (icpc) {
        while (solve());
        return 0;
    }
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }

// solve();
    return 0;
}