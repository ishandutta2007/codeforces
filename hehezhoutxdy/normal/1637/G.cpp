// Problem: CF1637G Birthday
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1637G
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<pair<int,int>> ans;
int c[100003],lim;
void op(int x,int y)
{
	if(x>y) swap(x,y);
	--c[x],--c[y],++c[y-x],++c[x+y],
	ans.push_back(make_pair(x,y));
	return ;
}
signed main()
{
	for(int T=read(); T--;)
	{
		int n=read(),lim=1;
		if(n==2)
		{
			puts("-1");
			continue;
		}
		ans.clear();
		for(int i=1; i<=n; ++i) c[i]=1;
		while(lim<n) lim<<=1;
		for(int i=1; i<(lim>>1); i<<=1)
			for(int j=(lim>>1); j>=1; j>>=1)
				for(int k=(j<<1)-i; k>j; k-=(i<<1))
					while(c[k]&&c[(j<<1)-k]) 
						op(k,(j<<1)-k);
		for(int i=1;i<lim;i<<=1)
			while(c[i]>=2) op(i,i);
		for(int i=1;i<lim;i<<=1)
		{
			while(c[i]>=2) op(i,i);
			if(c[i]) op(i,0); 
			while(c[i]>=2) op(i,i); 
		}
		while(c[0]) op(lim,0);
		assert(c[lim]==n);
		c[lim]=0;
		printf("%d\n",(int)ans.size());
		for(auto i:ans) printf("%d %d\n",i.first,i.second);
	}
	return 0;
}