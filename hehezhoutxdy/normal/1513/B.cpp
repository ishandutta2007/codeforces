// Problem: B. AND Sequences
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int p=1e9+7;
int a[1000003];
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i) a[i]=read();
    	sort(a+1,a+n+1);
    	int s=a[2];
    	for(int i=3; i<=n; ++i) s&=a[i];
    	if(s!=a[1])
    	{
    		puts("0");
    		continue;	
    	}
    	int c=0;
    	for(int i=1; i<=n; ++i) if(a[i]==a[1]) ++c;
    	int ans=c*(c-1)%p;
    	for(int i=1; i<=n-2; ++i)  ans=ans*i%p; 
    	printf("%lld\n",ans);
    }
	return 0;
}