#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,K,a[MAXN],sum[MAXN],sum2[MAXN];vector<int>E[MAXN];bool is[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){sum[u]=a[u];for(auto v:E[u])if(v!=f)dfs(v,u),sum[u]^=sum[v];}
void dfs2(int u,int f,int lst){if(sum[u]==sum[1])is[lst]=0,lst=u,is[u]=1;for(auto v:E[u])if(v!=f)dfs2(v,u,lst);}
bool check1(){For(i,1,N)is[i]=0;dfs2(1,0,0);int cnt=0;For(i,2,N)cnt+=is[i];return cnt>=2;}
void dfs3(int u,int f){sum2[u]=is[u];for(auto v:E[u])if(v!=f)dfs3(v,u),sum2[u]+=sum2[v];}
bool check2(){dfs3(1,0);For(i,1,N)if(sum2[i]&&!sum[i])return 1;return 0;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get(),E[i].clear();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}dfs(1,0);
		if(sum[1]){if(K==2){cout<<"NO\n";continue;}cout<<(check1()||check2()?"YES\n":"NO\n");continue;}cout<<"YES\n";
	}
	return 0;
}