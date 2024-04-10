#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 200001
int T,N,a[MAXN];bool vis[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N)cin>>a[i],vis[i]=0;
		For(j,0,30){bool flag=0;For(i,1,N)if(!((a[i]>>j)&1)){flag=1;break;}if(flag)For(i,1,N)if((a[i]>>j)&1)vis[i]=1;}
		int cnt=0;For(i,1,N)cnt+=!vis[i];if(cnt<2){cout<<0<<endl;continue;}int ans=1ll*cnt*(cnt-1)%P;For(i,1,N-2)ans=1ll*ans*i%P;cout<<ans<<endl;
	}
	return 0;
}