#include<iostream>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define F first
#define S second
#define MAXN 100001
int T,N,a[MAXN],deg[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;ll ans=0;For(i,1,N)cin>>a[i],deg[i]=0,ans+=a[i];For(i,1,N-1){int u,v;cin>>u>>v;deg[u]++,deg[v]++;}
		priority_queue<Pair>q;For(i,1,N)if(deg[i]>1)q.push(mp(a[i],i));cout<<ans<<' ';
		For(i,2,N-1){int u=q.top().second;q.pop();ans+=a[u];cout<<ans<<' ';deg[u]--;if(deg[u]>1)q.push(mp(a[u],u));}cout<<endl; 
	}
	return 0;
}