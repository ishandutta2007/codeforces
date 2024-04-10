#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	set<ll> t;
	t.insert(0);
	
	int ans = 0;
	
	ll sum = 0;
	for(int i=1; i<=n; ++i)
	{
		sum += a[i];
		if(t.find(sum) == t.end()) t.insert(sum);
		else
		{
			++ans;
			t.clear();
			sum = a[i];
			t.insert(0);
			t.insert(a[i]);
		}
	}
	
	printf("%d",ans);
	return 0;
}