#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
ll rd()
{
	char c=getchar();ll x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
void wr(ll x)
{
	static int a[128],t;
	t=0;
	while(x)
	{
		a[t++]=x%10;
		x/=10;
	}
	for(int i=t-1;i>=0;i--)
		printf("%d",a[i]);
	printf(" ");
}
const int N=1005;
int n,m,va[N],vb[N];
ll a[N],b[N];
struct seg
{
	ll tr[N<<2];
	void build(int k,int l,int r,ll* a,ll v)
	{
		if(l==r)
		{
			tr[k]=v/__gcd(a[l],v);
			return;
		}	
		int mid=l+r>>1;
		build(k<<1,l,mid,a,v);
		build(k<<1|1,mid+1,r,a,v);
		tr[k]=__gcd(tr[k<<1],tr[k<<1|1]);
	}
	void del(int k,int l,int r,int x)
	{
		if(l==r)
		{
			tr[k]=0;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) del(k<<1,l,mid,x);
		else del(k<<1|1,mid+1,r,x);
		tr[k]=__gcd(tr[k<<1],tr[k<<1|1]);
	}
}sa[N],sb[N];
queue<pair<int,int>>q;
void sol()
{
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=m;i++)
		b[i]=rd();
	while(q.size())
		q.pop();
	for(int i=1;i<=n;i++)
	{
		sa[i].build(1,1,m,b,a[i]);
		va[i]=0;
		if(sa[i].tr[1]>1)
			q.push({i,0}),va[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		sb[i].build(1,1,n,a,b[i]);
		vb[i]=0;
		if(sb[i].tr[1]>1)
			q.push({i,1}),vb[i]=1;
	}
	while(q.size())
	{
		int p=q.front().first,z=q.front().second;
		q.pop();
		if(!z)
		{
			for(int i=1;i<=m;i++)
			{
				if(vb[i])
					continue;
				sb[i].del(1,1,n,p);
				if(sb[i].tr[1]>1)
					q.push({i,1}),vb[i]=1;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(va[i])
					continue;
				sa[i].del(1,1,m,p);
				if(sa[i].tr[1]>1)
					q.push({i,0}),va[i]=1;
			}
		}
	}
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
		if(!va[i])
			ca++;
	for(int i=1;i<=m;i++)
		if(!vb[i])
			cb++;
	if(ca==0||cb==0)
		puts("NO");
	else
	{
		puts("YES");
		printf("%d %d\n",ca,cb);
		for(int i=1;i<=n;i++)
			if(!va[i])
				wr(a[i]);
		puts("");
		for(int i=1;i<=m;i++)
			if(!vb[i])
				wr(b[i]);
		puts("");
	}
}
int main()
{
	int t=rd();
	while(t--)
		sol();
	return 0;
}