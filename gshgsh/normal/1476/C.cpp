#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],b[MAXN],c[MAXN];ll f[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>c[i];For(i,1,N)cin>>a[i];For(i,1,N)cin>>b[i],a[i]<b[i]?swap(a[i],b[i]),0:0;
		ll ans=0;For(i,2,N)a[i]!=b[i]?f[i]=max(a[i]-b[i]+0ll,f[i-1]-a[i]+b[i])+c[i]+1:f[i]=c[i]+1,ans=max(ans,f[i]);cout<<ans<<endl;
	}
	return 0;
}