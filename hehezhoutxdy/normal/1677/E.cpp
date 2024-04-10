// Problem: E. Tokitsukaze and Beautiful Subsegments
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003],pos[200003],ls[200003],rs[200003];
vector<int> d[200003];
const int N=2e5;
struct s1{int l,r,v1,v2;};
vector<s1> v1[200003];
struct s2{int l,r,v,id;};
vector<s2> v2[200003];
int ans[1000003];
void qwq(int l1,int r1,int l2,int r2)
{
	
	v1[l1].push_back((s1){l2,r2,1,1-l1}),
	v1[r1].push_back((s1){l2,r2,-1,r1});
	return ;
}
void dfs(int l,int r,int x)
{
	vector<pair<int,int>> v,g;
	for(int i:d[x])
		if(l<=pos[i]&&l<=pos[x/i]&&pos[i]<=r&&pos[x/i]<=r)
			v.push_back(make_pair(
				min(min(pos[i],pos[x/i]),pos[x]),
				-max(max(pos[i],pos[x/i]),pos[x])
			));
	if(!v.empty())
	{
		sort(v.begin(),v.end());
		for(auto &i:v)
		{
			i.second=-i.second;
			while(!g.empty()&&g.back().second>=i.second)
				g.pop_back();
			g.push_back(i);
		}
		int sz=g.size();
		qwq(l,g[0].first,g[0].second,r);
		for(int i=1; i<sz; ++i) 
			// assert(g[i-1].first!=g[i].first),
			qwq(g[i-1].first+1,g[i].first,g[i].second,r);
	}
	if(ls[x]) dfs(l,pos[x]-1,ls[x]);
	if(rs[x]) dfs(pos[x]+1,r,rs[x]);
	return ;
}
struct seg
{
	int tag[1000003],ans[1000003];
	void push_down(int x,int l1,int l2)
	{
		tag[x<<1]+=tag[x],tag[(x<<1)+1]+=tag[x];
		ans[x<<1]+=tag[x]*l1,ans[(x<<1)+1]+=tag[x]*l2;
		tag[x]=0;
		return ;
	}
	void update(int l,int r,int& L,int& R,int id,int &val)
	{
		if(L<=l && r<=R) 
		{
			tag[id]+=val;
			ans[id]+=(r-l+1)*val;
			return ;
		}
		int mid=(l+r)>>1;
		push_down(id,mid-l+1,r-mid);
		if(L<=mid) update(l,mid,L,R,id<<1,val);
		if(R>=mid+1) update(mid+1,r,L,R,(id<<1)+1,val);
		ans[id]=ans[(id<<1)]+ans[(id<<1)+1];
		return ;
	}
	long long query(int l,int r,int& L,int& R,int id)
	{
		if(L<=l && r<=R) return ans[id];
		int mid=(l+r)>>1;
		push_down(id,mid-l+1,r-mid);
		long long res=0;
		if(L<=mid) res+=query(l,mid,L,R,id<<1);
		if(R>=mid+1) res+=query(mid+1,r,L,R,(id<<1)+1);
		return res;
	}
}A,B;
signed main()
{
	int n=read(),m=read();
	stack<int> stk;
	for(int i=1; i<=N; ++i)
		for(int j=i+1; i*j<=N; ++j)
			d[i*j].push_back(i);
	for(int i=1; i<=n; ++i) pos[a[i]=read()]=i;
	for(int i=1; i<=n; ++i)
	{
		while(!stk.empty()&&a[i]>stk.top())
			ls[a[i]]=stk.top(),stk.pop();
		if(!stk.empty()) rs[stk.top()]=a[i];
		stk.push(a[i]);
	}
	dfs(1,n,n);
	for(int i=1,l,r; i<=m; ++i)
		l=read(),r=read(),
		v2[l-1].push_back((s2){l,r,-1,i}),
		v2[r].push_back((s2){l,r,1,i});
	for(int i=1; i<=n; ++i)
	{
		for(s1 j:v1[i])
			A.update(1,n,j.l,j.r,1,j.v1),
			B.update(1,n,j.l,j.r,1,j.v2);
		for(s2 j:v2[i])
			ans[j.id]+=(i*A.query(1,n,j.l,j.r,1)
			+B.query(1,n,j.l,j.r,1))*j.v;
	}
	for(int i=1; i<=m; ++i) printf("%lld\n",ans[i]);
	return 0;
}