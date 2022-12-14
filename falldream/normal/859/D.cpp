#include<iostream>
#include<cstdio>
#define MN 64
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int f[MN+5][MN+5],n;double s[10][MN+5],p[10][MN+5],ans=0;

void Solve(int x,int l,int r,int S)
{
	if(l==r) {p[x][l]=1;return;}
	int mid=l+r>>1;Solve(x+1,l,mid,S>>1);Solve(x+1,mid+1,r,S>>1);
	double mx1=0,mx2=0;
	for(int i=l;i<=mid;++i) mx1=max(mx1,s[x+1][i]);
	for(int i=mid+1;i<=r;++i) mx2=max(mx2,s[x+1][i]);
	ans=max(ans,mx1+mx2);
	for(int i=l;i<=mid;++i) s[x][i]=s[x+1][i]+mx2;
	for(int i=mid+1;i<=r;++i) s[x][i]=s[x+1][i]+mx1;
	for(int i=l;i<=mid;++i)
		for(int j=mid+1;j<=r;++j)
		{
			p[x][i]+=p[x+1][i]*p[x+1][j]*f[i][j]/100;
			p[x][j]+=p[x+1][i]*p[x+1][j]*f[j][i]/100; 
			s[x][i]+=p[x+1][i]*p[x+1][j]*f[i][j]*S/100;
			s[x][j]+=p[x+1][i]*p[x+1][j]*f[j][i]*S/100; 
		}	
}

int main()
{
	n=read();
	for(int i=1;i<=1<<n;++i)for(int j=1;j<=1<<n;++j)f[i][j]=read();
	Solve(1,1,1<<n,1<<n-1);
	for(int i=1;i<=1<<n;++i) ans=max(ans,s[1][i]);
	printf("%.10lf\n",ans);
	return 0;
}