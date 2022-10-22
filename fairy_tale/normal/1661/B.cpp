#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

vector<int> g[maxn];
int f[maxn], a[maxn];

void init()
{
    for (int i = 1; i < 32768; i++) {
        g[(i + 1) % 32768].push_back(i);
        g[(i * 2) % 32768].push_back(i);
    }

    queue<int> q;
    q.push(0);
    a[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto e:g[u]) {
            if (a[e]) continue;
            a[e] = 1;
            f[e] = f[u] + 1;
            q.push(e);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << f[n] << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}