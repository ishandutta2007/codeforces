#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int N=1000, SUM=20001, m=1e9+7;
long long gl[SUM], gr[SUM], dp[SUM], temp[SUM];
int n, a[N];

long long inRange(int l, int r)
{
	if(r-l<=1)
		return 0;
	int mid = (l+r)/2;
	long long ans=(inRange(l,mid)+inRange(mid,r))%m;
	int s1=0,s2=0;
	rep(i,l,mid)
		s1+=a[i];
	rep(i,mid,r)
		s2+=a[i];
	
	for(int i=0;i<=s1+s1;++i)
	{
		gl[i]=0;
		dp[i]=0;
	}
	dp[s1]=1;
	for(int i=mid-1;i>=l;--i)
	{
		int x=a[i];
		for(int j=0;j<=s1+s1;++j)
			temp[j]=0;
		for(int j=0;j<=s1+s1;++j)
		{
			if(j-x>=0)
				temp[j-x]+=dp[j], temp[j-x]%=m;
			if(j+x<=s1+s1)
				temp[j+x]+=dp[j], temp[j+x]%=m;
		}
		for(int j=0;j<=s1+s1;++j)
		{
			gl[j]+=temp[j], gl[j]%=m;
			dp[j]=temp[j];
		}
	}

	for(int i=0;i<=s2+s2;++i)
	{
		gr[i]=0;
		dp[i]=0;
	}
	dp[s2]=1;
	for(int i=mid;i<r;++i)
	{
		int x=a[i];
		for(int j=0;j<=s2+s2;++j)
			temp[j]=0;
		for(int j=0;j<=s2+s2;++j)
		{
			if(j-x>=0)
				temp[j-x]+=dp[j], temp[j-x]%=m;
			if(j+x<=s2+s2)
				temp[j+x]+=dp[j], temp[j+x]%=m;
		}
		for(int j=0;j<=s2+s2;++j)
		{
			gr[j]+=temp[j], gr[j]%=m;
			dp[j]=temp[j];
		}
	}
	ans+=gl[s1]*gr[s2], ans%=m;
	for(int j=1;j<=s1 && j<=s2;++j)
		ans+=2*gl[s1+j]*gr[s2+j], ans%=m;
	return ans;
}

int main()
{
	scanf("%d",&n);
	rep(i,0,n)
	{
		scanf("%d",&a[i]);
	}

	cout<<inRange(0,n)<<endl;
}