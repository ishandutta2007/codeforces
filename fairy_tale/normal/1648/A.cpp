
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

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> a[maxn], b[maxn];

LL solve(vector<int> &f)
{
    int n = f.size();
    if (n == 0) return 0;

    sort(f.begin(), f.end());
    LL s = 0;
    for (int i = 0; i < n; i++) {
        s += 1LL * f[i] * i - (n - i - 1LL) * f[i];
    }

    return s;
}

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &x);
            a[x].push_back(i);
            b[x].push_back(j);
        }
    }

    LL ans = 0;
    for (int i = 0; i < maxn; i++) ans += solve(a[i]);
    for (int i = 0; i < maxn; i++) ans += solve(b[i]);

    printf("%lld\n", ans);

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}