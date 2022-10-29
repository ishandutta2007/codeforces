#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,n,p,k,vis[M],a[N],d,str,End;
map<int,int>mp;
int power(int x,int y)
{
		int sum=1;
		for (;y;y>>=1)
		{
				if (y&1) sum=1ll*sum*x%m;
				x=1ll*x*x%m;
		}
		return sum;
}
int cal()
{
	int i,usedsum=(a[2]-a[1]+m)%m;
	long long ans=0;
	for (i=1;i<=n;++i)
	{
		 int need=(a[i]-usedsum+m)%m;
		 ans+=mp[need];
		 mp[a[i]]++;
	}
	mp.clear();
	for (i=n;i;--i)
	{
		 int need=(a[i]-usedsum+m)%m;
		 ans+=mp[need];
		 mp[a[i]]++;
	}	
	ans=n-ans;
	if (ans<=0) return -1;
	d=1ll*usedsum*power(ans,m-2)%m;
	mp.clear();
	for (i=1;i<=n;++i) mp[a[i]]++;
 	for (str=0;str<n;++str) if (mp.find((a[1]+1ll*str*d%m)%m)==mp.end()) break;
 	for (End=0;End<n;++End) if (mp.find((a[1]-1ll*End*d%m+m)%m)==mp.end()) break;
 	if (End+str-1>=n) return (a[1]-1ll*(End-1)*d%m+m)%m; 
 	else return -1;
}
int main()
{
	scanf("%d%d",&m,&n);
	if (n>m) puts("-1");
	else if (n==m) puts("0 1");
	else 
	{
		for (i=1;i<=n;++i) scanf("%d",&a[i]);
		if (n==1)
		{
				printf("%d 0\n",a[1]);
				return 0;
		}
		if (2*n<m)
		{
				int x=cal();
				if (x==-1) puts("-1");
				else 
				printf("%d %d\n",x,d);
		}
		else 
		{
			  for (i=1;i<=n;++i) vis[a[i]]++;
			  n=0;
			  for (i=0;i<m;++i)
			  if (!vis[i]) a[++n]=i;
			  int x=cal();
			  if (x==-1) printf("%d\n",x);
			  else printf("%I64d %d\n",(x+1ll*n*d%m)%m,d); 
		}
	}
}