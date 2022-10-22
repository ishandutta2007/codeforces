#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define abs(x) ((x)>0?(x):-(x))
#define INF 0x3fffffff
#define MAXN 201
int T,N,a[MAXN],f[MAXN*2][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sort(a+1,a+N+1);For(i,0,N*2)For(j,0,N)f[i][j]=INF;For(i,0,N)f[i][0]=0;int ans=INF;
		For(i,1,N*2)For(j,1,min(i,N))f[i][j]=min(f[i-1][j],f[i-1][j-1]+abs(i-a[j])),j==N?ans=min(ans,f[i][j]):0;cout<<ans<<endl;
	}
	return 0;
}