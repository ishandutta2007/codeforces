#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i) ans += a[i];
	map<pii,int> t;
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		pii p;
		int x;
		scanf("%d%d%d",&p.first,&p.second,&x);
		
		if(t.find(p) != t.end())
		{
			int y = t[p];
			ans -= max(a[y] - b[y], 0);
			--b[y];
			ans += max(a[y] - b[y], 0);
			t.erase(p);
		}
		
		if(x)
		{
			t[p] = x;
			ans -= max(a[x] - b[x], 0);
			++b[x];
			ans += max(a[x] - b[x], 0);
		}
		
		printf("%lld\n",max(ans, 1ll));
	}
	return 0;
}