#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
#define INF 2000000000
using namespace std;
inline int read()
{
    int  x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int mx1,mx2,mn1=INF,mn2=INF;
int n,m,ans=0;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int l=read();int r=read();
        mx1=max(mx1,l);mn1=min(mn1,r);
    }
    m=read();
    for(int i=1;i<=m;i++)
    {
        int l=read();int r=read();
        mx2=max(mx2,l);mn2=min(mn2,r);
    }
    ans=max(ans,max(mx1-mn2,mx2-mn1));
    cout<<ans;
    return 0;
}