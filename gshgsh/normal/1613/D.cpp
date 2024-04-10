#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 600001
int T,N,a[MAXN],f[MAXN][2];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get()+1;For(i,1,N+3)f[i][0]=f[i][1]=0;f[0][0]=1;
		For(i,1,N)
		{
			f[a[i]][0]=(2ll*f[a[i]][0]+f[a[i]-1][0])%P;f[a[i]+2][1]=2ll*f[a[i]+2][1]%P;
			a[i]>1&&(f[a[i]][1]=(2ll*f[a[i]][1]+f[a[i]-2][0])%P);
		}
		int ans=0;For(i,0,N+1)ans=(0ll+ans+f[i][0]+f[i][1])%P;cout<<(ans+P-1)%P<<'\n';
	}
	return 0;
}