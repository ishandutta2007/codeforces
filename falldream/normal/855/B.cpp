#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long f[4][100005],n,p,q,r,a[100005];
int main()
{

    n=read();p=read();q=read();r=read();
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=0;i<=n;++i) f[1][i]=f[2][i]=f[3][i]=-5e18;
    for(int i=1;i<=n;++i) f[1][i]=max(f[1][i-1],f[0][i]+p*a[i]);
    for(int i=1;i<=n;++i) f[2][i]=max(f[2][i-1],f[1][i]+q*a[i]);
    for(int i=1;i<=n;++i) f[3][i]=max(f[3][i-1],f[2][i]+r*a[i]);
    printf("%lld\n",f[3][n]);
    return 0;
}