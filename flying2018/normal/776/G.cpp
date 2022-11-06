#include<iostream>
#include<cstdio>
#include<cstring>
#define N 17
#define ll long long
using namespace std;
ll f[N][2][2][2];
int num[N],lim;
ll dfs(int u,int s,int p0,int p1)//p0:pre_0,p1:same
{
	if(u<0) return s;
	if(f[u][s][p0][p1]>=0) return f[u][s][p0][p1];
	int m=min(p1?num[u]:15,lim);
    ll ans=0;
    for(int i=0;i<=m;i++)
    {
        if((u<<2)==((lim>>2)<<2) && !(i>>(lim%4)&1))continue;
        ans+=dfs(u-1,((!p0 || i!=0) && i==lim)?1:s,p0 && i==0,p1 && i==num[u]);
    }
    return f[u][s][p0][p1]=ans;
}
ll work(ll x)
{
    if(x<=0)return 0;
    int cnt=0;
    while(x) num[cnt++]=x&15,x>>=4;
    ll ans=0;
    for(lim=4;lim<=min(15,cnt*4-1);lim++)
    {
    	memset(f,-1,sizeof(f));
    	ans+=dfs(cnt-1,0,1,1);
	}
    return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll l,r;
		scanf("%llx%llx",&l,&r);
		printf("%lld\n",work(r)-work(l-1));
	}
	return 0;
}