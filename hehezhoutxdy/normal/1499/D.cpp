// Problem: D. The Number of Pairs
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/D
// Memory Limit: 512 MB
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
int F[20000003];
void init()
{
	for(int i=1; i<=20000000; i++) F[i]=1;
	for(int i=2; i<=20000000; ++i) if(F[i]==1)
		for(int j=1; i*j<=20000000; j++) F[i*j]<<=1;
	return ;
}
signed main()
{
	init();
    for(int T=read();T--;)
    {
    	int n=read(),m=read(),x=read();	
    	int X=sqrt(x)+3,ans=0;
    	for(int i=1; i<=X; i++) if(x%i==0)
    	{
    		if(i>(x/i))
    		{
    			continue;
    		}
    		int p=i+m;
    		if(p%n==0)
    		{
    			int t=p/n;
    			//printf("%lld %lld %lld\n",i,t,F[t]);
    			ans+=F[t];
    		}
    		if(i>=(x/i))
    		{
    			continue;
    		}
    		p=x/i+m;
    		if(p%n==0)
    		{
    			int t=p/n;
    			//printf("%lld %lld %lld\n",x/i,t,F[t]);
    			ans+=F[t];
    		}
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}