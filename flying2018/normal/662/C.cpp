#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 100010
#define M 21
#define ll long long
using namespace std;
int n,m;
ll num[21][N],_2[1<<M],f[1<<M],g[1<<M],s[1<<M];
void fwt_xor(ll f[],int n,int opt)
{
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=j;k<j+(i>>1);k++)
			{
				ll x=f[k],y=f[k+(i>>1)];
				f[k]=x+y;
				f[k+(i>>1)]=x-y;
				if(opt==-1)
				{
					f[k]=f[k]/2;
					f[k+(i>>1)]=f[k+(i>>1)]/2; 
				}
			}
}
char str[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(int j=1;j<=m;j++)
		num[i][j]=str[j]-'0';
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			s[i]|=(1<<j-1)*num[j][i];
	for(int i=1;i<=m;i++) f[s[i]]++;
	for(int i=0;i<=1<<n;i++)
		g[i]=g[i>>1]+(i&1);
	for(int i=0;i<=1<<n;i++) g[i]=min(g[i],n-g[i]);
	fwt_xor(f,1<<n,1);
	fwt_xor(g,1<<n,1);
	for(int i=0;i<(1<<n);i++) f[i]*=g[i];
	fwt_xor(f,1<<n,-1);
	ll ans=1000000000;
	for(int i=0;i<(1<<n);i++) ans=min(f[i],ans);
	printf("%lld",ans);
	return 0;
}