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

int a[maxn];
void solve()
{
    int n;
    cin >> n;
    map<int, int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q[a[i]]++;
    }

    int a = 0, b = 0;
    for (auto e:q) {
        if (e.se > 1) b++;
        else a++;
    }

    cout << b + (a + 1) / 2 << endl;

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