#include<iostream>
#include<cstdio>
#include<cstring>
#define N 110
#define ll long long
using namespace std;
bool f[N][N][2];
int pre[N][N][2];
ll num[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&num[i]);
		f[1][0][0]=f[1][0][1]=true;
		for(int i=1;i<n;i++)
			for(int j=0;j<min(i,n/2+1);j++)
				for(int k=0;k<=1;k++)
				if(f[i][j][k])
				{
					ll a=k?-num[i]:num[i];
					for(int k_=0;k_<=1;k_++)
					{
						ll a_=k_?-num[i+1]:num[i+1];
						if(a_>a) f[i+1][j+1][k_]=true,pre[i+1][j+1][k_]=k+3;
						if(a_<a) f[i+1][j][k_]=true,pre[i+1][j][k_]=k;
						if(a_==a) f[i+1][j+1][k_]=f[i+1][j][k_]=true,pre[i+1][j+1][k_]=k+3,pre[i+1][j][k_]=k;
					}
				}
		int k=f[n][n/2][0]?0:1,j=n/2;
		for(int i=n;i>=1;i--)
		{
			num[i]=k?-num[i]:num[i];
			int k_=pre[i][j][k];
			if(k_>=3) k_-=3,j--;
			k=k_;
		}
		for(int i=1;i<=n;i++) printf("%lld ",num[i]);
		puts("");
	}
	return 0;
}