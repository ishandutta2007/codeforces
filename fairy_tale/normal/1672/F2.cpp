#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 998244353;
const int maxn = 2e5 + 5;

int a[maxn], b[maxn], d[maxn];
vector<int> f[maxn];

void solve()
{
    int n, u = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) f[i].clear();
    for (int i = 1; i <= n; i++) d[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        f[b[i]].push_back(a[i]);
        d[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] > d[u]) u = i;
    }

    // ,DAG
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (auto v:f[u]) {
            if (--d[v] == 0) q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] > 0) {
            cout << "WA" << endl;
            return;
        }
    }

    cout << "AC" << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}