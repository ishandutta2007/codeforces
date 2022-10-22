#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,M,cnt[20],val[MAXN*19];bool vis[MAXN];
int main()
{
	cin>>N>>M;ll ans=1ll*(N-1)*M+1;For(i,2,N)if(!vis[i]){int tot=0;ll x=i;while(x<=N)tot++,vis[x]=1,x*=i;cnt[tot]++;}
	For(i,1,19){For(j,1,M)val[i*j]++;For(j,1,M*i)if(val[j])ans-=cnt[i]*(val[j]-1);}cout<<ans<<'\n';return 0;
}