// Problem: C. Add One
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/C
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
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int f[10][200003];
void init()
{
	for(int i=0; i<=9; ++i) f[i][0]=1;
	for(int j=1; j<=200000; ++j)
	{
		for(int i=0; i<9; ++i) f[i][j]=f[i+1][j-1];
		f[9][j]=(f[0][j-1]+f[1][j-1])%p;
	}
	return ;
}
signed main()
{
	init();
    for(int T=read();T--;)
    {
    	int n=read(),m=read();
    	int ans=0;
    	while(n)
    	{
    		int x=n%10;
    		ans+=f[x][m];
    		ans%=p;
    		n/=10;
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}