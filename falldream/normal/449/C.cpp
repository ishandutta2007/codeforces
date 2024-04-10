#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],r[MN+5],vis[MN+5],B[MN+5],b[MN+5],ans=0,q[MN+5],top,v[MN+5],num=0;
int main()
{
    n=read();
    for(int i=2;i<=n>>1;++i) if(!B[i])
    {
        top=0;
        for(int j=i;j<=n;j+=i)
            if(B[j]=1,!vis[j]) q[++top]=j;
        if(i==2) continue;if(top&1) q[2]=i;
        for(int i=1+(top&1);i<=top;i+=2) a[++ans]=q[i],b[ans]=q[i+1],vis[q[i]]=vis[q[i+1]]=1;
    }
    for(int i=2;i<=n;++i) if(!vis[i]&&(i%2==0)) v[++num]=i;
    printf("%d\n",ans+num/2);
    for(int i=1;i<=ans;++i) printf("%d %d\n",a[i],b[i]);
    for(int i=2;i<=num;i+=2) printf("%d %d\n",v[i-1],v[i]);
    return 0;
}