#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 2520
#define MAXN 20
#define MAXM 3000
int T;ll l,r,f[MAXN][1<<9][MAXM];
ll dfs(int pos,int now,int sum)
{
	if(pos==1){For(i,1,9)if(now&(1<<i-1)&&sum%i)return 0;return 1;}if(f[pos][now][sum]!=-1)return f[pos][now][sum];
	f[pos][now][sum]=dfs(pos-1,now,sum*10%P);For(i,1,9)f[pos][now][sum]+=dfs(pos-1,now|(1<<i-1),(sum*10+i)%P);return f[pos][now][sum];
}
ll sol(ll x)
{
	int cnt=0,tmp[MAXN],sum=0,now=0;ll ans=0;while(x)tmp[++cnt]=x%10,x/=10;
	FOR(i,cnt,1){if(tmp[i])ans+=dfs(i,now,sum*10%P);For(j,1,tmp[i]-1)ans+=dfs(i,now|(1<<j-1),(sum*10+j)%P);sum=(sum*10+tmp[i])%P,tmp[i]?now|=1<<tmp[i]-1:0;}return ans;
}
int main(){memset(f,-1,sizeof(f));cin>>T;while(T--){cin>>l>>r;cout<<sol(r+1)-sol(l)<<endl;}return 0;}