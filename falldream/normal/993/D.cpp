#include<bits/stdc++.h>
#define MN 50 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long f[MN+5][MN+5],c[MN+5];
int n,a[MN+5],b[MN+5],rk[MN+5];
bool cmp(int x,int y){return a[x]>a[y];}
bool Solve(long long mid)
{
	for(int i=0;i<=n;++i) for(int j=0;j<=n;++j) f[i][j]=-1e18; 
	f[0][0]=0;
	for(int i=1,j;i<=n;i=j+1)
	{
		for(j=i;j<n&&a[rk[j+1]]==a[rk[i]];++j);
		for(int k=i;k<=j;++k) c[k]=mid*b[rk[k]]-1000LL*a[rk[k]];
		sort(c+i,c+j+1,greater<long long>());
		c[i-1]=0;for(int k=i;k<=j;++k) c[k]+=c[k-1];
		for(int l=0;l<=n;++l)
			for(int k=0;k<=l&&k<=j-i+1;++k)
				f[j][l+(j-i+1)-2*k]=max(f[j][l+(j-i+1)-2*k],f[i-1][l]+c[j-k]);
	}
	for(int i=0;i<=n;++i) if(f[n][i]>=0) return true;
	return false;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read(),rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	long long l=0,r=2e12,mid,res;
	while(l<=r)
	{
		mid=l+r>>1;
		if(Solve(mid))res=mid,r=mid-1;
		else l=mid+1;	
	}
	printf("%lld",res);
	return 0;
}