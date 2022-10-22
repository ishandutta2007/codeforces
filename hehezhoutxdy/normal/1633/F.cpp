// Problem: F. Perfect Matching
// Contest: Codeforces - Educational Codeforces Round 122 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1633/problem/F
// Memory Limit: 512 MB
// Time Limit: 12000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int ans[500003];
#define mp make_pair
vector<pair<int,int> > e[300003];
int sz[300003],fa[300003],dep[300003],son[300003],top[300003];
int dfn[300003],inv[300003],lst[300003],tot;
int faid[300003];
inline void dfs1(int x)
{
    sz[x]=1;
    for(auto xx:e[x]) {int y=xx.first;if(y!=fa[x])
    {
        if(y==fa[x])continue;
        fa[y]=x,dep[y]=dep[x]+1,faid[y]=xx.second,dfs1(y),sz[x]+=sz[y];
        (sz[y]>sz[son[x]])&&(son[x]=y);
    }}
}
inline void dfs2(int x,int tp)
{
    top[x]=tp,dfn[x]=++tot,inv[tot]=x;
    if(son[x]) dfs2(son[x],tp);
    for(auto xx:e[x]) {int y=xx.first;
        if(y!=son[x]&&y!=fa[x])dfs2(y,y);}
    lst[x]=tot;
}
int sum[1000003],cnt[1000003],tag[1000003];
int sc[1000003],sv[1000003],VAL[1000003];
void build(int l,int r,int i)
{
	if(l==r){sc[i]=1,sv[i]=VAL[l];return ;}
	int mid=(l+r)>>1;
	build(l,mid,i<<1),build(mid+1,r,(i<<1)+1);
	sc[i]=sc[i<<1]+sc[(i<<1)+1],sv[i]=sv[i<<1]+sv[(i<<1)+1];
	return ;
}
void build1(int l,int r,int i)
{
	if(l==r){ans[faid[inv[l]]]=cnt[i];return ;}
	int mid=(l+r)>>1;
	if(tag[i])
	{
		int A=i<<1;
		tag[A]^=1,sum[A]=sv[A]-sum[A],cnt[A]=sc[A]-cnt[A];
		A=(i<<1)+1;
		tag[A]^=1,sum[A]=sv[A]-sum[A],cnt[A]=sc[A]-cnt[A];
		tag[i]=0;
	}
	build1(l,mid,i<<1),build1(mid+1,r,(i<<1)+1);
	return ;
}
inline void update(int nl,int nr,int l,int r,int i)
{
	if(r<nl||nr<l) return ;
	if(l<=nl&&nr<=r) 
	{
		tag[i]^=1,sum[i]=sv[i]-sum[i],cnt[i]=sc[i]-cnt[i];
		return ;
	}
	int mid=(nl+nr)>>1;
	if(tag[i])
	{
		int A=i<<1;
		tag[A]^=1,sum[A]=sv[A]-sum[A],cnt[A]=sc[A]-cnt[A];
		A=(i<<1)+1;
		tag[A]^=1,sum[A]=sv[A]-sum[A],cnt[A]=sc[A]-cnt[A];
		tag[i]=0;
	}
	update(nl,mid,l,r,i<<1),update(mid+1,nr,l,r,(i<<1)+1),
	cnt[i]=cnt[i<<1]+cnt[(i<<1)+1],sum[i]=sum[i<<1]+sum[(i<<1)+1];
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<n; ++i)
	{
		int A=read(),B=read();
		e[A].push_back(make_pair(B,i)),
		e[B].push_back(make_pair(A,i));
	}
	dfs1(1),dfs2(1,1);
	for(int i=1; i<=n; ++i) VAL[dfn[i]]=faid[i];
	build(1,n,1);
	update(1,n,dfn[1],dfn[1],1);
	int S=1,lst=0;
	while(1)
	{
		int op=read();
		if(op==1)
		{
			int x=read();
			++S;
			while(1)
			{
				update(1,n,dfn[top[x]],dfn[x],1);
				if(top[x]==1) break;
				else x=fa[top[x]];
			}
			// printf("%lld ",sum[1]);
			if(cnt[1]*2!=S) lst=0,puts("0");
			else printf("%lld\n",lst=sum[1]);
			fflush(stdout);
		}
		else if(op==2)
		{
			if(lst==0) {puts("0");fflush(stdout);continue;}
			for(int i=1; i<n; ++i) ans[i]=0;
			build1(1,n,1);
			printf("%lld ",S>>1);
			for(int i=1; i<n; ++i) if(ans[i]) printf("%lld ",i);
			puts("");
			fflush(stdout);
		}
		else exit(0);
	}
	return 0;
}