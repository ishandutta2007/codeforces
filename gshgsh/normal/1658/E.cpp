#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define abs(x) ((x)>0?(x):-(x))
#define MAXN 2001
int N,K,a[MAXN][MAXN],f[MAXN][MAXN],px[MAXN*MAXN],py[MAXN*MAXN],v1[MAXN*MAXN],v2[MAXN*MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),K=get();For(i,1,N)For(j,1,N)a[i][j]=get(),v1[a[i][j]]=i+j,v2[a[i][j]]=i-j,px[a[i][j]]=i,py[a[i][j]]=j;f[px[N*N]][py[N*N]]=1;int mx1=v1[N*N],mn1=v1[N*N],mx2=v2[N*N],mn2=v2[N*N];
	FOR(i,N*N-1,1){if(max(max(abs(mx1-v1[i]),abs(mn1-v1[i])),max(abs(mx2-v2[i]),abs(mn2-v2[i])))<=K)f[px[i]][py[i]]=1,mx1=max(mx1,v1[i]),mn1=min(mn1,v1[i]),mx2=max(mx2,v2[i]),mn2=min(mn2,v2[i]);}
	For(i,1,N){For(j,1,N)cout<<(f[i][j]?'M':'G');cout<<'\n';}
}