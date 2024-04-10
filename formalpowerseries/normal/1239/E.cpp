#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<18],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<18,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
const int MaxV=50000;
bool dp[30][1250005];
int pre[30][1250005];
int N,n,a[55],ans[3][30],buc[MaxV+5];
void Solve(int s)
{
	for(int i=N-1;i;--i)
	{
		int c=pre[i][s];
		ans[1][i+1]=c;
		--buc[c];
		s-=c;
	}
	int c=0;
	for(int i=MaxV;i;--i)
	{
		assert(buc[i]>=0);
		while(buc[i])	ans[2][++c]=i,--buc[i];
	}
}
int main(){
	n=read()<<1;
	for(int i=1;i<=n;++i)	a[i]=read();
	sort(a+1,a+1+n);
	N=n>>1;
	ans[1][1]=a[1],ans[2][N]=a[2];
	int sum=0;
	for(int i=3;i<=n;++i)	sum+=a[i];
	for(int i=3;i<=n;++i)	++buc[a[i]];
	sum>>=1;
	dp[0][0]=true;
	for(int i=3;i<=n;++i)
	{
		for(int j=min(N-1,i-2);j;--j)
		{
			for(int k=a[i];k<=sum;++k)
			{
				if(dp[j][k])	continue;
				if(dp[j-1][k-a[i]])	dp[j][k]=true,pre[j][k]=a[i];
			}
		}
	}
	for(int i=sum;~i;--i)	if(dp[N-1][i])	{Solve(i);break;}
	for(int i=1;i<=2;++i)	for(int j=1;j<=N;++j)	write(ans[i][j]),putchar(j==N?'\n':' ');
	return 0;
}