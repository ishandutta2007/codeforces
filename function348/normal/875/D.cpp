#include <cstdio>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int N=200010;
int n,m,num,len1,len2,flag;
int a[N][20],xx[N],p[N];
map<int,int> last;
int q(int l,int r)
{
	if (l>r) return 0;
	int k=xx[r-l+1];
	return a[l][k]|a[r-(1<<k)+1][k];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i][0]);
		m=max(m,a[i][0]);
		if (last.find(a[i][0])!=last.end()) p[i]=last[a[i][0]];
		last[a[i][0]]=i;
	}
	for (int j=1;(1<<j)<=n;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
		a[i][j]=a[i][j-1]|a[i+(1<<(j-1))][j-1];
	for (int i=2;i<=n;i++) xx[i]=xx[i/2]+1;
	long long ans=0;
	int k=1;
	for (int i=1;i<=n;i++)
	{
		int l=p[i]+1,r=i;
		while (l<r)
		{
			int mid=(l+r)>>1;
			int x=q(mid,i-1);
			if ((x|a[i][0])==a[i][0]) r=mid;else l=mid+1;
		}
		int k1=l;
		l=i,r=n;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			int x=q(i+1,mid);
			if ((x|a[i][0])==a[i][0]) l=mid;else r=mid-1;
		}
		ans+=1LL*(i-k1+1)*(l-i+1);
	}
	ans=1LL*n*(n-1)/2-ans+n;
	cout<<ans;
	return 0;
}