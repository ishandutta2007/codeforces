// Problem: B. The Cake Is a Lie
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/B
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
bitset<10001> bs[101][101];
signed main()
{
	bs[1][1][0]=1;
	for(int i=1; i<=100; ++i)
	for(int j=1; j<=100; ++j)
	if(i+j>1)
	{
		if(i>1)bs[i][j]|=bs[i-1][j]<<j;
		if(j>1) bs[i][j]|=bs[i][j-1]<<i;
	}
    for(int T=read();T--;)
    {
    	int n=read(),m=read(),k=read();
    	if(bs[n][m][k]) puts("YES");
    	else puts("NO");
    }
	return 0;
}