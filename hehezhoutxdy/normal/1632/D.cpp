// Problem: D. New Year Concert
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
struct node
{
	int x,l,r;
};
vector<node> v;
int a[1000003];
signed main()
{
	int n=read();
	for(int i=1,ans=0; i<=n; ++i)
	{
		a[i]=read();
		vector<node> vv;
		v.push_back((node){a[i],i,i});
		int N=(int)v.size();
		for(int j=0; j<N; ++j) v[j].x=__gcd(v[j].x,a[i]);
		node A=v[0];
		if(N==1) vv.push_back(A);
		for(int j=1; j<N; ++j)
		{
			if(A.x!=v[j].x) vv.push_back(A),A=v[j];
			else A.r=v[j].r;
			if(j==N-1) vv.push_back(A);
		}
		vv.swap(v);
		bool flg=0;
		for(auto j:v)
			if(i-j.r+1<=j.x&&j.x<=i-j.l+1) flg=1;
		if(flg)
		{
			v.clear();
			++ans;
			v.push_back((node){998244353,i,i});
		}
		printf("%d ",ans);
	}
	return 0;
}