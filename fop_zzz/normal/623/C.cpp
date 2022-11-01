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
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
struct node{ll v;int num;}	zx[200001],zy[200001],fy[200001],fx[200001];
struct poi{ll x,y;}	p[200001];
ll lmi[200001],rmi[200001],lmx[200001],rmx[200001];
inline bool cmp1(poi x,poi y){return x.x<y.x;}
int n,t1,t2,t3,t4;
inline ll sqr(ll x){return x*x;}
inline bool cmp(node x,node y){return x.v<y.v;}
ll ans=1e18;
inline bool check(ll mx)
{
	ll R=1;
	For(L,1,n)
	{
		if(p[L].x>0)	break;
		while(R<n&&sqr(p[R+1].x-p[L].x)<=mx&&abs(p[R+1].x)<=abs(p[L].x))	R++;
		while(abs(p[R].x)>abs(p[L].x))	R--;
		ll m_x=max(lmx[L-1],rmx[R+1]);
		ll m_i=min(lmi[L-1],rmi[R+1]);
//		cout<<L<<' '<<R<<' '<<m_i<<' '<<m_x<<endl
		if(sqr(m_x-m_i)<=mx&&(sqr(max(abs(p[L].x),abs(p[R].x)))+sqr(max(abs(m_x),abs(m_i))))<=mx)	return 1;
	}
	ll L=n;
	Dow(R,1,n)
	{
		if(p[R].x<0)	break;
		while(L>1&&sqr(p[R].x-p[L-1].x)<=mx&&abs(p[L-1].x)<=abs(p[R].x))	L--;
		while(abs(p[L].x)>abs(p[R].x))	L++;
		ll m_x=max(lmx[L-1],rmx[R+1]);
		ll m_i=min(lmi[L-1],rmi[R+1]);	
//		cout<<L<<' '<<R<<' '<<m_i<<' '<<m_x<<' '<<lmx[L-1]<<' '<<rmx[R+1]<<endl;
		if(sqr(m_x-m_i)<=mx&&(sqr(max(abs(p[R].x),abs(p[L].x)))+sqr(max(abs(m_x),abs(m_i))))<=mx)	return 1;
	}
	return 0;
}
ll mix=1e9,mxx=-1e9,miy=1e9,mxy=-1e9;
int main()
{
	n=read();
	For(i,1,n)
	{
		ll x=read(),y=read();
		zx[++t1].v=x,zx[t1].num=i;
		zy[++t2].v=y,zy[t2].num=i;
		p[i].x=x;p[i].y=y;
		mix=min(mix,x);mxx=max(mxx,x);
		miy=min(miy,y);mxy=max(mxy,y);
	}
	ans=min(sqr(mix-mxx),sqr(miy-mxy));
	sort(p+1,p+n+1,cmp1);
//	lmi[0]=1e9;lmx[0]=-1e9;
	For(i,1,n)	lmi[i]=min(lmi[i-1],p[i].y),lmx[i]=max(lmx[i-1],p[i].y);
//	rmi[n+1]=1e9;rmx[n+1]=-1e9;
	Dow(i,1,n)	rmi[i]=min(rmi[i+1],p[i].y),rmx[i]=max(rmx[i+1],p[i].y);
	ll l=0,r=ans;
	while(l<=r)
	{
		ll mid=l+r>>1;
		if(check(mid))	ans=mid,r=mid-1;else l=mid+1;
	}
	printf("%I64d\n",ans);
}