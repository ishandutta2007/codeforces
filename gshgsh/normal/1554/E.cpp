#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 100001
int T,N,ans[MAXN];vector<int>E[MAXN],Div[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int check(int u,int f,int x)
{
	int sum=0;for(auto v:E[u])if(v!=f){int t=check(v,u,x);if(t==-1)return -1;sum+=t;}sum%=x;
	if(sum&&sum!=x-1)return -1;return sum?0:1;
}
int main()
{
	T=get();FOR(i,MAXN-1,1)for(int j=i;j<MAXN;j+=i)Div[j].push_back(i);
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear(),ans[i]=0;For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
		for(auto i:Div[N-1])if(i>1){if(check(1,0,i)!=-1)ans[i]=1;else ans[i]=0;for(auto j:Div[(N-1)/i])if(j!=1)ans[i]=(ans[i]-ans[i*j]+P)%P;}
		ans[1]=pow(2,N-1);For(i,2,N-1)ans[1]=(ans[1]-ans[i]+P)%P;For(i,1,N)cout<<ans[i]<<" \n"[i==N];
	}
}