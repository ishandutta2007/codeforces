// Problem: E. Permutation Shift
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
set<int> ANS;
void print()
{
	printf("%lld ",(int)ANS.size());
	for(int A:ANS) printf("%lld ",A);
	puts("");
}
int a[1000003],A[1000003],c[1000003];
bool f[1000003];
int n,m;
void solve(int x)
{
	for(int i=1; i<=n; ++i) A[i]=a[(i+n+n-x-1)%n+1],f[i]=0;
	int ans=n;
	for(int i=1; i<=n; ++i) if(!f[i])
	{
		--ans;
		int t=i;
		while(1)
		{
			if(f[t]) break;
			f[t]=1,t=A[t];
		}
	}
	if(ans<=m) ANS.insert(x);
	return ;
}
signed main()
{
	for(int T=read();T--;)
	{
		ANS.clear();
		n=read(),m=read();
		for(int i=1; i<=n; ++i) a[read()]=i,c[i]=0;
		for(int i=1; i<=n; ++i) ++c[(n+a[i]-i)%n];
		for(int i=0; i<n; ++i) if(c[i]>=n/3) solve(i);
		print();
	}
	return 0;
}