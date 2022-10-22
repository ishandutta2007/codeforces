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

int a[maxn];

bool check(int st, int n)
{
    for (int i = 0; i < n; i++) {
        if (abs(st + i - a[i]) > 1) return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (check(a[0] - 1, n) || check(a[0], n) || check(a[0] + 1, n)) cout << "YES" << endl;
    else cout << "NO" << endl;
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