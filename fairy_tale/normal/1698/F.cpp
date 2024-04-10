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

const int maxn = 2e5 + 5;
const int mod = 998244353;

int a[555], b[555];
P fa[555], fb[555];

void work(int l, int r)
{
    while (l < r) {
        swap(a[l], a[r]);
        l++, r--;
    }
}

void solve()
{
    int n, fg;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i < n; i++) fa[i] = P(min(a[i], a[i + 1]), max(a[i], a[i + 1]));
    for (int i = 1; i < n; i++) fb[i] = P(min(b[i], b[i + 1]), max(b[i], b[i + 1]));

    sort(fa + 1, fa + n);
    sort(fb + 1, fb + n);
    fg = (a[1] == b[1]) & (a[n] == b[n]);
    for (int i = 1; i < n; i++) fg &= (fa[i] == fb[i]);
    if (!fg) {
        cout << "NO" << endl;
        return;
    }

    vector<P> ans;
    for (int i = 2; i < n; i++) {
        if (a[i] == b[i]) continue;
        int mask = 0;
        for (int j = i; j < n; j++) {
            if (a[j] == b[i] && a[j + 1] == b[i - 1]) {
                ans.push_back(P(i - 1, j + 1));
                work(i - 1, j + 1);
                mask = 2;
                break;
            }
        }

        if (mask == 2) continue;

        for (int j = i; j < n; j++) {
            if (a[j] == b[i - 1] && a[j + 1] == b[i]) {
                for (int l = i; l <= j; l++) {
                    for (int r = j + 1; r <= n; r++) {
                        if (a[l] == a[r]) {
                            ans.push_back(P(l, r));
                            work(l, r);
                            mask = 1;
                            i--;
                            break;
                        }
                    }
                    if (mask) break;
                }
                if (mask) break;
            }
        }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto e:ans) cout << e.fi << " " << e.se << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
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