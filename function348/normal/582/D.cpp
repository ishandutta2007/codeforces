#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=4010,P=1000000007;
int p,q,n,m;
char A[N];
int f[N][N][2][2];
int a[N],c[N];
int c1(int i)
{
	if (i<p) return i+1;else return (2*p-1-i)%P;
}
int c22(int i)
{
	if (i<0) return 0;
	if (i<p-1) return 1LL*(i+1)*(i+2)/2%P;
	else { i-=p;return (1LL*p*(i+1)-1LL*(i+1)*(i+2)/2)%P;}
}
int c2(int i)
{
	if (i<0) return 0;
	if (i<p-1) return 1LL*(i+1)*(i+2)/2%P;
	else { i-=p;return (1LL*p*(i+2)-1LL*(i+1)*(i+2)/2)%P;}
}
int c3(int i)
{
	if (i==0)  return 1LL*(p+1)*p/2%P;
	if (i==-1) return 1LL*(p-1)*p/2%P;
	if (i==p)  return 1LL*(p-1)*p/2%P;
	if (i==p-1)return 1LL*(p+1)*p/2%P;
}
int dp(int i,int j,int f1,int f2)
{
	if (i==0)
	{
		if (f2) return 0;
		if (j>=q) return 1;
		return 0;
	}
	if (f[i][j][f1][f2]!=-1) return f[i][j][f1][f2];
	int res=0;
	if (f1)
	{
		res=(res+1LL*dp(i-1,j  ,1,0)*c1(a[i]+p*f2))%P;
		
//	printf("%d %d %d %d %d\n",i,j,f1,f2,res);
	
		res=(res+1LL*dp(i-1,j+1,1,1)*c1(a[i]+p*f2-1))%P;	
//	printf("%d %d %d %d %d\n",i,j,f1,f2,res);
	
		if (a[i]>=1)
		res=(res+1LL*dp(i-1,j  ,0,0)*c22(a[i]-1+p*f2))%P;
//	printf("%d %d %d %d %d\n",i,j,f1,f2,res);
	
		if (a[i]>=1)
		res=(res+1LL*dp(i-1,j+1,0,1)*c2(a[i]-2+p*f2))%P;
//	printf("%d %d %d %d %d\n",i,j,f1,f2,res);
	}
	else
	{
		res=(res+1LL*dp(i-1,j  ,0,0)*c3(f2*p))%P;
		res=(res+1LL*dp(i-1,j+1,0,1)*c3(f2*p-1))%P;
	}
//	printf("%d %d %d %d %d\n",i,j,f1,f2,res);
	f[i][j][f1][f2]=res;
	return res;
}
int divv(int p)
{
	LL now=0;
	for (int i=n;i>=1;i--)
	{
		now=now*10+c[i];
		c[i]=now/p;
		now%=p;
	}
	while (c[n]==0&&n) n--;
	return now;
}
int main()
{
	scanf("%d%d",&p,&q);
	scanf("%s",A+1);n=strlen(A+1);
	for (int i=1;i<=n;i++) c[i]=A[n+1-i]-'0';
	while (n) a[++m]=divv(p);
	n=m;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=n;j++)
	for (int k1=0;k1<2;k1++)
	for (int k2=0;k2<2;k2++)
		f[i][j][k1][k2]=-1;
	if (n<q) { printf("0\n");return 0;}
	printf("%d\n",dp(n,0,1,0));
	return 0;
}