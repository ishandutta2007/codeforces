// Problem: C. Minimum Grid Path
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
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
    	int ans=0;
    	for(int i=1; i<=n; i++) a[i]=read(),ans+=a[i];
    	int s=1e10,q=1e18;
    	int ts=0,g=n;
    	int ss=1e10;
    	int tss=0,gg=n;
    	for(int i=1; i<=n; i++) 
    	{
    		ts+=a[i];
    		if(i&1)
    		{
    			--g;
    			s=min(s,a[i]);
    		}
    		else
    		{
    			--gg;
    			ss=min(ss,a[i]);
    		}
    		q=min(q,ts+s*g+ss*gg);
    	}
    	printf("%lld\n",q);
    }
	return 0;
}