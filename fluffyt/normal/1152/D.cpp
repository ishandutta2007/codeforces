#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,m,f[2005][2005][2];
int ok(int i,int j)
{
	return (j>=0&&j<=n-i+1)?1:0;
}
int getsz(int i,int j)
{
	if(i==n) return 1;
	return ok(i+1,j-1)+ok(i+1,j+1);
}
void add(int &x,int val)
{
	x+=val;
	if(x>=mod) x-=mod;
}
int solve(int i,int j,int k)
{
	if(f[i][j][k]!=-1) return f[i][j][k];
	if(i==n) return f[i][j][k]=k;
	int ret=0;
	if(k==0)
	{
		if(ok(i+1,j+1)) add(ret,solve(i+1,j+1,1));
		if(ok(i+1,j-1)) add(ret,solve(i+1,j-1,1));
		return f[i][j][k]=ret;
	}
	else
	{
		if(!ok(i+1,j+1))
		{
			ret=1+solve(i+1,j-1,0);
			if(ret>=mod) ret-=mod;
			//printf("f(%d,%d,%d)=%d\n",i,j,k,ret);
			return f[i][j][k]=ret;
		}
		if(!ok(i+1,j-1))
		{
			ret=1+solve(i+1,j+1,0);
			if(ret>=mod) ret-=mod;
			//printf("f(%d,%d,%d)=%d\n",i,j,k,ret);
			return f[i][j][k]=ret;
		}
		if(getsz(i+1,j+1)>=getsz(i+1,j-1))
		{
			ret=1+solve(i+1,j+1,0);
			if(ret>=mod) ret-=mod;
			add(ret,solve(i+1,j-1,1));
			//printf("f(%d,%d,%d)=%d\n",i,j,k,ret);
			return f[i][j][k]=ret;
		}
		else
		{
			ret=1+solve(i+1,j-1,0);
			if(ret>=mod) ret-=mod;
			add(ret,solve(i+1,j+1,1));
			//printf("f(%d,%d,%d)=%d\n",i,j,k,ret);
			return f[i][j][k]=ret;
		}
	}
}
int main()
{
	scanf("%d",&n);
	n*=2;
	memset(f,-1,sizeof(f));
	printf("%d\n",solve(1,0,1));
	return 0;
}