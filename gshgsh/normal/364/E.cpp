#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2501
int N,M,K,a[MAXN][MAXN],f[2][10];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int sum(int x1,int y1,int x2,int y2){return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];}
ll solve(int x1,int x2,int y1,int y2)
{
	if(x1==x2&&y1==y2)return sum(x1,y1,x2,y2)==K;int type=x2-x1>=y2-y1;
	if(type)
	{
		int mid=x1+x2>>1;ll ans=solve(x1,mid,y1,y2)+solve(mid+1,x2,y1,y2);
		For(i,y1,y2)
		{
			For(j,0,K+1)f[0][j]=mid,f[1][j]=mid+1;
			FOR(j,y2,i)
			{
				For(k,0,K+1)while(f[0][k]>=x1&&sum(f[0][k],i,mid,j)<k)f[0][k]--;
				For(k,0,K+1)while(f[1][k]<=x2&&sum(mid+1,i,f[1][k],j)<k)f[1][k]++;
				For(k,0,K)ans+=(f[0][k]-f[0][k+1])*(f[1][K-k+1]-f[1][K-k]);
			}
		}
		return ans;
	}
	int mid=y1+y2>>1;ll ans=solve(x1,x2,y1,mid)+solve(x1,x2,mid+1,y2);
	For(i,x1,x2)
	{
		For(j,0,K+1)f[0][j]=mid,f[1][j]=mid+1;
		FOR(j,x2,i)
		{
			For(k,0,K+1)while(f[0][k]>=y1&&sum(i,f[0][k],j,mid)<k)f[0][k]--;
			For(k,0,K+1)while(f[1][k]<=y2&&sum(i,mid+1,j,f[1][k])<k)f[1][k]++;
			For(k,0,K)ans+=(f[0][k]-f[0][k+1])*(f[1][K-k+1]-f[1][K-k]);
		}
	}
	return ans;
}
int main(){N=get(),M=get(),K=get();For(i,1,N)For(j,1,M)a[i][j]=a[i][j-1]+a[i-1][j]-a[i-1][j-1]+getc();cout<<solve(1,N,1,M)<<'\n';return 0;}