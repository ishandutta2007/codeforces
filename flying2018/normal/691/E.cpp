#include<iostream>
#include<cstdio>
#include<cstring>
#define N 110
#define ll long long
#define mod 1000000007
using namespace std;
int n;
struct matrix{
    int a[N][N];
    matrix(int c=0,int n=0){memset(a,0,sizeof(a));for(int i=1;i<=n;i++) a[i][i]=c;}
    int* operator [](int b){return a[b];}
    friend matrix operator *(matrix a,matrix b)
    {
        matrix c;
        for(int i=1;i<=n;i++)
            for(int k=1;k<=n;k++)
                for(int j=1;j<=n;j++)
                c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%mod;
        return c;
    }
}o;
matrix operator ^(matrix a,ll b)
{
    matrix r(1,n);
    for(;b;b>>=1)
    {
        if(b&1) r=r*a;
        a=a*a;
    }
    return r;
}
ll a[N];
int main()
{
    ll m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(__builtin_popcountll(a[i]^a[j])%3==0) o[i][j]++;
    o=o^(m-1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) ans=(ans+o[i][j])%mod;
    printf("%d\n",ans);
    return 0;
}