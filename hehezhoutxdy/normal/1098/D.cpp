// Problem: C. Eels
// Contest: Codeforces - Z Flip #4
// URL: https://codeforces.com/gym/376319/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
multiset<int> st[53];
int sum[53];
signed main()
{
	int sz=0;
	char ch;
	for(int T=read(),v; T--;)
	{
		ch=getchar();
		while(ch!='+'&&ch!='-') ch=getchar();
		v=read();
		int o=0;
		while((1<<(o+1))<=v) ++o;
		if(ch=='-') --sz,sum[o]-=v,st[o].erase(st[o].find(v));
		else ++sz,sum[o]+=v,st[o].insert(v);
		int S=sz;
		for(int i=0,tot=0; i<32; tot+=sum[i],++i) 
			if(!st[i].empty()&&(tot*2)<*st[i].begin())
				--S;
		printf("%lld\n",S);
	}
	return 0;
}