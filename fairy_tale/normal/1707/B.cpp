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
typedef pair<LL, LL> PL;

const int maxn = 1e5 + 5;
const int mod = 998244353;

int a[maxn];
map<int, int> p, q;

void solve()
{
    int n, u;
    cin >> n;

    p.clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) p[a[i + 1] - a[i]]++;
    for (int i = 2; i < n; i++) {
        q.clear();
        u = -1;
        for (auto e:p) {
            //cout << e.fi << " == " << e.se << endl;
            if (e.se > 1) q[0] += e.se - 1;
            if (u != -1) q[e.fi - u]++;
            u = e.fi;
        }
        swap(p, q);
    }

    for (auto e:p) cout << e.fi << endl;
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