#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=1e9+7,mh=1e6+3;
const long long p=131,md1=32984792344369,md2=32984792344321;
long long ans,dp[3333],has1,has2;
int n,a[3333],s;
struct hasht
{
	vector<pair<long long,long long> > v[1111111];
	void add(pair<long long,long long> x)
	{
		long long cur=x.first%mh;
		v[cur].push_back(x);
	}
	bool find(pair<long long,long long> x)
	{
		long long cur=x.first%mh;
		for (int i=0;i<v[cur].size();i++)
		{
			if (v[cur][i]==x) return 1;
		}
		return 0;
	}
}ht;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i+1]=1;
		has1=has2=0;
		for (int j=i;j>=1;j--)
		{
			dp[j]=0;s=0;has1=(has1*p+3*a[j]+1)%md1;
			has2=(has2*p+3*a[j]+1)%md2;
			for (int k=j;k<=i && k<=j+3;k++)
			{
				s=(s<<1)|a[k];
				if (k==j+3 && (s==3 || s==5 || s==14 || s==15)) continue;
				dp[j]+=dp[k+1];
				if (dp[j]>=mod) dp[j]-=mod;
			}
			if (!ht.find(make_pair(has1,has2)))
			{
				ht.add(make_pair(has1,has2));
				ans=(ans+dp[j])%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return Accepted;
}