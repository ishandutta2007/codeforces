// Problem: A. Meximum Array
// Contest: Codeforces Round #767 (Div. 1)
// URL: https://codeforces.com/contest/1628/problem/A
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[200003];
deque<int> s[200003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=0; i<=n+1; ++i)while(!s[i].empty()) s[i].pop_front();
		for(int i=1; i<=n; ++i) s[read()].push_back(i);
		vector<int> b;
		int sdt=1;
		while(1)
		{
				int cur=0,qwq=0;
				while(1) 
				{
					while(!s[cur].empty()&&s[cur].front()<sdt) s[cur].pop_front();
					if(s[cur].empty()) break;
					qwq=max(s[cur].front(),qwq);
					++cur;
				}
				if(cur==0)
				{
					for(int i=sdt; i<=n; ++i) b.push_back(0);
					break;
				}
				else{
				sdt=qwq+1;
				b.push_back(cur);
		}}
		printf("%d\n",(int)b.size());
		for(auto i:b) printf("%d ",i);
		puts("");
	}
	return 0;
}