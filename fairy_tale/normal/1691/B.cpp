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
const int mod = 1e9 + 7;

int a[maxn];
void solve()
{
    int n;
    cin >> n;
    map<int, int> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        q[a[i]]++;
    }

    for (auto e:q) {
        if (e.se == 1) {
            cout << -1 << endl;
            return;
        }
    }

    int pre = 0;
    for (auto e:q) {
        cout << pre + e.se << " ";
        for (int j = pre + 1; j < pre + e.se; j++) cout << j << " ";
        pre += e.se;
    }
    cout << endl;
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