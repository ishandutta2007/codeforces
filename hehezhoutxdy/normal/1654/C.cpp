// Problem: C. Alice and the Cake
// Contest: Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/C
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),s=0;
		for(int i=1; i<=n; ++i) a[i]=read(),s+=a[i];
		sort(a+1,a+n+1);
		multiset<int> st;
		st.insert(s);
		int f=1;
		for(int i=n; i>=1; --i)
		{
			while(st.find(a[i])==st.end())
			{
				if(st.empty()||*st.rbegin()<a[i]) {f=0;break;}
				else 
				{
					int A=*st.rbegin();
					assert(A>1);
					st.erase(st.find(*st.rbegin()));
					st.insert(A>>1),st.insert((A+1)>>1);
				}
			}
			if(f) st.erase(st.find(a[i])); else break;
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}