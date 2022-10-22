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

int prev(int x, int n) {
    if (--x < 0) x += n;
    return x;
}

int nxt(int x, int n) {
    if (++x == n) x = 0;
    return x;
}

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    int ans = 0;
    if (n & 1) {
        int x = n / 2 + 1;
        while (x < n && s[x] == s[n / 2]) x++;
        ans = (x - n / 2) * 2 - 1;
    } else {
        int x = n / 2 + 1;
        while (x < n && s[x] == s[n / 2]) x++;
        ans = (x - n / 2) * 2;
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
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}