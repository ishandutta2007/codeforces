#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int f[1<<22],from[1<<22],ch[1<<22],b[1<<22],num[1<<22],n,s[25],B[25][25],q[25],top=0;
inline void R(int&x,int y,int a,int b,int c)
{
    if(y<x) x=y,from[a]=b,ch[a]=c;
}
int main()
{
    n=read();int m=read();
    memset(f,40,sizeof(f));
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        s[x]|=1<<y-1;
        s[y]|=1<<x-1;
        B[x][y]=B[y][x]=1;
    }
    for(int i=1;i<1<<n;++i)
    {
        num[i]=num[i>>1]+(i&1);
        if(num[i]<=1) b[i]=1,f[i]=0;
        else
        {
            int mn=100,mx=0;
            for(int j=0;j<n;++j) if(i&(1<<j)) mn=min(mn,j),mx=max(mx,j);
            b[i]=b[i^(1<<mn)]&&b[i^(1<<mx)]&&B[mn+1][mx+1];
            if(b[i]) f[i]=0;
        }
        for(int j=1;j<=n;++j) if(i&(1<<j-1)) R(f[i|s[j]],f[i]+1,i|s[j],i,j);
    }
    printf("%d\n",f[(1<<n)-1]);
    for(int k=(1<<n)-1;f[k];k=from[k]) q[++top]=ch[k];
    for(;top;--top) printf("%d ",q[top]);
    return 0;
}