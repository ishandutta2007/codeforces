#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const int N=1e3+5;
const ll MOD=1e9+7;
ll n,m,dp[N],ans;
matrix operator *(const  matrix &a, const matrix &b)
{
    int n=a.size();
    matrix c(n,vector<ll>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                (c[i][j]+=a[i][k]*b[k][j])%=MOD;
    return c;
}
matrix calc(matrix a,ll b)
{
    if(b==1)
        return a;
    ll m=b/2;
    matrix res=calc(a,m);
    if(b%2)
        return res*res*a;
    return res*res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<=m-1;i++) dp[i]=1;
    dp[m]=2;
    if(n<=m){
        cout<<dp[n];
        return 0;
    }
    matrix a(m+1,vector<ll>(m+1));
    for(int i=1;i<m+1;i++)
        a[i][i-1]=1;
    a[0][0]=1; a[0][m-1]=1;
    matrix r=calc(a,n-m);
    for(int i=0;i<m+1;i++)
        (ans+=r[0][i]*dp[m-i])%=MOD;
    cout<<ans;
    return 0;
}