#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define int long long
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
const int mod=1e9+7;
struct Matrix
{
    int m[101][101];
} a,b;
Matrix operator *(Matrix a,Matrix b)
{
    Matrix c;
    forinc(i,0,100) forinc(j,0,100) c.m[i][j]=0;
    forinc(k,0,100) forinc(i,0,100) forinc(j,0,100)
    c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return c;
}
Matrix pw(Matrix a,int n)
{
    if(n==1) return a;
    Matrix tg=pw(a,n/2);
    tg=tg*tg;
    if(n%2) return tg*a;
    return tg;
}
main()
{
    //freopen("d.inp","r",stdin);
    int n,m;
    cin>>n>>m;
    if(n<m) return cout<<1,0;
    a.m[0][0]=1;
    a.m[0][m-1]=1;
    forinc(i,1,m-1) a.m[i][i-1]=1;
    b=pw(a,n);
    cout<<b.m[0][0];
}