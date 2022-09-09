#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Mp make_pair
const int MAXN = 2e5 + 5;

int a[MAXN];
ll sum[MAXN];
map<ll,int> t;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	int lst=0;
	ll ans=0;
	t[0]=0;
	for(int i=1; i<=n; ++i)
	{
		if(t.find(sum[i]) != t.end())
			lst = max(lst, t[sum[i]]+1);
		t[sum[i]]=i;
		
		ans += i-lst;
	}
	printf("%lld",ans);
	return 0;
}