// Problem: C. Tonya and Burenka-179
// Contest: Codeforces Round #814 (Div. 1)
// URL: https://codeforces.com/contest/1718/problem/C
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f[7][200003],a[200003];
		multiset<int> st[7];
		vector<int> D;
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		D.clear();
		int nn=n;
		for(int q=2; q*q<=nn; ++q) if(nn%q==0)
		{
			D.push_back(n/q);
			while(nn%q==0) nn/=q;
		}
		if(nn>1) D.push_back(n/nn);
		int sz=(int)D.size();
		for(int i=0; i<sz; ++i) st[i].clear();
		for(int i=0; i<n; ++i) a[i]=read();
		for(int i=0; i<sz; ++i)
		{
		for(int j=0; j<D[i]; ++j)
			f[i][j]=0;
			for(int j=0; j<n; ++j)
				f[i][j%D[i]]+=a[j];
			for(int j=0; j<D[i]; ++j)
				st[i].insert(f[i][j]);
		}
		int R=0;
		for(int i=0; i<sz; ++i)
			R=max(R,(*st[i].rbegin())*D[i]);
		printf("%lld\n",R);
		for(int x,y; m--;)
		{
			x=read()-1,y=read();
			for(int i=0; i<sz; ++i)
				st[i].erase(st[i].find(f[i][x%D[i]]));
			for(int i=0; i<sz; ++i)	
			f[i][x%D[i]]-=a[x];
			a[x]=y;
			for(int i=0; i<sz; ++i)	
			f[i][x%D[i]]+=a[x];
			for(int i=0; i<sz; ++i)
				st[i].insert(f[i][x%D[i]]);
			int R=0;
			for(int i=0; i<sz; ++i)
				R=max(R,(*st[i].rbegin())*D[i]);
				printf("%lld\n",R);
		}
	}
	return 0;
}