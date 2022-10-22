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

const int maxn = 5e5 + 5;
const int mod = 998244353;

int b[maxn], a[maxn];
vector<P> f[maxn];

void solve()
{
    int n, l, r;
    cin >> n;
    for (int i = 1; i <= n; i++) f[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] == 0) l = i + 1, r = n;
        else {
            r = i / b[i];
            l = i / (b[i] + 1) + 1;
        }
        f[r].push_back(P(l, i));
    }

    priority_queue<P> q;
    for (int i = n, j = n; i > 0; i--) {
        for (auto e:f[i]) q.push(e);
        while (j >= i && !q.empty()) {
            P u = q.top();
            q.pop();
            a[u.se] = j--;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
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
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}