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

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int mul(int x,int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x,int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

void solve()
{
    int n, m, mask = 0;
    string s;
    cin >> n;
    cin >> s;
    cin >> m;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        mask |= 1 << (c - 'a');
    }

    int pre = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int j = s[i] - 'a';
        if ((mask >> j) & 1) {
            ans = max(ans, i - pre);
            pre = i;
        }
    }
    cout << ans << endl;
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