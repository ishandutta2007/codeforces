#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
#define MAXM 1000001
int N,ans,dep[MAXN],tot,id[MAXN],pos[MAXN],len[MAXN];vector<int>E[MAXN];bool cmp(int x,int y){return len[x]>len[y];}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void dfs1(int u){int l=0;for(auto v:E[u])dep[v]=dep[u]+1,dfs1(v),l=max(l,len[v]);sort(E[u].begin(),E[u].end(),cmp);len[u]=l+1;}
void dfs2(int u){id[tot]=u,pos[u]=tot++;int M=E[u].size();FOR(i,M-1,0)dfs2(E[u][i]);}
int main(){N=get();For(i,1,N-1)E[get()].push_back(i);dfs1(0);dfs2(0);For(i,0,N-1)cout<<id[i]<<' ';cout<<endl;For(i,1,N-1)ans+=dep[id[i-1]]-dep[id[i]]+1;cout<<ans<<endl;For(i,1,N-1)For(j,1,dep[id[i-1]]-dep[id[i]]+1)cout<<id[i]<<' ';cout<<endl;return 0;}