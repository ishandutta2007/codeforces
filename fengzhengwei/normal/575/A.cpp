#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll k,mod;
const int xx=5e4+5;
struct matrix
{
	ll a[2][2];
	matrix(){memset(a,0,sizeof(a));}
	matrix(ll x,ll y){memset(a,0,sizeof(a));a[1][0]=1,a[0][1]=x;a[1][1]=y;}
	matrix operator*(const matrix&w)const
	{
		matrix s;
		for(int i=0;i<2;i++)
		{
			for(int k=0;k<2;k++)
			{
				ll o=a[i][k];
				for(int j=0;j<2;j++)s.a[i][j]+=o*w.a[k][j]%mod,s.a[i][j]%=mod;
			}
		}
		return s;
	}
	void print()
	{
		puts("Matrix:");
		cout<<a[0][0]<<" "<<a[0][1]<<"\n";
		cout<<a[1][0]<<" "<<a[1][1]<<"\n";
		puts("");
	}
}sum[xx<<2],blk[xx],ans;
ll n,m,a[xx];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=matrix(a[l-1],a[l]);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]*sum[k<<1|1];
}
matrix get(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return sum[k];
	int mid=l+r>>1;
	if(y<=mid)return get(k<<1,l,mid,x,y);
	if(mid<x)return get(k<<1|1,mid+1,r,x,y);
	return get(k<<1,l,mid,x,y)*get(k<<1|1,mid+1,r,x,y);
}
struct nod{ll t,v;bool operator<(const nod&w)const{return t<w.t;};}e[xx];
map<ll,ll>mp;
ll get(ll x){if(mp.find(x)!=mp.end())return mp[x];return a[x%n];}
ll now;// 
void move()
{
	ans=ans*matrix(get(now-1),get(now));
	now++;
}
ll bel(ll x){return (x-1)/n+1;}
ll pos(ll x){return (x-1)%n+1;}
//i->i+1i 
void to(ll x)//x 
{
	if(now>x)return;
	if(x-now<=4){while(now!=x)move();return;}
	if(x>bel(now)*n)ans=ans*get(1,1,n,pos(now),n),now=bel(now)*n+1;//block 
	ll w=bel(x)-bel(now);
	if(w)
	{
		for(int j=log2(w)+1;j>=0;j--)
			if(w>>j&1)ans=ans*blk[j],now+=n*(1ll<<j);
	}
	//xnow 
	if(x-now<=4){while(now!=x)move();return;}
	ans=ans*get(1,1,n,pos(now),pos(x)-1),now=x;
	if(x-now<=4){while(now!=x)move();return;}
}
signed main(){//n 

//	freopen("a.in","r",stdin);
	k=read(),mod=read();
	n=read();
	if(!k)puts("0"),exit(0);
	if(mod==1)puts("0"),exit(0);
	for(int i=0;i<n;i++)a[i]=read()%mod;
	a[n]=a[0];
	build(1,1,n);
	blk[0]=get(1,1,n,1,n);
	for(int i=1;i<=70;i++)blk[i]=blk[i-1]*blk[i-1];
	m=read();
	for(int i=1;i<=m;i++)e[i].t=read(),e[i].v=read()%mod,mp[e[i].t]=e[i].v;
	sort(e+1,e+m+1);
	while(m&&e[m].t+1>k)m--;//t+1t+2 
//	for(int i=1;i<=m;i++)
//	{
//		if(e[i].t==32586886)cout<<i<<"\n";
//	}
	
	//32586886 6616
	now=1;
	ans.a[0][1]=1;
	for(int i=1;i<=m;i++)
	{
		if(now>=e[i].t+2)continue;
		to(e[i].t);
		if(e[i].t+2-now<=5){while(now!=min(e[i].t+2,k))move();continue;}
	}
	to(k);
//	cerr<<now<<"\n";
	cout<<ans.a[0][1]<<"\n";
	return 0;
}