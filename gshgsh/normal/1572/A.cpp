#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,deg[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear();For(i,1,N){deg[i]=get();For(j,1,deg[i])E[get()].push_back(i);}
		set<int>q;For(i,1,N)if(!deg[i])q.insert(i);int cnt=0,lst=0,ans=1;q.insert(N+1);
		while(*q.begin()!=N+1){int u=*q.lower_bound(lst+1);if(u==N+1)ans++,u=*q.begin();lst=u;q.erase(u);cnt++;for(auto v:E[u])if(!(--deg[v]))q.insert(v);}
		if(cnt<N){cout<<"-1\n";continue;}cout<<ans<<'\n';
	}
}