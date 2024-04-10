#include <bits/stdc++.h>
#include <numeric>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 4e18;
const ll fact_table = 1200008;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
// priority_queue <ll, vector<ll>, greater<ll> > pqls;
priority_queue<P, vector<P>, greater<P>> pqps;
// small priority queue
// top pop

ll dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
ll dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};
//,,,

/*
#define endl "\n"
#ifdef ENJAPMA
#undef endl
#endif
*/

#define p(x) cout << x << endl;
#define el cout << endl;
#define pe(x) cout << x << " ";
#define ps(x) cout << fixed << setprecision(25) << x << endl;
#define pu(x) cout << (x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pc(x) cout << x << ",";
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = a; i <= (b); i++)
#define rep3(i, a, b) for (ll i = a; i >= (b); i--)
#define all(c) begin(c), end(c)

typedef vector<ll> vec;
typedef vector<vector<ll>> mat;

// vec v(n) -> n
// mat dp(h, vec(w)) -> h * w 

const ll mod = 998244353ll;
// const ll mod = 1000000007ll;

ll mypow(ll a, ll b, ll m = mod) {
    ll x = 1;
    while (b) {
        while (!(b & 1)) {
            (a *= a) %= m;
            b >>= 1;
        }
        (x *= a) %= m;
        b--;
    }
    return x;
}
vec rv(ll read) {
    vec res(read);
    for (int i = 0; i < read; i++) {
        cin >> res[i];
    }
    return res;
}

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
    return (((fact[n] * rfact[r]) % mod) * rfact[n - r]) % mod;
}
*/
bool icpc = false;
bool multicase = false;

ll n, k;
ll a[100005], b[100005];

ll parent[500005], sizes[500005];

void init(ll n) {
    for (ll i = 0; i <= n; i++) {
        parent[i] = i;
    }
}
ll find(ll x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = find(parent[x]);
    }
}

void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sizes[x] < sizes[y]) swap(x, y);

    parent[y] = x;
    sizes[x] += sizes[y];
}

bool same(ll x, ll y) {
    return find(x) == find(y);
}

ll size(ll x) {
    return sizes[find(x)];
}

bool solve() {
    cin >> n;
    init(2 * n + 10);
    multiset<P> st;
    ll sum = 0;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        a[i] = x + y, b[i] = x;
        sum += x;
        st.insert(P(a[i], i * 2));
        st.insert(P(b[i], i * 2 + 1));
    }

    set<P> aid, bid;
    ll ans = 0;

    ll cnt = 0;

    while (true) {
        cnt++;
        if (st.size() == 0) break;
        auto [value, info] = *st.begin();
        st.erase(st.begin());

        int id = info / 2;
        int group = info % 2;
        bool match = false;

        if (group == 0) {
            // A 
            for (auto [value, nid] : bid) {
                if (!same(id, nid) || cnt == 2 * n) {
                    // 
                    bid.erase(P(value, nid));
                    ans += max(a[id], b[nid]);
                    unite(id, nid);
                    match = true;
                    break;
                }
            }
        } else {
            for (auto [value, nid] : aid) {
                if (!same(id, nid) || cnt == 2 * n) {
                    aid.erase(P(value, nid));
                    ans += max(b[id], a[nid]);
                    unite(id, nid);
                    match = true;
                    break;
                }
            }
        }
        if (!match) {
            if (group == 0) {
                aid.insert(P(a[id], id));
            } else {
                bid.insert(P(b[id], id));
            }
        }
    }

    ans -= sum;
    p(ans);

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (icpc) {
        while (solve())
            ;
        return 0;
    }
    ll q, testcase = 1;
    if (multicase) {
        cin >> q;
    } else {
        q = 1;
    }
    while (q--) {
        solve();
        testcase++;
    }

    // solve();
    return 0;
}