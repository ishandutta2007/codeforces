#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif
 
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
 
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int base = 1e5;
const int B = 200;
 
int f[maxn * (B + 5)];
int a[maxn], ans;
PI b[maxn];
 
inline void add(int i, int k)
{
    if (b[k].fi != i) b[k] = PI(i, 1);
    else {
        b[k].se++;
        ans = max(ans, b[k].se);
    }
}
 
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    ans = 1;
    for (int i = 1; i <= n; i++) {
        int r = min(n - i, base / B);
        for (int j = 1; j <= r; j++) {
            int sub = a[i + j] - a[i];
            int k = sub / j;
            if (k * j == sub) {
                add(i, k + base);
            }
        }
    }
 
    ans++;
    int mm = B * n;
    for (int k = -B; k <= B; k++) {
        for (int i = 1; i <= n; i++) {
            int idx = a[i] - i * k + mm;
            f[idx]++;
            ans = max(ans, f[idx]);
        }
 
        for (int i = 1; i <= n; i++) {
            int idx = a[i] - i * k + mm;
            f[idx]--;
        }
    }
 
    cout << max(0, n - ans) << endl;
}
 
 
 
int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    t = 1;
    while(t--) {
        solve();
    }
 
    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}