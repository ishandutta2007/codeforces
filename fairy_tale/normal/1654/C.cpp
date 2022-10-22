
#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int a[maxn];
multiset<LL> g;

bool dfs(LL x)
{
    auto e = g.find(x);
    if (e != g.end()) {
        g.erase(e);
        return true;
    }
    if (x == 1) return false;
    if (!dfs(x / 2)) return false;

    if (x & 1) return dfs(x / 2 + 1);
    else return dfs(x / 2);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    LL s = 0;
    for (int i = 0; i < n; i++) s += a[i];

    g.clear();
    for (int i = 0; i < n; i++) g.insert(a[i]);

    cout << (dfs(s) ? "YES" : "NO") << endl;
}



int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}