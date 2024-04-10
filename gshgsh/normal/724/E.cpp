#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 10001
int N,c,a[MAXN],b[MAXN];ll f[2][MAXN];
int main()
{
	cin>>N>>c;For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i];
	For(i,1,N)For(j,0,i)f[i&1][j]=min(j<i?f[i-1&1][j]+1ll*c*j+a[i]:INF,j?f[i-1&1][j-1]+b[i]:INF);
	ll ans=f[N&1][0];For(i,1,N)ans=min(ans,f[N&1][i]);cout<<ans<<endl;return 0;
}