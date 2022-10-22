// Problem: B. Binary Removals
// Contest: Codeforces - Educational Codeforces Round 106 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1499/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
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
char s[1000003];
int f[1000003];
int g[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	scanf("%s",s+1);
    	int n=strlen(s+1);
    	for(int i=1; i<=n; i++) f[i]=g[i]=-1;
    	f[0]=0,g[n+1]=n+1;
    	s[0]='0',s[n+1]='1';
    	bool FF=0,GG=0;
    	for(int i=1; i<=n; i++) if(s[i]=='0') FF=1; else GG=1;
    	for(int i=1; i<=n; i++) if(s[i]=='1')
    	{
    		if(s[i-1]=='1')
    		{
    			break;
    		} 
    		f[i]=i;
    	}
    	else f[i]=f[i-1];
    	for(int i=n; i>=1; i--) if(s[i]=='0')
    	{
    		if(s[i+1]=='0')
    		{
    			break;
    		} 
    		g[i]=i;
    	}else g[i]=g[i+1];
    	bool F=0;
    	for(int i=0; i<=n; i++) if(f[i]!=-1&&g[i+1]!=-1)
    	{
    		if(f[i]+1<g[i+1]) F=1;
    	}
    	if(F) puts("YES");
    	else puts("NO");
    }
	return 0;
}