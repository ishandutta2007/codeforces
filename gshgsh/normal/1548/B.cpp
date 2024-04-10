#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N;ll a[MAXN],b[MAXN],st[MAXN][20];ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
ll get(){ll x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
ll ask(int l,int r){int k=log2(r-l+1);return GCD(st[l][k],st[r-(1<<k)+1][k]);}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,1,N-1)b[i]=abs(a[i]-a[i+1]);For(i,1,N-1)st[i][0]=b[i];
		for(int j=1;(1<<j)<=N-1;j++)For(i,1,N-(1<<j))st[i][j]=GCD(st[i][j-1],st[i+(1<<j-1)][j-1]);
		int r=1,ans=1;ll now=b[1];For(i,1,N-1){r=max(r,i);now=ask(i,r);while(r<N-1&&GCD(now,b[r+1])>1)r++,now=GCD(now,b[r]);if(now>1)ans=max(ans,r-i+2);}
		cout<<ans<<'\n';
	}
	return 0;
}