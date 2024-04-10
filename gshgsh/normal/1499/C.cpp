#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],f[MAXN];ll sum[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i];sum[1]=f[1]=a[1],sum[2]=f[2]=a[2];ll ans=1ll*f[1]*N+1ll*f[2]*N;
		For(i,3,N)
		{
			f[i]=min(a[i],f[i-2]),sum[i]=sum[i-2]+a[i];
			ans=min(ans,1ll*f[i]*(N-(i-1)/2)+sum[i]-f[i]+1ll*f[i-1]*(N-(i-2)/2)+sum[i-1]-f[i-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}