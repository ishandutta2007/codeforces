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
    int n, m;

    cin >> n;
    m = 2 * n - 1;
    m = (m + 2) / 3;
    cout << m << endl;

    if (m & 1) {
        int d = m / 2;
        cout << "1 1" << endl;
        for (int i = 1; i <= d; i++) cout << 1 + i << " " << 1 + i + i << endl;
        for (int i = 1; i <= d; i++) cout << d + 1 + i << " " << i * 2 << endl;
    } else {
        int d = m / 2 - 1;
        cout << "1 1" << endl;
        cout << "2 2" << endl;
        for (int i = 1; i <= d; i++) cout << 2 + i << " " << 2 + i + i << endl;
        for (int i = 1; i <= d; i++) cout << d + 2 + i << " " << i * 2 + 1 << endl;
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