//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int N=1e9;
struct node
{
	int x,y,z;
	bool operator<(const node&t)const{return y<t.y;}
}a[100003],b[100003];
int ls[10000003],rs[10000003],val[10000003];
ll ans=0;
int n=read(),d=read(),cnt;
void update(int nl,int nr,int l,int r,int x,int v)
{
	if(r<nl||nr<l) return ;
	if(l<=nl&&nr<=r) 
	{
		val[x]+=v;
		return ;
	}
	int mid=(nl+nr)>>1;
	(!ls[x])&&(ls[x]=++cnt,ls[cnt]=rs[cnt]=val[cnt]=0,0),
	(!rs[x])&&(rs[x]=++cnt,ls[cnt]=rs[cnt]=val[cnt]=0,0),
	update(nl,mid,l,r,ls[x],v),update(mid+1,nr,l,r,rs[x],v);
	return ;
}
int query(int nl,int nr,int pos,int x)
{
	if(nl==nr) return val[x];
	int mid=(nl+nr)>>1;
	if(pos<=mid) return val[x]+(ls[x]?query(nl,mid,pos,ls[x]):0);
	else return val[x]+(rs[x]?query(mid+1,nr,pos,rs[x]):0);
}
void solve(int l,int r)
{
	if(l==r) return ;
	int mid=(l+r)>>1,pl=l,pr=l,t=l;
	solve(l,mid),solve(mid+1,r),cnt=1,ls[1]=rs[1]=val[1]=0;
	for(int i=mid+1; i<=r; ++i)
	{
		while(pr<=mid&&a[pr].z<=a[i].z+d) 
			update(1,N,max(1,a[pr].x-a[pr].y),min(N,a[pr].x+a[pr].y),1,1),++pr;
		while(pl<=mid&&a[pl].z<a[i].z-d) 
			update(1,N,max(1,a[pl].x-a[pl].y),min(N,a[pl].x+a[pl].y),1,-1),++pl;
		ans+=query(1,N,a[i].x,1);
	}
	pl=l,pr=mid+1;
	while(pl<=mid&&pr<=r)
		if(a[pl].z<=a[pr].z) b[t++]=a[pl++];
		else b[t++]=a[pr++];
	while(pl<=mid) b[t++]=a[pl++];
	while(pr<=r) b[t++]=a[pr++];
	for(int i=l; i<=r; ++i) a[i]=b[i];
	return ;
}
signed main()
{
	for(int i=1; i<=n; ++i) 
		a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+n+1),solve(1,n),
	printf("%lld\n",ans);
	return 0;
}