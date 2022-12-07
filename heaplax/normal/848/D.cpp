#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 100
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
const int mod=1000000007;
int n,m,inv[N],f[N][N],g[N][N],h[N][N];
int main()
{
	re(n),re(m);
	f[0][1]=1;
	inv[1]=1;
	for(int i=2;i<N;++i)
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i+1;++j)
		{
			for(int p=0;p<i;++p)
			{
				int q=i-1-p;
				for(int k=j;k<=p+1;++k)
					g[i][j]=(g[i][j]+1ll*f[p][k]*f[q][j])%mod;
				for(int k=j+1;k<=q+1;++k)
					g[i][j]=(g[i][j]+1ll*f[p][j]*f[q][k])%mod;
			}
			memset(h,0,sizeof h);
			for(int p=0;p<=n;++p)
				for(int q=1;q<=p+1;++q)
				{
					int w=1;
					for(int k=1;p+k*i<=n;++k)
					{
						w=1ll*w*(g[i][j]+k-1)%mod*inv[k]%mod;
						h[p+k*i][q+k*j]=(h[p+k*i][q+k*j]+1ll*f[p][q]*w)%mod;	
					}
				}
			for(int p=0;p<=n;++p)
				for(int q=1;q<=p+1;++q)
					f[p][q]=(f[p][q]+h[p][q])%mod;
		}
	printf("%d\n",f[n][m]);
}