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

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

map<int, int> q;

void solve()
{
    int n;
    cin >> n;
    q.clear();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q[x]++;
    }

    int m = 0;
    for (auto e:q) m = max(m, e.se);
    int t = m, k = 0;
    while (t < n) {
        k++;
        if (t * 2 >= n) k += n - t;
        else k += t;
        t *= 2;
    }

    cout << k << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}