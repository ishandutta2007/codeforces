#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline ll calc(int x,int k)
{
	if(x < k) return -linf;
	
	ll cnt = x / k;
	return (ll)(x%k) * (cnt + 1) * (cnt + 1) + (ll)(k - x%k) * cnt * cnt;
}

int a[MAXN];

priority_queue<pair<ll, pii> > t;
inline void insert(int x,int k)
{
	if(x > k)
		t.push(make_pair(calc(x,k) - calc(x,k+1), make_pair(x, k)));
}

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += (ll)a[i] * a[i];
	
	for(int i=1; i<=n; ++i)
		insert(a[i], 1);
	
	int cur = n;
	while(cur < d)
	{
		pair<ll, pii> chs = t.top(); t.pop();
		
		ans -= chs.first;
		insert(chs.second.first, chs.second.second + 1);
		
		++cur;
	}
	
	printf("%lld",ans);
	return 0;
}