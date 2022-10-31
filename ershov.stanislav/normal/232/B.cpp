#include <iostream>

using namespace std;
#define mod 1000000007
typedef long long ll;
ll c[111][101], d[101][10001], n, m, k;

ll exp(ll a, ll b) {
    ll x=1, y=a;
    while (b) {
        if (b&1) x*=y, x%=mod;
        y*=y, y%=mod, b/=2;
    } return x;
}

int main()
{
    c[0][0] = 1;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) { c[i][0] = 1; for (int j=1; j<=i; j++) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod; }
    for (int i=0; i<=n; i++) c[n+1][i] = exp(c[n][i], m/n), c[n+2][i] = c[n+1][i]*c[n][i]%mod;
    d[0][0]=1;
    for (int i=1; i<=n; i++) for (int j=0; j<=k; j++) for (int l=0; l<=n&&l<=j; l++) d[i][j]+=d[i-1][j-l]*c[n+(i>m%n?1:2)][l], d[i][j]%=mod;
    cout << d[n][k];
    return 0;
}