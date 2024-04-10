// Problem: B. Once in a casino
// Contest: Codeforces - Z Flip #2
// URL: https://codeforces.com/gym/374761/problem/B
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
#define int long long
inline int read(){
   int a=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') a=a*10+ch-'0',ch=getchar();
   return a*w;
}
char a[1000003],b[1000003];
int sum=0;
void move(int x,int y)
{
	printf("%lld %lld\n",x-1,y);
	if(y==1)
	{
		assert(a[x-1]!='9'),assert(a[x]!='9');
		++a[x-1],++a[x];
	}
	else
	{
		assert(a[x-1]!='0'),assert(a[x]!='0');
		--a[x-1],--a[x];
	}
	if(++sum==100000) exit(0);
	return ;
}
signed main()
{
	int n=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	int sa=0,sb=0,sc=0;
	for(int i=1; i<=n; ++i) 
		if(i&1) sa+=a[i]-48; else sb+=a[i]-48;
	for(int i=1; i<=n; ++i) 
		if(i&1) sa-=b[i]-48; else sb-=b[i]-48;
	if(sa-sb) puts("-1"),exit(0);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(i&1) sc+=a[i]-48; else sc-=a[i]-48;
		if(i&1) sc-=b[i]-48; else sc+=b[i]-48;
		ans+=abs(sc);
	}
	printf("%lld\n",ans);
	for(int i=n; i>=1; --i)
	{
		while(a[i]<b[i])
		{
			//target: ++a[i]
			//another target: --a[i-1];
			int j=i;
			while(1)
			{
				if((i-j)&1)
				{
					//need down
					if(a[j-1]=='0') --j;
					else break;
				}
				else
				{
					//need up
					if(a[j-1]=='9') --j;
					else break;
				}
			}
			for(int t=j; t<=i; ++t)
				if((i-t)&1) move(t,-1);
				else move(t,1);
		}
		while(a[i]>b[i])
		{
			int j=i;
			while(1)
			{
				if((i-j)&1)
				{
					if(a[j-1]=='9') --j;
					else break;
				}
				else
				{
					if(a[j-1]=='0') --j;
					else break;
				}
			}
			for(int t=j; t<=i; ++t)
				if((i-t)&1) move(t,1);
				else move(t,-1);
		}
	}
	return 0;
}