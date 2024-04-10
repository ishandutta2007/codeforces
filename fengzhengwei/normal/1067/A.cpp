#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
const int xx=1e5+5;
const int mod=998244353;
int a[xx];
int f[2][205][2],sum[2][205][2];
int red(int x)
{
	if(x<0)return x+mod;
	if(x>=mod)return x-mod;
	return x;
}
signed main(){
//	freopen("a.in","r",stdin);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(a[1]!=-1)f[1][a[1]][0]=1;
	else for(int i=1;i<=200;i++)f[1][i][0]=1;
	for(int i=1;i<=200;i++)sum[1][i][0]=red(sum[1][i-1][0]+f[1][i][0]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=200;j++)for(int k=0;k<=1;k++)f[i&1][j][k]=sum[i&1][j][k]=0;
		if(a[i]!=-1)
		{
			int j=a[i];
			f[i&1][j][1]=red(sum[!(i&1)][200][1]-sum[!(i&1)][j-1][1]);// 
			f[i&1][j][1]=red(f[i&1][j][1]+f[!(i&1)][j][0]);// 
			f[i&1][j][0]=red(sum[!(i&1)][j-1][0]+sum[!(i&1)][j-1][1]);
		}
		else 
		{
			for(int j=1;j<=200;j++)
			{
				f[i&1][j][1]=red(sum[!(i&1)][200][1]-sum[!(i&1)][j-1][1]);// 
				f[i&1][j][1]=red(f[i&1][j][1]+f[!(i&1)][j][0]);// 
				f[i&1][j][0]=red(sum[!(i&1)][j-1][0]+sum[!(i&1)][j-1][1]);
			}
		}
		for(int j=1;j<=200;j++)
		{
			sum[i&1][j][0]=red(sum[i&1][j-1][0]+f[i&1][j][0]);
			sum[i&1][j][1]=red(sum[i&1][j-1][1]+f[i&1][j][1]);
//				cout<<sum[i&1][j][1]<<" sss "<<sum[i&1][j][0]<<"\n";
		}
	}
	cout<<sum[n&1][200][1]<<"\n";
	return 0;
}