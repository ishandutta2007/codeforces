#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=200010;
int n,k,x;
int a[N][20];
int xx[N];
LL ans;
int q(int l,int r)
{
	if (l>r) return 0;
	int k=xx[r-l+1];
	return a[l][k]|a[r-(1<<k)+1][k];
}
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i][0]);
	for (int j=1;(1<<j)<=n;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
		a[i][j]=a[i][j-1]|a[i+(1<<(j-1))][j-1];
	xx[1]=0;
	for (int i=2;i<=n;i++) xx[i]=xx[i/2]+1;
	
	for (int i=1;i<=n;i++)
	{
		LL p=a[i][0];
		for (int j=1;j<=k;j++) p*=x;
		p=p|q(1,i-1)|q(i+1,n);
		ans=max(ans,p);
	}
	cout<<ans<<endl;
	return 0;
}