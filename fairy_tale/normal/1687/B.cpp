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
typedef pair<LL, int> PL;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int a[555], b[555];
void solve()
{
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < m; i++) b[i] = i;

    string s = "";
    for (int i = 0; i < m; i++) s += '0';
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        cout << "? " << s << endl;
        cout.flush();
        s[i] = '0';

        cin >> x;
        a[i] = x;
    }

    sort(b, b + m, [&](int u, int v) {
            return a[u] < a[v];
         });

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int j = b[i];
        s[j] = '1';
        cout << "? " << s << endl;
        cout.flush();

        cin >> x;
        if (x == ans + a[j]) ans = x;
        else s[j] = '0';
    }

    cout << "! " << ans << endl;
    cout.flush();
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}