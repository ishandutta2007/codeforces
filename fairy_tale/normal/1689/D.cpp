#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

string s[1005];
P check(int n, int m, int ux, int uy) {
    int best = mod;
    P ans = P(ux, uy);
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            int x = a + ux, y = b + uy;
            int vv = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (s[i][j - 1] == 'B') {
                        vv = max(vv, abs(i - x) + abs(j - y));
                    }
                }
            }

            if (vv < best) {
                best = vv;
                ans = P(x, y);
            }
        }
    }
    return ans;
}

void solve()
{
    int n, m;

    vector<int> fx, fy;
    auto add = [&](int x, int y) {
        fx.push_back(x + y);
        fy.push_back(x - y);
    };
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') add(i, j + 1);
        }
    }

    sort(fx.begin(), fx.end());
    sort(fy.begin(), fy.end());
    int dx = fx[0] + fx.back();
    int dy = fy[0] + fy.back();
    P ans = check(n, m, (dx + dy + 2) / 4, (dx - dy + 2) / 4);
    cout << ans.fi << " " << ans.se << endl;
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