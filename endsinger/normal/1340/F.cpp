#include<bits/stdc++.h>
using namespace std;
const int N=100005,B=405,K=300,mod=1000000007;
int n,m,w,a[N],l[B],r[B],b1,b2,p1[B],p2[N],fl[B];
int rnd(){int x=0;for(int i=1;i<=9;i++)x=x*10+rand()%10;return x;}
void init()
{
	b1=rnd()%50000000;
	b2=rnd()%50000000;
	p1[0]=p2[0]=1;
	for(int i=1;i<B;i++)
		p1[i]=1ll*p1[i-1]*b1%mod,p2[i]=1ll*p2[i-1]*b2%mod;
}
struct Hash
{
	int a[B],v1[B],v2[B],t;
	void init(){t=0;}
	void ins(int x){a[++t]=x;}
	void build()
	{
		v1[0]=v2[0]=0;
		for(int i=1;i<=t;i++)
			v1[i]=(1ll*v1[i-1]*b1+a[i])%mod,v2[i]=(1ll*v2[i-1]*b2+a[i])%mod;
	}
	pair<int,int> ask(int r,int l)
	{
		int k1=(v1[r]+mod-1ll*v1[r-l]*p1[l]%mod)%mod;
		int k2=(v2[r]+mod-1ll*v2[r-l]*p2[l]%mod)%mod;
		return make_pair(k1,k2);
	}
}h1[B],h2[B];
void build(int id,int l,int r)
{
	static int q[B],t;
	t=fl[id]=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]<0&&t&&q[t]==-a[i])
			t--;
		else
			q[++t]=a[i];
	}
	for(int i=2;i<=t;i++)
		if(q[i]<0&&q[i-1]>0)
			fl[id]=1;
	if(fl[id])
		return;
	h1[id].init(),h2[id].init();
	for(int i=t;i>=1;i--)
		if(q[i]<0)
			h1[id].ins(-q[i]);
	for(int i=1;i<=t;i++)
		if(q[i]>0)
			h2[id].ins(q[i]);
	h1[id].build(),h2[id].build();
}
void change(int x,int y)
{
	a[x]=y;
	int k=(x-1)/K+1;
	build(k,l[k],r[k]);
}
int t,ok;
pair<int,int>q[B];
void insert(int id)
{
	if(fl[id])
		ok=0;
	if(!ok)
		return;
	int l=h1[id].t;
	for(;t&&ok&&l;)
	{
		int v=min(q[t].second,l);
		if(h2[q[t].first].ask(q[t].second,v)!=h1[id].ask(l,v))
			ok=0;
		if(!(q[t].second-=v))
			t--;
		l-=v;
	}
	if(l)
		ok=0;
	if(h2[id].t)
		q[++t]=make_pair(id,h2[id].t);
}
int query(int le,int ri)
{
	int bl=(le-1)/K+1,br=(ri-1)/K+1;
	if(bl==br)
	{
		static int q[B],t;
		t=0;
		for(int i=le;i<=ri;i++)
		{
			if(a[i]<0&&t&&q[t]==-a[i])
				t--;
			else
				q[++t]=a[i];
		}	
		return !t;
	}
	else
	{
		build(m+1,le,r[bl]);
		build(m+2,l[br],ri);
		t=0,ok=1;
		insert(m+1);
		for(int i=bl+1;i<=br-1;i++)
			insert(i);
		insert(m+2);
		return ok&&!t;
	}
}
int main()
{
	init();
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m=(n-1)/K+1;
	for(int i=1;i<=m;i++)
	{
		l[i]=(i-1)*K+1;
		r[i]=min(n,i*K);
		build(i,l[i],r[i]);
	}
	scanf("%d",&w);
	while(w--)
	{
		int ty,x,y;
		scanf("%d%d%d",&ty,&x,&y);
		if(ty==1)
			change(x,y);
		if(ty==2)
			puts(query(x,y)?"Yes":"No");
	}
	return 0;
}