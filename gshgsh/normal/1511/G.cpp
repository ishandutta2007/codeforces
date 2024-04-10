#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1048576
int N,M,Q,K,a[MAXN],f[MAXN][20],g[MAXN][20];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();while(1<<K+1<=M)K++;For(i,1,N)a[get()]^=1;For(i,1,M)g[i][0]=a[i];Q=get();
	For(k,1,K)For(i,1,M-(1<<k)+1)f[i][k]=(f[i][k-1]^f[i+(1<<k-1)][k-1])|(g[i+(1<<k-1)][k-1]&1)<<k-1,g[i][k]=g[i][k-1]^g[i+(1<<k-1)][k-1];
	while(Q--){int l=get(),r=get(),ans=0,sum=0;FOR(i,K,0)if(l+(1<<i)-1<=r)ans^=f[l][i]^g[l][i]*sum,sum|=1<<i,l+=1<<i;cout<<(ans?'A':'B');}cout<<'\n';
}