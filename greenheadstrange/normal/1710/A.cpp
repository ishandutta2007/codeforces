// Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int a[maxn];
int k;
int chk(int n, int m) {
    ll tot = 0, hvs = 0;
    for (int i = 1; i <= k; i++) {
        int cur = a[i] / n;
        if (cur < 2) continue;
        tot += cur;
        if (cur >= 3) hvs = 1;
    }
    if (tot < m) return 0;
    if ((tot - m) % 2)
        if (!hvs) return 0;
    return 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i++)
            scanf("%d", &a[i]);
        int ans = chk(n, m) | chk(m, n);
        if (ans) printf("Yes\n");
        else printf("No\n");
    }
    return (0-0); //<3
}