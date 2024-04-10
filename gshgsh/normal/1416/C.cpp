#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 300001
int N,a[MAXN],tot=1,son[MAXN*32][2],siz[MAXN*32];ll f[32][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void ins(int x){int u=1;FOR(i,30,0){int c=(x>>i)&1;if(!son[u][c])son[u][c]=++tot;f[i][c]+=siz[son[u][c^1]];u=son[u][c];siz[u]++;}}
int main(){N=get();For(i,1,N)a[i]=get(),ins(a[i]);ll ans1=0;int ans2=0;FOR(i,30,0){if(f[i][0]>f[i][1])ans2^=1<<i;ans1+=min(f[i][0],f[i][1]);}cout<<ans1<<' '<<ans2<<endl;return 0;}