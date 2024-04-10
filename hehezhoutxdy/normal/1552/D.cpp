// Problem: D. Array Differentiation
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int a[13],b[13];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=0; i<n; ++i) b[i]=a[i]=abs(read());
		int N=1,f=0;
		for(int j=0; j<n; ++j) N*=3;
			for(int j=1; j<N; ++j)
			{
				int Q=j,s=0;
				for(int k=0; k<n; ++k)
				{
					if(Q%3==1) s-=b[k];
					else if(Q%3==2)s+=b[k];
					Q/=3;
				}
				if(s==0) {f=1;break;}
			}
		if(f) puts("YES");
		else puts("NO");
	}
	return 0;
}