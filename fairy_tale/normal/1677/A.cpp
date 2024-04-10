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

struct BT {
    int f[5005], n;
    void init(int x) {
        memset(f, 0, sizeof(int) * (x + 1));
        n = x;
    }

    void add(int x) {
        for (int i = x; i <= n; i += i & (-i)) f[i]++;
    }

    int query(int x) {
        int w = 0;
        for (int i = x; i > 0; i -= i & (-i)) w += f[i];
        return w;
    }
};

BT dl, dr;
int a[5005];
void solve()
{
    int n;
    LL ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dl.init(n);
    for (int b = 2; b < n; b++) {
        dl.add(a[b - 1]);
        dr.init(n);
        for (int c = n - 1; c > b; c--) {
            dr.add(a[c + 1]);
            ans += dl.query(a[c]) * dr.query(a[b]);
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