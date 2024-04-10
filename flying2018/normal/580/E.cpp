#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define ll long long
#define P pair<ll,ll>
#define MP make_pair
#define fi first
#define se second
#define mod1 998244353
#define mod2 1000000007 
using namespace std;
P operator +(const P a,const P b){return MP((a.fi+b.fi)%mod1,(a.se+b.se)%mod2);}
P operator -(const P a,const P b){return MP((a.fi-b.fi+mod1)%mod1,(a.se-b.se+mod2)%mod2);}
P operator *(const P a,const P b){return MP(a.fi*b.fi%mod1,a.se*b.se%mod2);}
P operator +(const P a,const int b){return MP((a.fi+b)%mod1,(a.se+b)%mod2);}
P base=MP(23,233);
P bs[N];
struct node{
	P v;
	int l;
	node(P V=MP(0,0),int L=0):v(V),l(L){}
	bool operator ==(const node a)const{return v==a.v;}
	node operator +(const node a)const{return node(v*bs[a.l]+a.v,l+a.l);}
}val[N<<2],bsv[12][N];
int tag[N];
char s[N];
void build(int u,int l,int r)
{
	if(l==r){val[u]=node(MP(s[l]-'0'+1,s[l]-'0'+1),1);return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid),build(u<<1|1,mid+1,r);
	val[u]=val[u<<1]+val[u<<1|1];
}
void set_tag(int u,int l,int r,int v){val[u]=bsv[v][r-l+1];tag[u]=v;}
void push_down(int u,int l,int r)
{
	if(!tag[u]) return;
	int mid=(l+r)>>1;
	set_tag(u<<1,l,mid,tag[u]),set_tag(u<<1|1,mid+1,r,tag[u]);
	tag[u]=0;
}
void insert(int u,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R){set_tag(u,l,r,v);return;}
	push_down(u,l,r);
	int mid=(l+r)>>1;
	if(L<=mid) insert(u<<1,l,mid,L,R,v);
	if(R>mid) insert(u<<1|1,mid+1,r,L,R,v);
	val[u]=val[u<<1]+val[u<<1|1];
}
node answer(int u,int l,int r,int L,int R)
{
	if(L<=l && r<=R) return val[u];
	int mid=(l+r)>>1;
	push_down(u,l,r);
	node ans;
	if(L<=mid) ans=ans+answer(u<<1,l,mid,L,R);
	if(R>mid) ans=ans+answer(u<<1|1,mid+1,r,L,R);
	return ans;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d%s",&n,&m,&k,s+1),m+=k;
	bs[0]=MP(1,1);
	for(int i=1;i<=n;i++) bs[i]=bs[i-1]*base;
	for(int i=1;i<=10;i++)
	{
		bsv[i][1]=node(MP(i,i),1);
		for(int j=2;j<=n;j++) bsv[i][j]=bsv[i][j-1]+bsv[i][1];
	}
	build(1,1,n);
	while(m --> 0)
	{
		int opt,l,r,d;
		scanf("%d%d%d%d",&opt,&l,&r,&d);
		if(opt==1) insert(1,1,n,l,r,d+1);
		else
		{
			if(r-l+1<d) puts("NO");
			else if(r-l+1==d) puts("YES");
			else puts(answer(1,1,n,l,r-d)==answer(1,1,n,l+d,r)?"YES":"NO");
		}
	}
	return 0;
}