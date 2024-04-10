#include<iostream>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 300001
int T,N,K,a[MAXN],h[MAXN];bool vis[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>K;priority_queue<Pair>q;For(i,1,N)cin>>a[i],q.push(mp(a[i],i)),vis[i]=0;vis[0]=vis[N+1]=0;bool flag=1;
		while(!q.empty())
		{
			int u=q.top().S;q.pop();h[u]=a[u];if(vis[u-1])h[u]=max(h[u],h[u-1]-K+1);if(vis[u+1])h[u]=max(h[u],h[u+1]-K+1);
			if(h[u]-a[u]>=K){flag=0;break;}vis[u]=1;
		}
		cout<<(flag&&h[1]==a[1]&&h[N]==a[N]?"YES\n":"NO\n");
	}
	return 0;
}