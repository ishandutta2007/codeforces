#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define lowbit(x) x&-x
#define MAXN 2000001
int N,M,x[MAXN],c[MAXN],y[MAXN],lx[MAXN],rx[MAXN];vector<pair<int,int>>val[MAXN],que[MAXN];
void upd(int x,int v){for(int i=x+1;i<=1000001;i+=lowbit(i))c[i]+=v;}int ask(int x){ll ans=0;for(int i=x+1;i;i-=lowbit(i))ans+=c[i];return ans;}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N)y[i]=get(),lx[i]=get(),rx[i]=get(),val[lx[i]].push_back({y[i],1}),val[rx[i]+1].push_back({y[i],-1});
	ll ans=1;For(i,1,N)if(!lx[i]&&rx[i]==1000000)ans++;val[0].push_back({0,1}),val[0].push_back({1000000,1});For(i,1,M){int x=get(),l=get(),r=get();que[x].push_back({l,r});}
	For(i,0,1000000){for(auto j:val[i])upd(j.first,j.second);for(auto j:que[i])ans+=max(ask(j.second)-ask(j.first-1)-1,0);}cout<<ans<<'\n';return 0;
}