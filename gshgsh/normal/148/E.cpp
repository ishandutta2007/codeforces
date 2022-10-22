#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
#define MAXM 10001
int N,M,lim[MAXN],a[MAXN][MAXN],val[MAXN][MAXN],f[MAXN][MAXM],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,N){lim[i]=get();For(j,1,lim[i])a[i][j]=a[i][j-1]+get();For(j,1,lim[i])For(k,0,j)val[i][j]=max(val[i][j],a[i][lim[i]]-a[i][lim[i]-j+k]+a[i][k]);}
	For(i,1,N)For(j,0,M)For(k,0,min(j,lim[i]))ans=max(ans,f[i][j]=max(f[i][j],f[i-1][j-k]+val[i][k]));cout<<ans<<endl;return 0;
}