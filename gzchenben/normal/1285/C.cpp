#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long n,ans=1e15,tn;
vector<long long> vec;
void dfs(int step,long long now)
{
	if(step==n)
	{
//		printf("--%lld\n",now);
		ans=min(ans,max(now,tn/now));
		return;
	}
	dfs(step+1,now);
	dfs(step+1,now*vec[step]);
	return;
}
int main()
{
	scanf("%lld",&n);
	tn=n;
	for(long long i=2ll;i*i<=n;i++)
	{
		if(n%i==0)
		{
			long long tmp=1;
			while(n%i==0)
			{
				n/=i;
				tmp*=i;
			}
			vec.push_back(tmp);
		}
	}
	if(n!=1) vec.push_back(n);
	n=vec.size();
//	printf("%d\n",n);
	dfs(0,1ll);
	printf("%lld %lld\n",tn/ans,ans);
}