#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=200101;
int cas,n,m;
LL t;
int a[N];
LL check(int mid)
{
	LL res=0,d=0,c=0;
	for (int i=1;i<=n;i++)
	if (a[i]<=mid)
	{
		res+=a[i];c++;
		if (c==m+1) c=1,res+=d,d=0;
		d+=a[i];
	}
	return res;
}
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d%I64d",&n,&m,&t);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int l=0,r=200000;
		while (l<r)
		{
			int mid=(l+r+1)>>1;
			if (check(mid)<=t) l=mid;else r=mid-1;
		}
		int ans=0,lim=1<<30,ansi=l;
		for (int i=1;i<=n;i++)
			if (a[i]<=l) ans++;
			else lim=min(lim,a[i]);
		LL res=0,d=0;int c=0;
		for (int i=1;i<=n;i++)
		if (a[i]<=lim)
		{
			res+=a[i];c++;
			if ((c-1)%m==0&&c>1) res+=d,d=0;
			d+=a[i];
			if (res<=t) 
			{
				if (c>ans) ans=c,ansi=lim;
			}
			else break;
		}
		if (ansi==0) ansi=1;
		if (ansi>t) ansi=t;
		printf("%d %d\n",ans,ansi);
	}
}