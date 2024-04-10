#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,ans,a[MN+5];
pa s[MN+5];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read();
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i) a[i]=int((2e9)+7);a[0]=-a[1];
	for(int i=1;i<=n;++i)
	{
		int x=s[i].first-s[i].second,l=0,r=i-1,mid,res;
		while(l<=r)
		{
			mid=l+r>>1;
			if(a[mid]<=x) res=l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,res);a[res]=min(a[res],s[i].first+s[i].second);
	}
	printf("%d\n",ans);
	return 0;
}