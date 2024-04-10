#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 3001
int N,K,M[MAXN];vector<ll>a[MAXN];ll f[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void solve(int l,int r)
{
	if(l==r){For(i,0,min(K,M[l]))ans=max(ans,a[l][i]+f[K-i]);return;}
	int mid=l+r>>1;vector<ll>g(K+1);For(i,0,K)g[i]=f[i];For(i,l,mid)FOR(j,K,M[i])f[j]=max(f[j],f[j-M[i]]+a[i][M[i]]);solve(mid+1,r);
	For(i,0,K)f[i]=g[i];For(i,mid+1,r)FOR(j,K,M[i])f[j]=max(f[j],f[j-M[i]]+a[i][M[i]]);solve(l,mid);For(i,0,K)f[i]=g[i];
}
int main()
{
	N=get(),K=get();For(i,1,N){M[i]=get();a[i].resize(M[i]+1);For(j,1,M[i])a[i][j]=a[i][j-1]+get();}
	solve(1,N);cout<<ans<<endl;return 0;
}