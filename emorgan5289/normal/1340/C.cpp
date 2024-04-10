#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1000005, maxm = 10005;
int dfast[maxm];
vector<int> adj[maxn];

// call randint() for a random integer, good for hashing
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

int cost[maxm][1001] = {};
bool visited[maxm][1001] = {};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int> d(m); for (auto& x : d) cin >> x;

    // n = 1000000;
    // for (int i = 0; i < 10000; i++) d.pb(uniform_randint(0, n-1));

    sort(all(d)); d.erase(unique(all(d)), d.end());
    m = d.size();
    ll g, r; cin >> g >> r;
    for (int i = 0; i < m; i++) dfast[i] = d[i];

    for (int i = 0; i < m; i++)
        for (int k = 0; k < g; k++)
            cost[i][k] = inf;

    deque<pair<int, int>> q = {{0, 0}};
    cost[0][0] = 0;
    ll out = inf_ll;

    while (!q.empty()) {
        ll i, k; tie(i, k) = q.back(); q.pop_back();
        visited[i][k] = 1;
        debug(i, k, cost[i][k]);
        if (n-dfast[i] <= g-k) {
            out = min(out, (r+g)*cost[i][k]+k+n-dfast[i]);
        }

        if (i != 0 && dfast[i]-dfast[i-1] <= g-k) {
            int nk = k+dfast[i]-dfast[i-1];
            if (nk == g) {
                if (!visited[i-1][0]) {
                    visited[i-1][0] = 1;
                    cost[i-1][0] = cost[i][k]+1;
                    q.push_front({i-1, 0});
                }
            } else {
                if (!visited[i-1][nk]) {
                    visited[i-1][nk] = 1;
                    cost[i-1][nk] = cost[i][k];
                    q.push_back({i-1, nk});
                }
            }
        }
        if (i != m-1 && dfast[i+1]-dfast[i] <= g-k) {
            int nk = k+dfast[i+1]-dfast[i];
            if (nk == g) {
                if (!visited[i+1][0]) {
                    visited[i+1][0] = 1;
                    cost[i+1][0] = cost[i][k]+1;
                    q.push_front({i+1, 0});
                }
            } else {
                if (!visited[i+1][nk]) {
                    visited[i+1][nk] = 1;
                    cost[i+1][nk] = cost[i][k];
                    q.push_back({i+1, nk});
                }
            }
        }
    }
    
    if (out >= inf_ll)
        cout << -1 << "\n";
    else
        cout << out << "\n";
}