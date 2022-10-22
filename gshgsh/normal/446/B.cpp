#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
#define MAXM 1000001
int N,M,K,p,a[MAXN][MAXN];ll f[MAXM],g[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get(),K=get(),p=get();For(i,1,N)For(j,1,M)a[i][j]=get();
	ll line=0,row=0;priority_queue<ll>mx1,mx2;For(i,1,N){int sum=0;For(j,1,M)sum+=a[i][j];mx1.push(sum);}For(j,1,M){int sum=0;For(i,1,N)sum+=a[i][j];mx2.push(sum);}
	For(i,1,K){ll x=mx1.top();mx1.pop();f[i]=f[i-1]+x;mx1.push(x-p*M);}For(i,1,K){ll x=mx2.top();mx2.pop();g[i]=g[i-1]+x;mx2.push(x-p*N);}
	ll ans=-1e18;For(i,0,K)ans=max(ans,f[i]+g[K-i]-1ll*i*(K-i)*p);cout<<ans<<'\n';return 0;
}