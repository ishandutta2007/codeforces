#include<iostream>
#include<cstdio>
#include<cstring>
#define N 25
#define mod 1000000007
using namespace std;
int n,m,s;
struct matrix{
	int a[N][N];
	matrix(int x=0){memset(a,0,sizeof(a));for(int i=1;i<=s;i++) a[i][i]=x;}
	int* operator [](const int x){return a[x];}
}o,r;
matrix operator *(matrix a,matrix b)
{
	matrix c;
	for(int k=1;k<=s;k++)
		for(int i=1;i<=s;i++)
			for(int j=1;j<=s;j++)
			c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%mod;
	return c;
}
void ksm(matrix a,int k,matrix &r)
{
	for(;k;k>>=1)
	{
		if(k&1) r=r*a;
		a=a*a;
	}
}
int id[N][N];
bool ban[N][N];
void build()
{
	memset(o.a,0,sizeof(o.a));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		if(!ban[i][j])
		{
			o[id[i][j]][id[i][j]]=1;
			if(i<n && !ban[i+1][j]) o[id[i][j]][id[i+1][j]]=o[id[i+1][j]][id[i][j]]=1;
			if(j<m && !ban[i][j+1]) o[id[i][j]][id[i][j+1]]=o[id[i][j+1]][id[i][j]]=1;
		}
}
int main()
{
	int q;
	scanf("%d%d%d",&n,&m,&q);
	int pre=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) id[i][j]=++s;
	r[id[1][1]][id[1][1]]=1;
	for(int i=1;i<=q;i++)
	{
		int opt,x,y,t;
		scanf("%d%d%d%d",&opt,&x,&y,&t);
		build();
		ksm(o,t-pre,r);
		pre=t;
		if(opt==1) printf("%d\n",r[1][id[x][y]]);
		else if(opt==2) r[1][id[x][y]]=0,ban[x][y]=1;
		else if(opt==3) r[1][id[x][y]]=0,ban[x][y]=0;
	}
	return 0;
}