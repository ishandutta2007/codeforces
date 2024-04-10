#include <bits/stdc++.h>

using namespace std;

// using mint = long double;
// using mint = modint998244353;
// using mint = modint1000000007;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> T;
typedef pair<ll, vector<ll>> Pd;

const ll INF = 1e18;
const ll fact_table = 3200008;

priority_queue<ll> pql;
priority_queue<P> pqp;
// big priority queue
priority_queue<ll, vector<ll>, greater<ll>> pqls;
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

// const ll mod = 998244353ll;
const ll mod = 1000000007ll;

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

ll n, m, k;
ll h[505][505], w[505][505];
ll cost[20][505][505];

bool solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            cin >> h[i][j];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> w[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pe(-1);
            }
            el;
        }
        return true;
    }

    ll dist = k / 2;

    priority_queue<T, vector<T>, greater<T>> q;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            q.push(T(0, P(0, 1000 * i + j)));
        }
    }

    for (int i = 1; i <= dist; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cost[i][j][k] = INF;
            }
        }
    }

    while (q.size()) {
        T top_element = q.top();
        ll nowcost = top_element.first;
        ll walk = top_element.second.first;
        ll place = top_element.second.second;
        q.pop();

        int x = place / 1000, y = place % 1000;
        if (nowcost > cost[walk][x][y]) continue;

        if (walk == dist) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            int newwalk = walk + 1;
            ll newcost;
            if (i == 0) {
                newcost = w[x][y];
            } else if (i == 1) {
                newcost = h[x][y];
            } else if (i == 2) {
                newcost = w[x - 1][y];
            } else {
                newcost = h[x][y - 1];
            }

            newcost += nowcost;
            if (cost[newwalk][nx][ny] > newcost) {
                cost[newwalk][nx][ny] = newcost;
                q.push(T(newcost, P(newwalk, 1000 * nx + ny)));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cost[dist][i][j] >= INF) {
                pe(-1);
            } else {
                ll ans = cost[dist][i][j] * 2ll;
                pe(ans);
            }
        }
        el;
    }

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
        // cout << "Case #" << testcase << ": ";
        solve();
        testcase++;
    }

    // solve();
    return 0;
}