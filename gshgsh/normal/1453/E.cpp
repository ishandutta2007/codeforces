#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define MAXN 200001
int T,N,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
int dfs(int u,int f){vector<int>v;FOR(i,u,f)v.push_back(dfs(to[i],u));if(v.empty())return 1;sort(v.begin(),v.end());if(v.size()>1)ans=max(ans,u==1?max(v[v.size()-1],v[v.size()-2]+1):v[v.size()-1]+1);ans=max(ans,v[0]);return v[0]+1;}
int main(){T=get();while(T--){N=get();ans=cnt=0;For(i,1,N)fst[i]=0;For(i,1,N-1)add(get(),get());dfs(1,0);put(ans),putchar('\n');}return 0;}