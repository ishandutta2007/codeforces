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

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    int w = 0;
    for (auto e:s) w += e - 'a' + 1;
    if (n & 1){
        int d = min(s[0], s[n - 1]) - 'a' + 1;
        w -= d;
        if (w > d) cout << "Alice " << w - d << endl;
        else cout << "Bob " << d - w << endl;
    } else cout << "Alice " << w << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Pt = 1;
    cin >> Pt;
    while (Pt--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}