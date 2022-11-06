#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2510
#define M 10
using namespace std;
int sum[N][N],n,m,k;
char s[N];
int fl[M],fr[M];
long long ans=0;
int slv(int lx,int ly,int rx,int ry,int o){if(o)swap(lx,ly),swap(rx,ry);return sum[rx][ry]-sum[lx-1][ry]-sum[rx][ly-1]+sum[lx-1][ly-1];}
void work(int lx,int ly,int rx,int ry,int o)
{
	if(lx>rx || ly>ry) return;
	if(rx-lx>ry-ly) swap(lx,ly),swap(rx,ry),o^=1;
	int mid=(ly+ry)>>1;
	for(int i=lx;i<=rx;i++)
	{
		for(int j=0;j<=k;j++) fl[j]=ly,fr[j]=ry;
		for(int j=i;j<=rx;j++)
		{
			for(int p=0;p<=k;p++)
			{
				while(slv(i,fl[p],j,mid,o)>p) fl[p]++;
				while(slv(i,mid+1,j,fr[p],o)>p) fr[p]--;
			}
			for(int p=0;p<=k;p++)
				ans+=((p==0?mid+1:fl[p-1])-fl[p])*(fr[k-p]-(p==k?mid-1:fr[k-p-1]));
		}
	}
	work(lx,ly,rx,mid-1,o),work(lx,mid+1,rx,ry,o);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+s[j]-'0';
	}
	work(1,1,n,m,0);
	printf("%lld\n",ans);
	return 0;
}