#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,M,vis[MAXN];
int main()
{
	cin>>N>>M;For(i,1,M)vis[i]=-1;
	For(i,1,N)
	{
		ll opt,x,y;cin>>opt>>x>>y;
		if(opt==1){FOR(j,M,0)if(vis[j]!=-1){int now=j;For(k,1,y){now=now+(x+99999)/100000;if(now<=M&&vis[now]==-1)vis[now]=i;else break;}}}
		else FOR(j,M,0)if(vis[j]!=-1){ll now=j;For(k,1,y){now=(now*x+99999)/100000;if(now<=M&&vis[now]==-1)vis[now]=i;else break;}}
	}
	For(i,1,M)cout<<vis[i]<<' ';return 0;
}