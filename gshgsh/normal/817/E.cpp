#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,tot=1,son[MAXN*27][2],siz[MAXN*27];
void ins(int x){int u=1;FOR(i,26,0){int s=(x>>i)&1;if(!son[u][s])son[u][s]=++tot;u=son[u][s];siz[u]++;}}void del(int x){int u=1;FOR(i,26,0)u=son[u][(x>>i)&1],siz[u]--;}
int ask(int x,int y){int u=1,ans=0;FOR(i,26,0)if((y>>i)&1)ans+=siz[son[u][(x>>i)&1]],u=son[u][((x>>i)&1)^1];else u=son[u][(x>>i)&1];return ans;}
int main(){cin>>N;For(i,1,N){int opt,x,y;cin>>opt>>x;opt<=2?opt&1?ins(x):del(x),0:(cin>>y,cout<<ask(x,y)<<endl,0);}return 0;}