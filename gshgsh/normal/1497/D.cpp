#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 5001
int T,N,tg[MAXN],a[MAXN];ll f[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>tg[i],f[i]=0;For(i,1,N)cin>>a[i];
		For(i,2,N)FOR(j,i-1,1)if(tg[i]!=tg[j]){int v=abs(a[i]-a[j]);ll x=f[i],y=f[j];f[i]=max(f[i],y+v),f[j]=max(f[j],x+v);}
		ll ans=0;For(i,1,N)ans=max(ans,f[i]);cout<<ans<<endl;
	}
	return 0;
}