#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN];bool vis[MAXN];ll ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	For(i,1,N)
	{
		if(!q.empty()&&q.top().first<a[i]){pair<int,int>x=q.top();q.pop();ans+=a[i]-x.first;vis[i]=1;if(vis[x.second])q.push({a[x.second],x.second}),vis[x.second]=0;}
		q.push({a[i],i});
	}
	cout<<ans<<'\n';return 0;
}