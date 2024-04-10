// Problem: F. Burenka, an Array and Queries
// Contest: Codeforces - Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
#define arr bitset<100001>
arr f[2303],g[2303],h[8192];
int n=read(),m=read(),C=read(),Q=read();
int p[20003],ans[100003],pc;
struct query{int l,r,v;}q[100003];
int fi[100003],gi[100003];
bitset<20001> vis;
vector<int> vec[100003];
void solve(int l,int r,vector<int>&v)
{
	vector<int> ls,rs;
	int mid=(l+r)>>1;
	bool flg=0;
	for(int i:v) 
		if(q[i].r<mid) ls.emplace_back(i);
		else if(q[i].l>mid) rs.emplace_back(i);
		else flg=1;
	if(flg)
	{
		int fs=0,gs=0;
		fi[mid+1]=gi[mid-1]=0;
		for(int i=mid; i>=l; --i) 
		{
			for(int j:vec[i]) if(!vis[j])
			{
				vis[j]=1,++fs,f[fs]=f[fs-1];
				for(int k=1; j*k<=C; ++k) f[fs][j*k]=1;
			}
			fi[i]=fs;
		}
		for(int i=mid; i>=l; --i)
			for(int j:vec[i])
				vis[j]=0;
		for(int i=mid; i<=r; ++i)
		{
			for(int j:vec[i]) if(!vis[j])
			{
				vis[j]=1,++gs,g[gs]=g[gs-1];
				for(int k=1; j*k<=C; ++k) g[gs][j*k]=1;
			}
			gi[i]=gs;
		}
		for(int i=mid; i<=r; ++i)
			for(int j:vec[i])
				vis[j]=0;
		for(int i:v) if(q[i].l<=mid&&q[i].r>=mid)
			ans[i]=C-
			(f[fi[q[i].l]]|g[gi[q[i].r]]|h[q[i].v]).count();
	}
	if(!ls.empty()) solve(l,mid-1,ls);
	if(!rs.empty()) solve(mid+1,r,rs);
	return ; 
}
struct stor
{
	int a[100003],st[100003][17],l2[100003];
	inline void init(int l)
	{
		st[l][0]=a[l];
		for(int i=1; i<=16; i++) 
		st[l][i]=st[l][i-1]|st[min(l+(1<<(i-1)),n)][i-1];
	}
	inline int query(int l,int r)
	{
		int L=l2[r-l+1];
		return st[l][L]|st[min(r-(1<<L)+1,n)][L];
	}
	void main()
	{
	    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
		for(int i=n; i; --i) init(i);
		return ;
	}
}st;
signed main()
{
	m=20000;
	for(int i=2; i<=m; ++i) if(!vis[i])
	{
		p[++pc]=i;
		for(int j=2; i*j<=m; ++j) vis[i*j]=1;
	}
	for(int i=1; i<=n; ++i)
	{
		int x=read();
		for(int j=1; j<=13; ++j) if(x%p[j]==0)
		{
			st.a[i]+=1<<(j-1);
			while(x%p[j]==0) x/=p[j];
		}
		for(int j=14; j<=pc&&p[j]*p[j]<=x; ++j)
			if(x%p[j]==0)
				vec[i].push_back(p[j]),
				vec[i].push_back(x/p[j]),x=1;
		if(x>1) vec[i].push_back(x);
	}
	st.main();
	vector<int> v(Q);
	for(int i=1; i<=Q; ++i)
		q[i].l=read(),q[i].r=read(),
		q[i].v=st.query(q[i].l,q[i].r),v[i-1]=i;
	for(int i=1; i<=13; ++i)
		for(int j=1; p[i]*j<=C; ++j)
			h[1<<(i-1)][p[i]*j]=1;
	for(int i=3; i<8192; ++i)
		if((i&(-i))!=i)
			h[i]=h[i&(-i)]|h[i-(i&(-i))];
	solve(1,n,v);
	for(int i=1; i<=Q; ++i) printf("%d\n",ans[i]);
	return 0;
}