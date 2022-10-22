// Problem: C. K Integers
// Contest: Codeforces - Codeforces Round #609 (Div. 1)
// URL: https://codeforces.com/contest/1268/problem/C
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
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
struct BIT{
int tree[200003];
void add(int x,int k=1)
{
	while(x<=200000) tree[x]+=k,x+=x&(-x);
	return ;
}
int find(int x)
{
	int r=0;
	while(x) r+=tree[x],x-=x&(-x);
	return r;
}}sc,sv;
int a[10000003],b[1000003];
int F(int x)
{
	if(x&1)
	{
		//1 0 1
		int t=x/2;
		return t*(t+1);
	}
	else
	{
		//3 2 1 0 1 2
		int t=x/2;
		return t*t;
	}
}
signed main()
{
	ll ans=0;
	int n=read();
	for(int i=1; i<=n; ++i) b[a[i]=read()]=i;
	int S=0;
	for(int i=1; i<=n; ++i)
	{
		S+=b[i],sv.add(b[i],b[i]),sc.add(b[i]),ans+=i-sc.find(b[i]);
		int l=1,r=n,res=0,q=(i+1)>>1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(sc.find(mid)>=q) res=mid,r=mid-1;
			else l=mid+1;
		}
		ll o=res*(sc.find(res)*2-i)-sv.find(res)*2+S;
		printf("%lld ",ans+o-F(i));
	}
	return 0;
}