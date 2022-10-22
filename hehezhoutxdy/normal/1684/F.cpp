//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],vv[1000003],f[1000003],g[1000003],c[1000003],lsh[1000003],pig[1000003];
vector<int> e[1000003],pos[1000003];
int val[4000003];
void update(int nl,int nr,int l,int r,int v,int x)
{
	if(r<nl||nr<l) return ;
	if(l<=nl&&nr<=r) {val[x]=max(val[x],v);return;}
	int mid=(nl+nr)>>1;
	update(nl,mid,l,r,v,x<<1),update(mid+1,nr,l,r,v,(x<<1)+1);
}
void build(int l,int r,int x,int v=0)
{
	v=max(v,val[x]),val[x]=0;
	if(l==r)
	{
		vv[l]=v,pos[v].push_back(l);
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,x<<1,v),build(mid+1,r,(x<<1)+1,v);
}
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) lsh[i]=a[i]=read(),e[i].clear(),pos[i].clear();
		sort(lsh+1,lsh+n+1);
		int N=unique(lsh+1,lsh+n+1)-lsh-1;
		for(int i=1; i<=n; ++i) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh;
		for(int i=1; i<=N; ++i) c[i]=0;
		for(int i=1,l=1; i<=n; ++i)
		{
			while(c[a[i]]) c[a[l++]]=0;
			f[i]=l,c[a[i]]=1;
		}
		for(int i=1; i<=N; ++i) c[i]=0;
		for(int i=n,l=n; i>=1; --i)
		{
			while(c[a[i]]) c[a[l--]]=0;
			g[i]=l,c[a[i]]=1;
		}
		int r0=0,l0=n;
		for(int i=1,l,r; i<=m; ++i) 
		{
			l=read(),r=read();
			update(1,n,l,r,r,1);
			if(f[r]>l) r0=max(r0,f[r]-1);
			if(g[l]<r) l0=min(l0,g[l]);
		}
		for(int i=1; i<=N; ++i) c[i]=0;
		for(int i=1; i<=n; ++i) pig[i]=0;
		build(1,n,1);
		for(int i=1; i<=n; ++i)
		{
			c[a[i]]=i;
			for(int j:pos[i]) pig[j]=c[a[j]];
		}
		int ans=r0;
		for(int l=2,r=r0; l<=l0+1&&l<=n; ++l)
		{
			r=max(r,pig[l-1]);
			ans=min(ans,r-l+1);
		}
		printf("%d\n",max(ans,0));
	}
	return 0;
}