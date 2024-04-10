#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<16
int T,N,p[MAXN],q[MAXN],ans[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int x){For(i,0,4)if((1<<i)==x)return 1;return 0;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,0,(1<<N)-1)E[i].clear(),q[i]=-1,ans[i]=0;For(i,1,N*(1<<N-1)){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
		queue<int>Q;q[0]=0;For(i,0,E[0].size()-1)q[E[0][i]]=1<<i,Q.push(E[0][i]);
		while(!Q.empty()){int u=Q.front();Q.pop();for(auto v:E[u])if(q[v]==-1){q[v]=0;for(auto w:E[v])if(q[w]!=-1)q[v]|=q[w];Q.push(v);}}
		For(i,0,(1<<N)-1)p[q[i]]=i;For(i,0,(1<<N)-1)cout<<p[i]<<" \n"[i==(1<<N)-1];
		if(!check(N)){cout<<"-1\n";continue;}For(i,0,(1<<N)-1)For(j,0,N-1)if(i>>j&1)ans[i]^=j;
		For(i,0,(1<<N)-1)cout<<ans[q[i]]<<" \n"[i==(1<<N)-1];
	}
}