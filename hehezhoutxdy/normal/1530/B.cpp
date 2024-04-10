// Problem: B. Putting Plates
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.com/contest/1530/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
int f[103][103];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		int cnt=0;
		f[1][1]=1;cnt=0;
		for(int i=3; i+1<m; ++i) f[1][i]=(++cnt)&1;
		f[1][m]=1;cnt=0;
		for(int j=3; j+1<n; ++j) f[j][m]=(++cnt)&1;
		f[n][m]=1;cnt=0;
		for(int i=m-2; i>2; --i) f[n][i]=(++cnt)&1;
		f[n][1]=1;cnt=0;
		for(int j=n-2; j>2; --j) f[j][1]=(++cnt)&1;
		f[2][1]=((++cnt)&1)&&(f[1][1]==0);
		for(int i=1; i<=n; ++i,puts(""))
			for(int j=1; j<=m; ++j)
				if(i!=1&&i!=n&&j!=1&&j!=m) printf("0");
				else if(i==2||j==2||i==n-1||j==m-1)printf("0");
				else if(f[i][j]) printf("1");
				else printf("0");
				puts("");
	}
	return 0;
}