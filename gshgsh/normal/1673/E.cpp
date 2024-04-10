#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<21
int N,K,a[MAXN],cnt[MAXN],sum[27][MAXN],ans[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),K=get();For(i,1,N)a[i]=get();
	For(i,1,N)cnt[i]=i&1?0:cnt[i>>1]+1;For(i,1,N)cnt[i]+=cnt[i-1];
	For(i,1,26)
	{
		int x=N-i;FOR(j,x,0)sum[i][j]=cnt[x]==cnt[j]+cnt[x-j];
		FOR(j,x-1,0)sum[i][j]^=sum[i][j+1];
	}
	For(i,1,N)
	{
		int r=i;ll s=a[i];
		while(r<=N&&N-(r-i+1)>=K&&s<(1<<20))
		{
			int x=N-(r-i+1),y=K;if(i>1)x--,y--;if(r<N)x--,y--;if(y<0)y=0;
			if(sum[N-x][y])ans[s]^=1;
			r++;if(a[r]>20)break;s*=1<<a[r];
		}
	}
	FOR(i,(1<<20)-1,0)if(ans[i]||i==0){FOR(j,i,0)cout<<ans[j];cout<<'\n';break;}return 0;
}