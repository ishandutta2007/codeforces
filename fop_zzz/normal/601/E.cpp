#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define pb push_back
#define inf 1e9
#define maxn 500001
#define VI vector<ll>
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll tim,n,w,cnt[50001];
ll mo=1e9+7,p=1e7+19;
ll dp[30][2001];
struct node{ll w,v,s,e;}	wu[200001];
inline void get(ll l,ll r,ll dep,VI Q)
{
//	cout<<l<<' '<<r<<' '<<Q.size()<<endl;
	For(i,0,w)	dp[dep][i]=dp[dep-1][i];
	if(!Q.empty())
	For(i,0,Q.size()-1)
	{
		if(wu[Q[i]].s<=l&&r<=wu[Q[i]].e)
		{
			Dow(j,wu[Q[i]].w,w)
				dp[dep][j]=max(dp[dep][j],dp[dep][j-wu[Q[i]].w]+wu[Q[i]].v);		
		}
	}
	if(l==r)
	{
		if(!cnt[l])	return;
		ll ans=0;
//		For(i,1,w)	cout<<dp[dep][i]<<' ';cout<<endl<<endl;
		Dow(i,1,w)	ans=(ans*p+dp[dep][i])%mo;
		For(i,1,cnt[l])	printf("%I64d\n",ans);
		return;
	}
	VI L,R;
	ll mid=l+r>>1;
	if(!Q.empty())
	For(i,0,Q.size()-1)
	{
		if(wu[Q[i]].s<=l&&r<=wu[Q[i]].e)	continue;
		if(wu[Q[i]].s<=mid)	L.pb(Q[i]);
		if(wu[Q[i]].e> mid)	R.pb(Q[i]);
	}
	get(l,mid,dep+1,L);get(mid+1,r,dep+1,R);
}
int main()
{ 
	n=read();w=read();
	ll tim=1;
	For(i,1,n)
	{
		wu[i].v=read();wu[i].w=read();
		wu[i].s=1;
	}
	ll tot=n;
	int m=read();
	For(i,1,m)
	{
		ll	opt=read();
		if(opt==1)
		{
			tim++;
			wu[++tot].v=read();wu[tot].w=read();
			wu[tot].s=tim;
		}else
		if(opt==2)
		{
			wu[read()].e=tim;
			tim++;
		}else	cnt[tim]++;
	}
	VI Q;
	For(i,1,tot)
	{
		if(!wu[i].e)	wu[i].e=tim;
		Q.pb(i);
	}
	get(1,tim,1,Q);
}