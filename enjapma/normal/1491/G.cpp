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

const ll INF = 2e18;
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
#define all(c) begin(c), end(c)

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

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

ll n;
ll a, b;

ll x[200005];
ll y[200005];
ll f[200005];
ll pos[200005];
ll invf[200005];
bool used[200005];

ll idx = 1;
ll ss = 0;

vector<P> calc(int a, int b, int pa, int pb) {
    vector<P> res;
    if (a == 1 && b == 1) {
        return res;
    }

        for (int i = pa; i < pb; i++) {
            res.pb(P(i, pb));
        }
        for (int i = pb + 1; i < pb + b; i++) {
            res.pb(P(pa, i));
        }
        res.pb(P(pa, pb));
    
    return res;
}

void dfs(int v, int id, int head) {
    used[v] = true;
    ss ++;

    if (used[x[v]]) {
        y[idx++] = head;
        invf[head] = v;
        f[v] = head;
        return;
    }

    y[idx++] = id;
    f[v] = id;
    invf[id] = v;
    dfs(x[v], id + 1, head);
}


bool solve() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pos[x[i]] = i;
    }

    int cycle = 0;
    int id = 2, head = 1;
    vec sizelist;

    for (int i = 1; i <= n; i++) {
        if (!used[x[i]]) {
            cycle ++;
            ss = 0;
            dfs(x[i], id, head);
            sizelist.pb(ss);
        }
        head = idx, id = idx + 1;
    }

    vector<P> poslist;
    if (cycle == 1) {
        if (n >= 3) {
            for (int i = 2; i <= n - 1; i++) {
                poslist.pb(P(1, i));
            }
            poslist.pb(P(2, n));
            poslist.pb(P(1, n));
            poslist.pb(P(1, 2));
        }
    } else {
        int accum = 1;
        for (int i = 0; i < sizelist.size(); i += 2) {
            if (i + 1 == sizelist.size()) break;
            int a = sizelist[i], b = sizelist[i + 1];
            int pa = accum, pb = accum + a;
            auto res = calc(a, b, pa, pb);

            for (auto ppp : res) {
                poslist.pb(ppp);
            }

            accum += a + b;
        }

        if (sizelist.size() % 2 == 0) {

        } else {
            int list = sizelist.back();
            if (list == 1) {

            } else if (list == 2) {
                poslist.pb(P(n - 2, n - 1));
                poslist.pb(P(n - 2, n));
                poslist.pb(P(n - 2, n - 1));
            } else {
                for (int i = 2; i <= list - 1; i++) {
                    poslist.pb(P(1 + accum - 1, i + accum - 1));
                }
                poslist.pb(P(2 + accum - 1, list + accum - 1));
                poslist.pb(P(1 + accum - 1, list + accum - 1));
                poslist.pb(P(1 + accum - 1, 2 + accum - 1));
            }
        }
    }

    vector<P> anslist;

    for (auto [l, r] : poslist) {
        int e1 = y[l], e2 = y[r];
        int t1 = invf[e1], t2 = invf[e2];
        int p1 = pos[t1], p2 = pos[t2];

        anslist.pb(P(p1, p2));
        swap(x[p1], x[p2]);
        x[p1] *= -1;
        x[p2] *= -1;

        swap(y[l], y[r]);
        swap(pos[t1], pos[t2]);
    }





    p(anslist.size());
    for (auto uuu : anslist) {
        pe(uuu.first); p(uuu.second);
    }

    assert(anslist.size() <= n + 1);


    for (int i = 1; i <= n; i++) {
        assert(x[i] == i);
    }


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