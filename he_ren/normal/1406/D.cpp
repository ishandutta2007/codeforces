#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll a[MAXN], dif[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	for(int i=1; i<=n; ++i)
		dif[i] = a[i] - a[i-1];
	
	ll x = 0;
	for(int i=2; i<=n; ++i)
		if(dif[i] >= 0) x += dif[i];
	
	printf("%lld\n",(dif[1] + x)%2? (dif[1] + x + 1)/2: (dif[1] + x)/2);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		
		if(l != 1)
		{
			if(dif[l] >= 0) x -= dif[l];
			dif[l] += k;
			if(dif[l] >= 0) x += dif[l];
		}
		else dif[1] += k;
		
		if(r != n)
		{
			if(dif[r+1] >= 0) x -= dif[r+1];
			dif[r+1] -= k;
			if(dif[r+1] >= 0) x += dif[r+1];
		}
		
		printf("%lld\n",(dif[1] + x)%2? (dif[1] + x + 1)/2: (dif[1] + x)/2);
	}
	return 0;
}