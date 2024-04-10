#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 1000000007
#define MAXN 101
int N,b[MAXN],c[MAXN],sb[MAXN],sc[MAXN],x,f[MAXN][MAXN*MAXN],g[MAXN][MAXN*MAXN],ans;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)c[i]=get(),sc[i]=sc[i-1]+c[i];For(i,1,N-1)b[i]=get();For(i,1,N)For(j,1,i-1)sb[i]+=(i-j)*b[j];get(),x=get();
	For(i,0,sc[1])g[0][i]=1;For(i,1,N){For(j,max(x*i+sb[i],0),sc[i])f[i][j]=(g[i-1][j]-(j>c[i]?g[i-1][j-c[i]-1]:0)+P)%P;g[i][0]=f[i][0];For(j,1,sc[min(i+1,N)])g[i][j]=(g[i][j-1]+f[i][j])%P;}
	cout<<(sc[N]>=x*N+sb[N]?(g[N][sc[N]]-(x*N+sb[N]>0?g[N][x*N+sb[N]-1]:0)+P)%P:0)<<endl;return 0;
}