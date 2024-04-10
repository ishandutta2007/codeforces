// Problem: A. Tit for Tat
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/A
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
    	int n=read(),k=read();
    	for(int i=1; i<=n; ++i) a[i]=read();
    	while(k--)
    	{
    		int A=-1,B=-1;
    		for(int i=1; i<=n; ++i) if(a[i]>=1) 
    		{
    			A=i;
    			break;
    		}
    		if(A!=-1)
    		{
    			--a[A],++a[n];
    		}
    		else break;
    	}
    	for(int i=1; i<=n; ++i)
    	printf("%lld ",a[i]);
    	puts("");
    }
	return 0;
}