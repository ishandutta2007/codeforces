// Problem: B. Repetitions Decoding
// Contest: Codeforces Round #773 (Div. 1)
// URL: https://codeforces.com/contest/1641/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[1000003],ans[1000003];
signed main()
{
	for(int T=read(); T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		reverse(a+1,a+n+1);
		bool flg=0;
		vector<pair<int,int>> vec;
		int index=0;
		vector<int> ans2;
		while(n)
		{
			int x=a[n];
			int j=n-1;
			while(j&&a[j]!=x) --j;
			if(!j)
			{
				puts("-1");
				flg=1;
				break;
			}
			index+=n-j;
			vector<int> tmp;
			for(int i=n-1; i>j; --i)
				tmp.push_back(a[i]),
				vec.push_back(make_pair(index+n-i,a[i]));
			ans2.push_back(n-j),index+=n-j,n=j-1;
			for(int i:tmp) a[++n]=i;
		}
		if(flg) continue;
		printf("%d\n",(int)vec.size());
		for(pair<int,int> i:vec)
			printf("%d %d\n",i.first,i.second);
		printf("%d\n",(int)ans2.size());
		for(int i:ans2)
			printf("%d ",i<<1);
		puts("");
	}
	return 0;
}