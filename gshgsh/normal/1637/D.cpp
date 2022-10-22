#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
#define MAXM 10001
int T,N,a[MAXN],b[MAXN],f[MAXN][MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();
		int ans=0;For(i,1,N)ans+=a[i]*a[i]+b[i]*b[i];int sum=0;For(i,1,N)sum+=max(a[i],b[i]);
		For(i,0,N)For(j,0,sum)f[i][j]=0;f[0][0]=1;int M=0;For(i,1,N)M+=a[i]+b[i];
		For(i,0,N-1){For(j,0,sum-a[i+1])f[i+1][j+a[i+1]]|=f[i][j];For(j,0,sum-b[i+1])f[i+1][j+b[i+1]]|=f[i][j];}
		int mn=1e9;For(i,0,sum)if(f[N][i])mn=min(mn,i*i+(M-i)*(M-i));cout<<mn+(N-2)*ans<<'\n';
	}
}