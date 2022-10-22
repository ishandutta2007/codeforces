#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
struct nd{int x,y,z;};
int n,m,a[N],b[N],tr[N<<2],tg[N<<2],bt[N],z[N];
vector<nd>v;
long long s;
void add(int x,int v)
{
	for(int i=x;i<=n;i+=i&(-i))
		bt[i]+=v;
}
int ask(int x)
{
	int v=0;
	for(int i=x;i;i-=i&(-i))
		v+=bt[i];
	return v;
}
void pd(int k)
{
	tr[k<<1]+=tg[k];
	tg[k<<1]+=tg[k];
	tr[k<<1|1]+=tg[k];
	tg[k<<1|1]+=tg[k];
	tg[k]=0;
}
void build(int k,int l,int r)
{
	tg[k]=0;
	if(l==r)
	{
		tr[k]=l-1;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void upd(int k,int l,int r,int a,int b,int v)
{
	if(l==a&&r==b)
	{
		tr[k]+=v;
		tg[k]+=v;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	if(b<=mid) upd(k<<1,l,mid,a,b,v);
	else if(a>mid) upd(k<<1|1,mid+1,r,a,b,v);
	else upd(k<<1,l,mid,a,mid,v),upd(k<<1|1,mid+1,r,mid+1,b,v);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void sol()
{
	scanf("%d%d",&n,&m);
	v.clear();
	for(int i=0;i<=n;i++)
		bt[i]=0;
	s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		z[i]=a[i];
		v.push_back({a[i],i,0});
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		v.push_back({b[i],i,1});
	}
	sort(v.begin(),v.end(),[&](nd a,nd b){return (a.x==b.x?a.z>b.z:a.x<b.x);});
	build(1,1,n+1);
	sort(z+1,z+n+1);
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(z+1,z+n+1,a[i])-z;
		s+=i-ask(x)-1;
		add(x,1);
	}
	for(int i=0;i<v.size();i++)
	{
		int j=i;
		while(j+1<v.size()&&v[j+1].x==v[j].x)
			j++;
		for(int k=i;k<=j;k++)
			if(!v[k].z)
				upd(1,1,n+1,v[k].y+1,n+1,-1);
		for(int k=i;k<=j;k++)
			if(v[k].z)
				s+=tr[1];
		for(int k=i;k<=j;k++)
			if(!v[k].z)
				upd(1,1,n+1,1,v[k].y,1);
		i=j;
	}
	printf("%lld\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}