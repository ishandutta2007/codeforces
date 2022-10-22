#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;

int h[maxn];

void init()
{

}

LL work(int n, int limit)
{
    LL a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        int c = limit - h[i];
        a += c / 2;
        if (c & 1) b++;
    }

    LL t = 0;
    if (b > 0) {
        t = b + b - 1;
        a -= b - 1;
        a = max(a, 0LL);
        t += a / 3 * 4;
        a %= 3;
        if (a == 1) t += 1;
        else if (a == 2) t += 3;
    } else {
        t += a / 3 * 4;
        a %= 3;
        if (a == 1) t += 2;
        else if (a == 2) t += 3;
    }
    return t;
}

void solve()
{
    int n, m = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        m = max(m, h[i]);
    }

    cout << min(work(n, m), work(n, m + 1)) << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}