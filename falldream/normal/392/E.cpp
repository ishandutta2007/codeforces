#include<bits/stdc++.h>
#define MN 400 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,v[MN+5],u[MN+5][MN+5],d[MN+5][MN+5],f[MN+5][MN+5],a[MN+5],F[MN+5];
int main()
{
	n=read();
	memset(u,200,sizeof(u));
	memset(d,200,sizeof(d));
	memset(f,200,sizeof(f));
	for(int i=1;i<=n;++i) v[i]=read();
	for(int i=1;i<=n;++i) a[i]=read(),u[i][i]=d[i][i]=0;
	for(int i=n;i;--i) for(int j=i;j<=n;++j)
	{
		for(int k=i;k<j;++k) f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
		for(int k=i;k<j;++k) if(a[k]==a[j]-1) u[i][j]=max(u[i][j],u[i][k]+(k<j-1?f[k+1][j-1]:0));
		for(int k=j;k>i;--k) if(a[k]==a[i]-1) d[i][j]=max(d[i][j],d[k][j]+(k>i+1?f[i+1][k-1]:0));
		for(int k=i;k<=j;++k) 
			if(a[k]>=a[i]&&a[k]>=a[j]&&2*a[k]-a[i]-a[j]+1<=j-i+1)
			{
				f[i][j]=max(f[i][j],u[i][k]+d[k][j]+v[2*a[k]-a[i]-a[j]+1]);	
				//cout<<i<<" "<<k<<" "<<j<<" "<<u[i][k]<<" "<<d[k][j]<<" "<<v[2*a[k]-a[i]-a[j]+1]<<endl;
			}
	}
	for(int i=1;i<=n;++i,F[i]=F[i-1]) for(int j=i;j;--j)
		F[i]=max(F[i],F[j-1]+f[j][i]);
	printf("%d\n",F[n]);
	return 0;
}