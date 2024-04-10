// Problem: C. Berland Regional
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/C
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
int op[1000003];
vector<int> v[1000003];
int ans[1000003];
bool cmp(int x,int y)
{
	return x<y;
}
int A[1000003];
signed main()
{
    for(int T=read();T--;)
    {
    	int n=read();
    	for(int i=1; i<=n; ++i) op[i]=read(),ans[i]=0;
    	for(int i=1; i<=n; ++i) a[i]=read();
    	for(int i=1; i<=n; ++i) v[i].clear();
    	for(int i=1; i<=n; ++i) v[op[i]].push_back(a[i]);
    	for(int i=1; i<=n; ++i) sort(v[i].begin(),v[i].end(),cmp);
    	for(int i=1; i<=n; ++i)
    	{
    		int s=v[i].size(),c=0;
    		for(int i=1; i<=s; ++i) A[i]=0;
    		for(int j=1; j<=s; ++j) A[j]=A[j-1]+v[i][j-1],c+=v[i][j-1];
    		ans[1]+=c,ans[s+1]-=c;
    		for(int j=1; j<=s; ++j) ans[j]-=A[s%j],ans[j+1]+=A[s%j];
    	}
    	int C=0;
    	for(int i=1; i<=n; ++i) 
    	{
    		C+=ans[i];
    		printf("%lld ",C);
    	}
    	puts("");
    }
	return 0;
}