#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define y1 zyy_ak_in_one_morning
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll n,m,a[300001],f[700001];
inline void add(ll x,ll v){for(;x<=n;x+=x&-x)	f[x]+=v;}
inline ll ask(ll x){ll sum=0;for(;x;x-=x&-x)	sum+=f[x];return sum;}
struct orz
{
	ll x,y;
	int to,kind,v;
	orz(){}
	orz(ll x,ll y,ll to,ll kind,ll v):x(x),y(y),to(to),kind(kind),v(v){}
}que[1000001];
inline bool cmp(orz lbc,orz zyy){return lbc.x<zyy.x;}
ll x1,y1,x2,y2,tot,cnt[300001][5],ans[300001];
inline ll get(ll x){return x*(x-1)/2;}
int main()
{
	n=read();m=read();
	For(i,1,n)	a[i]=read();
	For(i,1,m)
	{
		x1=read();y1=read();x2=read();y2=read();
		que[++tot]=orz(x1-1,y1-1,i,1,1);	
		que[++tot]=orz(x2,y1-1,i,2,-1);
		que[++tot]=orz(x1-1,y2,i,3,-1);
		que[++tot]=orz(x2,y2,i,4,1);
		cnt[i][2]=y1-1;cnt[i][3]=x1-1;
		cnt[i][4]=n-x2-y2;
		ans[i]=n*(n-1)/2;
		ans[i]-=get(x1-1)+get(y1-1)+get(n-x2)+get(n-y2);
	}
	ll tep=1;
	sort(que+1,que+tot+1,cmp);
	while(tep<=tot&&que[tep].x<=0)	
	{
		ans[que[tep].to]+=get( ask(que[tep].y)*que[tep].v+cnt[que[tep].to][que[tep].kind] );
		tep++;
	}
	For(i,1,n)
	{
		add(a[i],1);
		while(tep<=tot&&que[tep].x<=i)	
		{
			ans[que[tep].to]+=get( ask(que[tep].y)*que[tep].v+cnt[que[tep].to][que[tep].kind] );
			tep++;
		}
	}
	For(i,1,m)
		printf("%I64d\n",ans[i]);
}