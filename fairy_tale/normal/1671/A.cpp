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
const int maxn = 1e5 + 5;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int pre = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) pre++;
        else {
            if (pre == 1) {
                cout << "NO" << endl;
                return;
            }
            pre = 1;
        }
    }

    if (pre == 1) cout << "NO" << endl;
    else cout << "YES" << endl;
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