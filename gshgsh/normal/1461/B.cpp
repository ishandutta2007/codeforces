#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 501
int T,N,M,a[MAXN][MAXN],sum[MAXN][MAXN];ll ans;
int main()
{
	cin>>T;
	while(T--)
	{
		ans=0;cin>>N>>M;For(i,1,N)For(j,1,M){char c;cin>>c;a[i][j]=c=='*';sum[i][j]=sum[i][j-1]+a[i][j];}
		For(i,1,N)For(j,1,M)if(a[i][j]){ans++;For(k,1,M)if(j-k>=1&&j+k<=M&&i+k<=N&&sum[i+k][j+k]-sum[i+k][j-k-1]==2*k+1)ans++;else break;}
		cout<<ans<<endl;
	}
	return 0;
}