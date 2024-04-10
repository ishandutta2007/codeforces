#include<cstdio>
#include<map>
typedef long long ll;
const int MAXN = 1e5 + 5;
using namespace std;

int a[MAXN];
ll s[MAXN];
map<ll,int> t1,t2;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) s[i]=s[i-1]+a[i];
	if(s[n]&1ll)
	{
		printf("NO");
		return 0;
	}
	ll sum=s[n]>>1ll;
	
	for(int i=1; i<=n; ++i) ++t1[a[i]];
	for(int i=0; i<=n; ++i)
	{
		if(i)
		{
			--t1[a[i]];
			if(!t1[a[i]]) t1.erase(a[i]);
			++t2[a[i]];
		}
		
		if(s[i]>sum)
		{
			if(t2.find(s[i]-sum)!=t2.end())
			{
				printf("YES");
				return 0;
			}
		}
		else if(s[i]==sum)
		{
			printf("YES");
			return 0;
		}
		else
		{
			if(t1.find(sum-s[i])!=t1.end())
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}