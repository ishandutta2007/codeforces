#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 5001
int N,a[MAXN],b[MAXN];ll f[MAXN][MAXN],ans;
int main()
{
	cin>>N;For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i];For(i,1,N)ans+=1ll*a[i]*b[i];For(i,1,N)f[i][i]=f[i][i-1]=ans;
	For(l,1,N-1)For(i,1,N-l){int j=i+l;ans=max(ans,f[i][j]=f[i+1][j-1]-1ll*a[i]*b[i]-1ll*a[j]*b[j]+1ll*a[i]*b[j]+1ll*a[j]*b[i]);}cout<<ans<<endl;return 0;
}