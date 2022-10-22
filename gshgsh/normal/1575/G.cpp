#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
int N,a[MAXN],tot,prm[MAXN],phi[MAXN],sum[MAXN],c[MAXN],s[MAXN];bool Not[MAXN];vector<int>Div[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int solve(int x){vector<int>val;For(i,1,N/x)c[a[i*x]]++;For(i,1,N/x)if(c[a[i*x]]){for(auto j:Div[a[i*x]])s[j]+=c[a[i*x]],val.push_back(j);c[a[i*x]]=0;}int ans=0;for(auto i:val)ans=(ans+1ll*phi[i]*phi[x]*s[i]*s[i])%P,s[i]=0;return ans;}
int main()
{
	N=get();For(i,1,N)a[i]=get();phi[1]=1;For(i,2,MAXN-1){if(!Not[i])prm[++tot]=i,phi[i]=i-1;for(int j=1;j<=tot&&i*prm[j]<MAXN;j++){Not[i*prm[j]]=1;if(i%prm[j]==0){phi[i*prm[j]]=phi[i]*prm[j];break;}phi[i*prm[j]]=phi[i]*(prm[j]-1);}}
	For(i,1,MAXN-1)for(int j=i;j<MAXN;j+=i)Div[j].push_back(i);For(i,1,MAXN-1)sum[i]=(sum[i-1]+phi[i])%P;
	int ans=0;For(i,1,N)ans=(ans+solve(i))%P;cout<<ans<<'\n';return 0;
}