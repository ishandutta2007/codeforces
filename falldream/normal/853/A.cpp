#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define MN 600000
#define pa pair<int,int>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,t[MN+5],K,Ans[MN+5];long long ans=0;
priority_queue<pa>q;
int main()
{
    n=read();K=read();
    for(int i=1;i<=n;++i) t[i]=read();
    for(int i=1;i<=K;++i) q.push(make_pair(t[i],i));
    for(int i=K+1;i<=K+n;++i)
    {
        if(i<=n) q.push(make_pair(t[i],i));
        int x=q.top().second;Ans[x]=i;q.pop();
        ans+=1LL*(i-x)*t[x];
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;++i)
    {
        printf("%d ",Ans[i]);
    }
    return 0;
}