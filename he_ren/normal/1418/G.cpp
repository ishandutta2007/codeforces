#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

inline ll rnd(void){ return ((ll)rand()<<45) | ((ll)rand()<<30) | (rand()<<15) | rand();}

int a[MAXN];
ll val[MAXN], h[MAXN];

int main(void)
{
	srand((unsigned long long)new char);
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) val[i] = rnd();
	
	ll ans = 0;
	map<ll,int> t;
	t[0] = 1;
	for(int i=1,j=1; i<=n; ++i)
	{
		static int freq[MAXN];
		++freq[a[i]];
		while(freq[a[i]] > 3) --t[h[j-1]], --freq[a[j]], ++j;
		
		static int coef[MAXN];
		h[i] = h[i-1] ^ (val[a[i]] * coef[a[i]]);
		coef[a[i]] = (coef[a[i]] + 1) % 3;
		h[i] ^= (val[a[i]] * coef[a[i]]);
		
		ans += t[h[i]]++;
	}
	
	printf("%lld",ans);
	return 0;
}