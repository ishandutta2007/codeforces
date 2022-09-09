#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int main(void)
{
	int n,d,m;
	scanf("%d%d%d",&n,&d,&m);
	
	vector<int> a(1),b(1);
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x>m) b.push_back(x);
		else a.push_back(x);
	}
	
	sort(a.begin()+1, a.end());
	reverse(a.begin()+1,a.end());
	
	sort(b.begin()+1,b.end());
	reverse(b.begin()+1,b.end());
	
	vector<ll> bs(b.size());
	for(int i=1; i<(int)b.size(); ++i)
		bs[i] = bs[i-1] + b[i];
	
	ll ans = 0;
	
	ll sum = 0;
	for(int i=0; i<(int)a.size(); ++i)
	{
		sum += a[i];
		int rem = n - i;
		
		int tot = (rem+d+1 - 1)/(d+1);
		if(tot >= (int)b.size()) continue;
		ans = max(ans, sum + bs[tot]);
	}
	printf("%lld\n",ans);
	return 0;
}