#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 300000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],f[MN+5][102],ans=0,tot=0;
int main()
{
    n=read();
    for(int i=1;i<=n;++i) tot+=(a[i]=read());
    memset(f,200,sizeof(f));f[n+1][0]=0;
    for(int i=n;i;--i)
        for(int j=0;j<=100;++j)
        {
            int x=a[i]/1000,y=min(j,x);
            f[i][j-y]=max(f[i][j-y],f[i+1][j]+y);
            f[i][min(j+x*10,100)]=max(f[i][min(j+x*10,100)],f[i+1][j]);
        }
    for(int j=0;j<=100;++j) ans=max(ans,f[1][j]);
    printf("%d\n",tot-100*ans);
    return 0;
}