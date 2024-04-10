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
const int maxn = 300005;
ll jc[maxn], bjc[maxn];
ll c(int a, int b) {
    if (a < b || b < 0) return 0;
    return jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
ll mat[maxn];
ll mt1[maxn];
int main() {    
    jc[0] =  1;
    for (int i = 1; i < maxn; i++)
        jc[i] = jc[i - 1] * i % mod;
    for (int i = 0; i < maxn; i++)
        bjc[i] = ksm(jc[i], mod - 2);
    mat[0] = 1;
    mt1[0] = 1;
    for (int i = 1; i < maxn; i++) {
        mat[i] = mat[i - 1];
        mt1[i] = 0;
        if (i >= 2) {
            mat[i] += (i - 1) * mat[i - 2], 
            mat[i] %= mod;
            mt1[i] += (i - 1) * 2 * mt1[i - 2],
            mt1[i] %= mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%d", &n);
        ll tot = 0;
        for (int j = 0; j * 2 <= n; j += 2) {
            ll ans = c(n - j, j) * mt1[j] % mod * mat[n - 2 * j] % mod;
            tot = (tot + ans) % mod;
        }
        printf("%lld\n", tot);
    }
    return 0;
}