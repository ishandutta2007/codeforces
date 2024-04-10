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
int a[1000003];
stack<int> stk;
int ls[1000003],rs[1000003],sz[1000003];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
gp_hash_table<int,int> c;
ll ans=0;
void dfs(int x)
{
	sz[x]=1;
	if(ls[x]) dfs(ls[x]),sz[x]+=sz[ls[x]];
	if(rs[x]) dfs(rs[x]),sz[x]+=sz[rs[x]];
	if(sz[ls[x]]>sz[rs[x]]) swap(ls[x],rs[x]);
	return ;
}
void clr(int x)
{
	--c[a[x]];
	if(ls[x]) clr(ls[x]);
	if(rs[x]) clr(rs[x]);
	return ;
}
void ins(int x)
{
	++c[a[x]];
	if(ls[x]) ins(ls[x]);
	if(rs[x]) ins(rs[x]);
	return ;
}
void add(int x,int v)
{
	ans+=c[v-a[x]];
	if(ls[x]) add(ls[x],v);
	if(rs[x]) add(rs[x],v);
	return ;
}
void calc(int x)
{
	sz[x]=1;
	if(ls[x]) calc(ls[x]),clr(ls[x]);
	if(rs[x]) calc(rs[x]);
	if(ls[x]) add(ls[x],a[x]),ins(ls[x]);
	++c[a[x]];
	return ;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i)
	{
		while(!stk.empty()&&a[i]>a[stk.top()])
			ls[i]=stk.top(),stk.pop();
		if(!stk.empty()) rs[stk.top()]=i;
		stk.push(i);
	}
	int rt=-1;
	while(!stk.empty()) rt=stk.top(),stk.pop();
	dfs(rt),calc(rt),printf("%lld\n",ans);
	return 0;
}