#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 200001
int T,N,p,a[MAXN];Pair b[MAXN];bool vis[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N>>p;For(i,1,N)cin>>a[i],b[i]={a[i],i},vis[i]=0;sort(b+1,b+N+1);
		ll ans=0;For(i,1,N){if(b[i].F>=p)break;int now=b[i].F,j=b[i].S;while(j>1&&!vis[j-1]&&a[j-1]%a[b[i].S]==0)vis[--j]=1,ans+=now;j=b[i].S;while(j<N&&!vis[j]&&a[j+1]%a[b[i].S]==0)vis[j++]=1,ans+=now;}
		For(i,1,N-1)if(!vis[i])ans+=p;cout<<ans<<endl;
	}
	return 0;
}