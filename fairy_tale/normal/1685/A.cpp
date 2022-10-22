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

const int maxn = 1e5 + 5;
const int mod = 998244353;

int a[maxn], b[maxn];
void solve()
{
    int n, m;
    cin >> n;
    map<int, int> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q[a[i]]++;
    }

    if (n & 1) {
        cout << "NO" << endl;
        return;
    }

    int L = 0, R = n;
    for (auto e:q) {
        R -= e.se;
        if (e.se * 2 > n) {
            cout << "NO" << endl;
            return;
        }

        if (L == 0 || R == 0) {
            L += e.se;
            continue;
        }
        if (e.se + 2 > L + R) {
            cout << "NO" << endl;
            return;
        }
        L += e.se;
    }

    sort(a, a + n);
    m = n / 2;
    for (int i = 0; i < m; i++) b[i * 2] = a[i];
    for (int i = 0; i < m; i++) b[i * 2 + 1] = a[i + m];

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
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