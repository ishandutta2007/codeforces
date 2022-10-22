#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,a[N],b[N],c[N],od[N],rt[N],lc[N<<6],rc[N<<6],t,sq[N],tp,lt[N],lv[N];
long long sa[N<<6],sb[N<<6],ans;
struct nd{int l,r,w;}st[N];
int build(int l,int r)
{
	int k=++t;
	if(l==r)
		return k;
	int mid=l+r>>1;
	lc[k]=build(l,mid);
	rc[k]=build(mid+1,r);
	return k;
}
int add(int o,int l,int r,int x)
{
	int k=++t;
	lc[k]=lc[o],rc[k]=rc[o],sa[k]=sa[o],sb[k]=sb[o];
	if(l==r)
	{
		sa[k]=a[x];
		sb[k]=b[x];
		return k;
	}
	int mid=l+r>>1;
	if(x<=mid) lc[k]=add(lc[k],l,mid,x);
	else rc[k]=add(rc[k],mid+1,r,x);
	sa[k]=sa[lc[k]]+sa[rc[k]];
	sb[k]=sb[lc[k]]+sb[rc[k]];
	return k;
}
long long aska(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return sa[k];
	int mid=l+r>>1;
	if(b<=mid) return aska(lc[k],l,mid,a,b);
	else if(a>mid) return aska(rc[k],mid+1,r,a,b);
	else return aska(lc[k],l,mid,a,mid)+aska(rc[k],mid+1,r,mid+1,b);
}
long long askb(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return sb[k];
	int mid=l+r>>1;
	if(b<=mid) return askb(lc[k],l,mid,a,b);
	else if(a>mid) return askb(rc[k],mid+1,r,a,b);
	else return askb(lc[k],l,mid,a,mid)+askb(rc[k],mid+1,r,mid+1,b);
}
pair<long long,int> bs(int k1,int k2,int l,int r,int a,int b,int ti,long long h)
{
	if(l==r)
		return {sa[k1]+ti*(sb[k2]-sb[k1]),l};
	if(l==a&&r==b)
	{
		int mid=l+r>>1;
		long long w=sa[lc[k1]]+ti*(sb[lc[k2]]-sb[lc[k1]]);
		if(w>=h)
			return bs(lc[k1],lc[k2],l,mid,l,mid,ti,h);
		else
		{
			auto zr=bs(rc[k1],rc[k2],mid+1,r,mid+1,r,ti,h-w);	
			zr.first+=w;
			return zr;
		}
	}
	int mid=l+r>>1;
	if(b<=mid) return bs(lc[k1],lc[k2],l,mid,a,b,ti,h);
	else if(a>mid) return bs(rc[k1],rc[k2],mid+1,r,a,b,ti,h);
	else
	{
		auto zl=bs(lc[k1],lc[k2],l,mid,a,mid,ti,h);
		if(zl.first>=h)
			return zl;
		auto zr=bs(rc[k1],rc[k2],mid+1,r,mid+1,b,ti,h-zl.first);
		zr.first+=zl.first;
		return zr;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		c[i]=(a[i]+b[i]-1)/b[i];
		od[i]=i;
		lv[i]=a[i];
	}
	sort(od+1,od+n+1,[&](int x,int y){return c[x]<c[y];});
	rt[0]=build(1,n);
	for(int i=1;i<=n;i++)
	{
		sq[i]=c[od[i]];
		rt[i]=add(rt[i-1],1,n,od[i]);
	}
	sq[n+1]=INT_MAX;
	for(int i=n;i>=1;i--)
		st[++tp]={i,i,-1};
	scanf("%d",&q);
	while(q--)
	{
		int x;
		long long h;
		scanf("%d%lld",&x,&h);
		while(h>0)
		{
			if(!tp)
				break;
			if(st[tp].w==-1)
			{
				for(int i=st[tp].l;i<=st[tp].r;i++)
				{
					long long v=lv[i]+1ll*b[i]*(x+i-1-lt[i]);
					v=min(v,1ll*a[i]);
					long long k=min(v,h);
					v-=k;
					h-=k;
					lt[i]=x+i-1;
					lv[i]=v;
					if(h<=0)
					{
						st[tp].l=i;
						break;
					}
				}
				if(h<=0)
					break;
				else
					tp--;
			}
			else
			{
				int l=st[tp].l,r=st[tp].r,ti=x+l-1-st[tp].w;
				int p=upper_bound(sq+1,sq+n+2,ti)-sq-1;
				long long s=aska(rt[p],1,n,l,r)+1ll*ti*(askb(rt[n],1,n,l,r)-askb(rt[p],1,n,l,r));
				if(s<h)
				{
					h-=s;
					tp--;
				}
				else
				{
					auto z=bs(rt[p],rt[n],1,n,l,r,ti,h);
					int g=z.second;
					h-=z.first;
					lt[g]=x+g-1;
					lv[g]=-h;
					if(g!=r)
						st[tp].l=g+1,st[tp].w+=g-l+1;
					else
						tp--;
					tp++;
					st[tp]={g,g,-1};
				}
			}
		}
		if(h>0)
		{
			ans+=h;
			tp=1;
			st[tp]={1,n,x};
		}
		else if(st[tp].l!=1)
		{
			tp++;
			st[tp]={1,st[tp-1].l-1,x};
		}
//		printf("@ %lld\n",ans);
//		for(int i=tp;i;i--)
//			printf("%d %d %d\n",st[i].l,st[i].r,st[i].w);
	}
	printf("%lld\n",ans);
	return 0;
}