// Problem: E. Fox And Polygon
// Contest: Codeforces - Codeforces Round #290 (Div. 1)
// URL: https://codeforces.com/problemset/problem/512/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
void dfs(vector<int>&v,vector<pair<int,int>>&e,vector<pair<int,int>>&ans,bool flg)
{
	assert(e.size()+3==v.size());
	if(e.empty()) return ;
	vector<int> v1,v2;
	vector<pair<int,int>> e1,e2;
	for(auto i:e) if(i.first==1)
	{
		v2.push_back(1),v2.push_back(i.second);
		for(int j:v) 
			if(j<=i.second) v1.push_back(j);
			else v2.push_back(j);
		for(auto j:e) if(i!=j)
		{
			auto x=find(v1.begin(),v1.end(),j.first);
			auto y=find(v1.begin(),v1.end(),j.second);
			if(x!=v1.end()&&y!=v1.end()) e1.push_back(j);
			else e2.push_back(j);
		}
		dfs(v1,e1,ans,flg),dfs(v2,e2,ans,flg);
		return ;
	}
	int x=v[1],y=v[v.size()-1],z=v[2];
	for(auto j:e) if(j.first==x&&j!=make_pair(x,y)) 
		z=max(z,j.second);
	if(flg) ans.push_back(make_pair(1,z));
	else ans.push_back(make_pair(x,y));
	v2.push_back(1),v2.push_back(z);
	for(int j:v) 
		if(j<=z) v1.push_back(j);
		else v2.push_back(j);
	for(auto j:e) if(j!=make_pair(x,y))
	{
		auto x=find(v1.begin(),v1.end(),j.first);
		auto y=find(v1.begin(),v1.end(),j.second);
		if(x!=v1.end()&&y!=v1.end()) e1.push_back(j);
		else e2.push_back(j);
	}
	dfs(v1,e1,ans,flg),dfs(v2,e2,ans,flg);
	return ;
}
vector<pair<int,int>> solve(int n,bool flg)
{
	vector<int> v;
	vector<pair<int,int>> e,res;
	for(int i=1; i<=n; ++i) v.push_back(i);
	for(int i=1,x,y; i+3<=n; ++i)
	{
		x=read(),y=read();
		if(x>y) swap(x,y);
		e.push_back(make_pair(x,y));
	}
	dfs(v,e,res,flg);
	return res;
}
signed main()
{
	int n=read();
	vector<pair<int,int>> A=solve(n,0),B=solve(n,1);
	reverse(B.begin(),B.end());
	printf("%d\n",(int)A.size()+(int)B.size());
	for(auto i:A) printf("%d %d\n",i.first,i.second);
	for(auto i:B) printf("%d %d\n",i.first,i.second);
	return 0;
}