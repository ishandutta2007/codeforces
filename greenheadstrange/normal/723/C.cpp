#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 5005
using namespace std;
int num[maxn],a[maxn];
int n,m;
int ndsum[maxn];
int ans1,ans2;
int need[maxn*2],fr=0,ed=0;
int main()
{
	scanf("%d%d",&n,&m);
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++)
	{ 
		scanf("%d",&a[i]);
		if(a[i]<=m) num[a[i]]++;
	 }
	ans1=n/m;
	ans2=0;
	for(int i=1;i<=m;i++)
		if(num[i]<ans1)
		{
			ans2+=ans1-num[i];
			for(int j=0;j<ans1-num[i];j++) need[ed++]=i;
		}
	for(int i=0;i<n;i++)
	{
		if(a[i]>m && fr<ed)
			a[i]=need[fr++];
		else 
			if(num[a[i]]>ans1 && fr<ed) num[a[i]]--,a[i]=need[fr++];
	}
	printf("%d %d\n",ans1,ans2);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}