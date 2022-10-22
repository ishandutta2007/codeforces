#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
#define ll long long 
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 27
int N,K,a[MAXN],cnt;ll S,fc[MAXN],ans;unordered_map<ll,int>res[MAXN];
void dfs1(int x,ll sum,int tot){if(x==N/2+1){res[tot][sum]++;return;}dfs1(x+1,sum,tot);if(sum+a[x]<=S)dfs1(x+1,sum+a[x],tot);if(tot<K&&a[x]<=cnt&&sum+fc[a[x]]<=S)dfs1(x+1,sum+fc[a[x]],tot+1);}
void dfs2(int x,ll sum,int tot){if(x==N/2){For(i,0,K-tot)ans+=res[i][S-sum];return;}dfs2(x-1,sum,tot);if(sum+a[x]<=S)dfs2(x-1,sum+a[x],tot);if(tot<K&&a[x]<=cnt&&sum+fc[a[x]]<=S)dfs2(x-1,sum+fc[a[x]],tot+1);}
int main(){cin>>N>>K>>S;fc[0]=1;while(fc[cnt]<=S)fc[cnt]=fc[cnt]*(++cnt);For(i,1,N)cin>>a[i];dfs1(1,0,0);dfs2(N,0,0);cout<<ans<<endl;return 0;}