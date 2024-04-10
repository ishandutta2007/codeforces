#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
#define MAXM 10000001
int T,N,K,a[MAXN],l[MAXN][21],f[MAXN][21],tot,prm[MAXM],mn[MAXM],cnt[MAXM];bool Not[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int turn(int x){int y=1;while(x>1){int z=mn[x];while(x%(1ll*z*z)==0)x/=z*z;if(x%z==0)y*=z,x/=z;}return y;}
int main()
{
	For(i,2,MAXM-1){if(!Not[i])prm[++tot]=i,mn[i]=i;for(int j=1;j<=tot&&i*prm[j]<MAXM;j++){Not[i*prm[j]]=1;mn[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=turn(get());
		For(j,0,K)
		{
			int k=1,sum=0;
			For(i,1,N){cnt[a[i]]++;sum+=cnt[a[i]]>1;while(sum>j)cnt[a[k]]--,sum-=cnt[a[k++]]>=1;l[i][j]=k;}
			while(k<=N)cnt[a[k++]]--;
		}
		For(j,0,K)For(i,1,N)f[i][j]=N+1;f[0][0]=0;
		For(j,0,K)For(i,1,N){f[i][j]=N+1;For(k,0,j)f[i][j]=min(f[i][j],f[l[i][k]-1][j-k]+1);}
		cout<<f[N][K]<<'\n';
	}
	return 0;
}