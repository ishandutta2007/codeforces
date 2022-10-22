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

int a[maxn], b[maxn];

void solve()
{
    int n, q, l, r;
    string s;
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i] == '0') a[i + 1]++;
            else b[i + 1]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    // : 0011 + 1
    // : 001101
    // 00(11)00(11)     0011 
    while (q--) {
        cin >> l >> r;
        cout << max(a[r] - a[l], b[r] - b[l]) + 1 << endl;
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
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}