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

vector<int> g[maxn], f;

void solve()
{
    int n, fa;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> fa;
        g[fa].push_back(i);
    }

    f.clear();
    for (int i = 1; i <= n; i++) {
        f.push_back(g[i].size());
        g[i].clear();
    }
    f.push_back(1);
    sort(f.rbegin(), f.rend());
    int ans = 0;
    int m = n;
    for (int i = 0; i <= n; i++) {
        if (f[i] == 0) {
            m = i;
            break;
        }
    }

    int l = m, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;

        int s = 0;
        for (int i = 0; i < m; i++) {
            if (f[i] + i > mid) {
                s += f[i] + i - mid;
            }
        }
        if (s > mid - m) l = mid + 1;
        else r = mid;
    }

    cout << l << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}