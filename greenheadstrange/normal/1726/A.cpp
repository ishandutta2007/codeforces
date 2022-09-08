#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 500005;
int a[maxn];
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int ans = -1e9;
        for (int i = 0; i < n; i++) 
            chkmax(ans, a[i] - a[(i + 1) % n]);
        int emx = 0;
        for (int i = 1; i < n; i++) chkmax(emx, a[i]);
        chkmax(ans, emx - a[0]);
        emx = a[0];
        for (int i = 0; i < n - 1; i++)
            chkmin(emx, a[i]);
        chkmax(ans, a[n - 1] - emx);
        printf("%d\n", ans);
    }
    return 0;
}