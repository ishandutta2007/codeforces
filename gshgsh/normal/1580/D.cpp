#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 4001
int N,M,a[MAXN],ls[MAXN],rs[MAXN],siz[MAXN];ll f[MAXN][MAXN];
int build(int l,int r){if(l>r)return 0;int x=l;For(i,l+1,r)if(a[i]<a[x])x=i;ls[x]=build(l,x-1);rs[x]=build(x+1,r);return x;}
void dfs(int u)
{
	siz[u]=1;if(ls[u])dfs(ls[u]),siz[u]+=siz[ls[u]];if(rs[u])dfs(rs[u]),siz[u]+=siz[rs[u]];
	For(i,0,siz[ls[u]])For(j,0,siz[rs[u]])f[u][i+j]=max(f[u][i+j],f[ls[u]][i]+f[rs[u]][j]-2ll*i*j*a[u]),f[u][i+j+1]=max(f[u][i+j+1],f[ls[u]][i]+f[rs[u]][j]+(M-1ll)*a[u]-2ll*(i+j+i*j)*a[u]);
}
int main(){cin>>N>>M;For(i,1,N)cin>>a[i];int rt=build(1,N);dfs(rt);cout<<f[rt][M]<<'\n';return 0;}