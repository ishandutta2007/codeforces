// Problem: A. Array and Peaks
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
int a[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	int m=read();
    	int A=(n-1)/2;
    	if(m>A)
    	{
    		puts("-1");
    	}
    	else
    	{
    		int G=m*2+1;
    		int p=1,q=1;
    		for(int i=1; p<=G; ++i,p+=2,++q)
    		a[p]=q;
    		p=2,q=G-m+1;
    		for(int i=1; p<=G; ++i,p+=2,++q)
    		a[p]=q;
    		for(int i=1; i<=G; ++i) printf("%lld ",a[i]);
    		for(int i=G+1; i<=n; ++i) printf("%lld ",i);
	puts("");
    	}
    }
	return 0;
}