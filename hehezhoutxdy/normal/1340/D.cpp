// Problem: A. Nastya and Time Machine
// Contest: Codeforces - Z Flip #2
// URL: https://codeforces.com/gym/374761/problem/A
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
vector<int> e[1000003];
vector<pair<int,int>> ans;
void dfs(int x,int fa,int sdt=0)
{
	int cnt=0,flg=1;
	for(int y:e[x]) if(y!=fa) ++cnt;
	for(int y:e[x]) if(y!=fa) 
	{
		ans.push_back(make_pair(x,sdt));
		if(sdt>=cnt+1&&flg) 
			sdt-=cnt+1,flg=0,ans.push_back(make_pair(x,sdt));
		dfs(y,x,++sdt);
	}
	ans.push_back(make_pair(x,sdt));
	if(sdt>=cnt+1&&flg) 
		sdt-=cnt+1,flg=0,ans.push_back(make_pair(x,sdt));
	return ;
}
signed main()
{
	int n=read();
	for(int u,v,i=1; i<n; ++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1,1);
	printf("%d\n",(int)ans.size());
	for(auto i:ans)
		printf("%d %d\n",i.first,i.second);
	return 0;
}