// Problem: D. Serious Business
// Contest: Codeforces - Codeforces Round #775 (Div. 1, based on Moscow Open Olympiad in Informatics)
// URL: https://codeforces.com/problemset/problem/1648/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int val[2000003],mn[2000003],nm[2000003],F[500003];
int a[500003],b[500003],c[500003],A[500003],B[500003];
void build(int l,int r,int x)
{
	if(l==r) 
	{
		val[x]=A[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1),build(mid+1,r,(x<<1)+1);
	val[x]=max(val[x<<1],val[(x<<1)+1]);
	return ;
}
int query(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) return -1e18;
	if(l<=nl&&nr<=r) return val[x];
	int mid=(nl+nr)>>1;
	return max(query(nl,mid,l,r,x<<1),query(mid+1,nr,l,r,(x<<1)+1));
}
void update(int l,int r,int pos,int x,int v)
{
	if(l==r) 
	{
		F[l]=val[x]=max(val[x],v);
		return ;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,pos,x<<1,v);
	else update(mid+1,r,pos,(x<<1)+1,v);
	val[x]=max(val[x<<1],val[(x<<1)+1]);
	return ;
}
struct node{int l,k;};
vector<node> v[500003];
int n=read(),m=read();
int l2[500003];
struct stmax
{
	int a[500003],st[500003][20];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<20; i++) 
		st[l][i]=max(st[l][i-1],st[min(l+(1<<(i-1)),n)][i-1]);
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return max(st[l][L],st[min(r-(1<<L)+1,n)][L]);
	}
	void main()
	{
		for(int i=n; i; --i) init(i);
		return ;
	}
}s0,sA,sB;
void Build(int l,int r,int x)
{
	if(l==r) 
	{
		mn[x]=F[l]+B[l];
		return ;
	}
	int mid=(l+r)>>1;
	Build(l,mid,x<<1),Build(mid+1,r,(x<<1)+1);
	mn[x]=max(mn[x<<1],mn[(x<<1)+1]);
	if(mid<r) 
	mn[x]=max(mn[x],sA.query(l,mid)+sB.query(mid+1,r));
	return ;
}
int Query(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) return -1e18;
	if(l<=nl&&nr<=r) return mn[x];
	int mid=(nl+nr)>>1,res=max(Query(nl,mid,l,r,x<<1),Query(mid+1,nr,l,r,(x<<1)+1));
	if(l<=mid&&r>mid) res=max(res,sA.query(l,mid)+sB.query(mid+1,r));	
	return res;
}
void builD(int l,int r,int x)
{
	if(l==r) 
	{
		nm[x]=A[l]+B[l];
		return ;
	}
	int mid=(l+r)>>1;
	builD(l,mid,x<<1),builD(mid+1,r,(x<<1)+1);
	nm[x]=max(nm[x<<1],nm[(x<<1)+1]);
	if(mid<r) 
	nm[x]=max(nm[x],s0.query(l,mid)+sB.query(mid+1,r));
	return ;
}
int querY(int nl,int nr,int l,int r,int x)
{
	if(nr<l||r<nl) return -1e18;
	if(l<=nl&&nr<=r) return nm[x];
	int mid=(nl+nr)>>1,res=max(querY(nl,mid,l,r,x<<1),querY(mid+1,nr,l,r,(x<<1)+1));
	if(l<=mid&&r>mid) res=max(res,s0.query(l,mid)+sB.query(mid+1,r));	
	return res;
}
signed main()
{
	for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
	for(int i=1; i<=n; ++i) a[i]=a[i-1]+read();
	for(int i=1; i<=n; ++i) b[i]=b[i-1]+read();
	for(int i=1; i<=n; ++i) c[i]=c[i-1]+read();
	for(int i=1; i<=n; ++i) s0.a[i]=A[i]=a[i]-b[i-1];
	for(int i=1; i<=n; ++i) B[i]=c[n]-c[i-1]+b[i];
	memset(val,0xc0,sizeof(val)),s0.main();
	for(int l,r,k; m--;)
		l=read(),r=read(),k=read(),
		v[r].push_back((node){l,k});
	memset(F,0xc0,sizeof(F));
	for(int r=1; r<=n; ++r)
		for(node i:v[r])
			update(1,n,r,1,
				max(s0.query(i.l,r),query(1,n,max(1ll,i.l-1),r,1))
				-i.k);
	int ans=-1e18;
	for(int i=1; i<=n; ++i) 
		sA.a[i]=F[i],sB.a[i]=B[i],ans=max(ans,F[i]+B[i]);
	sA.main(),sB.main(),Build(1,n,1),builD(1,n,1);
	for(int r=1; r<=n; ++r)
		for(node i:v[r])
			ans=max(ans,Query(1,n,max(1ll,i.l-1),r,1)-i.k),
			ans=max(ans,querY(1,n,i.l,r,1)-i.k);
	printf("%lld\n",ans);
	return 0;
}