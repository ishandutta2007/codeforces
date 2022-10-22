#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN],h[MAXN],f[MAXN],val[MAXN];vector<int>E[MAXN],id[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();queue<int>q;For(i,1,N)a[i]=get();For(i,1,N)if(a[i])q.push(i);else h[i]=-1;For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	while(!q.empty()){int u=q.front();q.pop();for(auto v:E[u])if(h[v]==-1)h[v]=h[u]+1,q.push(v);}
	For(i,1,N){bool flag=0;for(auto j:E[i])flag|=h[i]==h[j];if(flag)id[h[i]].push_back(i);}For(i,1,N)val[i]=-1;
	For(i,0,N)if(!id[i].empty())
	{
		deque<int>q;For(j,1,N)f[j]=1e5;for(auto j:id[i])f[j]=i+1,q.push_back(j);
		while(!q.empty())
		{
			int u=q.front();q.pop_front();
			for(auto v:E[u])if((h[u]==h[v]||(h[u]<h[v]&&f[u]==h[u]))&&f[v]>f[u]+1)f[v]=f[u]+1,q.push_back(v);else if(h[u]<h[v]&&f[u]>h[u]&&f[v]>f[u])f[v]=f[u],q.push_front(v);
		}
		For(j,1,N)if(f[j]==h[j]&&val[j]==-1)val[j]=i;
	}
	For(i,1,N)if(val[i]==-1)val[i]=h[i];For(i,1,N)cout<<h[i]*2-val[i]<<" \n"[i==N];
}