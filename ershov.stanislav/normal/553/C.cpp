#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;
const int MOD = 1e9 + 7;

int n, m;

vector<pair<int, int> > graph[N];
bool used[N];
int cnt = 0;
int color[N];

bool flag = true;

void dfs(int v, int c) {
    if (used[v]) {
        if (color[v] != c) {
            flag = false;
        }
    } else {
        used[v] = true;
        color[v] = c;
        for (auto i : graph[v]) {
            dfs(i.fs, c ^ i.sc);
        }
    }
}

ll power(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        c ^= 1;
        graph[a].eb(b, c);
        graph[b].eb(a, c);
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i, 0);
            cnt++;
        }
    }
    if (!flag) {
        cout << 0 << endl;
    } else {
        cout << power(2, cnt - 1) << endl;
    }
    return 0;
}