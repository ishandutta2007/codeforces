#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int N=200010,p=1000000007;
typedef long long LL;
multiset<int> S;
LL ans;
int a[N],b[N];
int n,k;
int main()
{
//	freopen("dividing.in","r",stdin);
//	freopen("dividing.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for (int i=1;i<=n;i++) b[i]=min(b[i],(1<<k)-1-b[i]);
	sort(b+1,b+1+n);
	for (int i=0,j=0;i<=n;i++)
	if (b[i]!=b[i+1]||i==n) 
	{
		int t=i-j+1;
		int u=t/2;
		ans+=1LL*u*(u-1)/2;
		if (t%2==1) u++;
		ans+=1LL*u*(u-1)/2;
		j=i+1;
	}
/*	for (int i=n;i>=1;i--)
	{
		S.erase(S.find(b[i]));
		now-=S.count(b[i]);
		b[i]=(1<<k)-1-b[i];
		now+=S.count(b[i]);
		S.insert(b[i]);
		ans=min(ans,now);
	}*/
	ans=1LL*n*(n+1)/2-ans;
	cout<<ans<<endl;
	return 0;
}

/*
   f[i][j] > j < (i-1-c[i-1]+j)
   */