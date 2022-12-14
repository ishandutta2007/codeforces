#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 25
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],rk[MN+5],b[MN+5];
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    for(int i=1;i<=n;++i) b[rk[i]]=a[rk[i%n+1]];
    for(int i=1;i<=n;++i) printf("%d ",b[i]);
    return 0;
}