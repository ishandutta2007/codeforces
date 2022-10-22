#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N;ll K;bool vis[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K,K--;if(N<=62&&K>=(1ll<<N-1)){cout<<-1<<endl;continue;}
		For(i,1,N)vis[i]=0;for(int i=0;1ll<<i<=K;i++)if((K>>i)&1)vis[N-i-1]=1;
		int now=1;For(i,1,N)if(!vis[i]){FOR(j,i,now)cout<<j<<' ';now=i+1;}cout<<endl;
	}
	return 0;
}