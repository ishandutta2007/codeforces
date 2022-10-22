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

const int maxn = 1e5 + 5;
const int mod = 998244353;

void solve()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    int l = n, r = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            l = min(l, i);
            r = max(r, i);
        }
    }

    if (l == n) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    if (l == r) {
        if (n - 1 - r <= k) cout << 1 << endl;
        else if (l <= k) cout << 10 << endl;
        else cout << 11 << endl;
    } else {
        if (n - 1 - r <= k) {
            swap(s[r], s[n - 1]);
            k -= n - 1 - r;
        }
        if (l <= k) swap(s[0], s[l]);
        int ans = 0;
        for (int i = 0; i < n - 1; i++) ans += (s[i] - '0') * 10 + (s[i + 1] - '0');
        cout << ans << endl;
    }
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