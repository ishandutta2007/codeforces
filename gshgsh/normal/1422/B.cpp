#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,M,a[MAXN][MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>M;For(i,1,N)For(j,1,M)cin>>a[i][j];
		ll ans=0;For(i,1,N/2)For(j,1,M/2){int b[4];b[0]=a[i][j],b[1]=a[i][M+1-j],b[2]=a[N+1-i][j],b[3]=a[N+1-i][M+1-j];sort(b,b+4);ans+=b[2]+b[3]-b[0]-b[1];}
		if(N&1)For(i,1,M/2)ans+=max(a[N+1>>1][i]-a[N+1>>1][M+1-i],a[N+1>>1][M+1-i]-a[N+1>>1][i]);
		if(M&1)For(i,1,N/2)ans+=max(a[i][M+1>>1]-a[N+1-i][M+1>>1],a[N+1-i][M+1>>1]-a[i][M+1>>1]);cout<<ans<<endl;
	}
	return 0;
}