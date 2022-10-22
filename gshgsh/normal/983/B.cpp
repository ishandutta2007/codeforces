#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 5001
int N,M,a[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int highbit(int x){return 1<<(31-__builtin_clz(x));}
int main()
{
	N=get();For(i,1,N)a[i]=get(),f[i][i]=a[i];For(l,1,N-1)For(i,1,N-l){int j=i+l;if(__builtin_popcount(l+1)==1)f[i][j]=f[i][i+(l+1>>1)-1]^f[i+(l+1>>1)][j];else f[i][j]=f[i][j-highbit(l+1)]^f[i+highbit(l+1)][j];}
	For(i,1,N)g[i][i]=f[i][i];For(l,1,N-1)For(i,1,N-l){int j=i+l;g[i][j]=max(f[i][j],max(g[i][j-1],g[i+1][j]));}
	M=get();For(i,1,M){int l=get(),r=get();cout<<g[l][r]<<'\n';}return 0;
}