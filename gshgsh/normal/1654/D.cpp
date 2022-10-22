#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int T,N,val[MAXN],tot,prm[MAXN],Div[MAXN],cnt[MAXN],mx[MAXN];bool Not[MAXN];vector<pair<int,pair<int,int>>>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void add(int x){while(x>1)cnt[Div[x]]++,mx[Div[x]]=max(mx[Div[x]],cnt[Div[x]]),x/=Div[x];}
void era(int x){while(x>1)cnt[Div[x]]--,x/=Div[x];}
void dfs(int u,int f)
{
	for(auto v:E[u])if(v.first!=f)
	{
		int x=v.second.first,y=v.second.second;era(y);add(x);val[v.first]=1ll*val[u]*y%P*pow(x,P-2)%P;
		dfs(v.first,u);era(x);add(y);
	}
}
int main()
{
	N=MAXN-1;For(i,2,N){if(!Not[i])prm[++tot]=i,Div[i]=i;for(int j=1;j<=tot&&i*prm[j]<=N;j++){Not[i*prm[j]]=1;Div[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear();For(i,1,N-1){int u=get(),v=get(),x=get(),y=get();E[u].push_back({v,{x,y}});E[v].push_back({u,{y,x}});}
		For(i,1,N)cnt[i]=mx[i]=0;val[1]=1;dfs(1,0);int sum=0;For(i,1,N)sum=(sum+val[i])%P;
		For(i,1,N)sum=1ll*sum*pow(i,mx[i])%P;cout<<sum<<'\n';
	}
}