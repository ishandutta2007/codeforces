#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define getchar() In[pos++]
#define MAXN 100001
#define B 1000
int N,len[MAXN],*E2[MAXN],now[MAXN];vector<int>E[MAXN];char In[2000010];int pos;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void init(int u,int f){E2[u]=new int[E[u].size()-(u!=1)];for(auto v:E[u])if(v!=f)E2[u][now[u]++]=v,init(v,u);}
int dfs(int u,int f,int k)
{
	int mx=0,mx2=0,ans=0;For(i,0,now[u]-1)if(E2[u][i]!=f){ans+=dfs(E2[u][i],u,k);if(len[E2[u][i]]>mx)mx2=mx,mx=len[E2[u][i]];else mx2=max(mx2,len[E2[u][i]]);}
	if(mx+mx2+1>=k)ans++,len[u]=0;else len[u]=mx+1;return ans;
}
int getmx(int l,int r,int res){while(l<r){int mid=l+r+1>>1;dfs(1,0,mid)==res?l=mid:r=mid-1;}return l;}
int main()
{
	fread(In,1,2000000,stdin);N=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}init(1,0);
	For(i,1,min(N,B))cout<<dfs(1,0,i)<<'\n';for(int l=B+1,r;l<=N;l=r+1){int ans=dfs(1,0,l);if(!ans){For(i,l,N)cout<<"0\n";return 0;}r=getmx(l,N/ans,ans);For(i,l,r)cout<<ans<<'\n';}return 0;
}