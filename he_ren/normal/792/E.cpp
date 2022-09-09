#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int n;
int a[MAXN];

ll ans;
inline void chk_ans(int x)
{
	if(x <= 0) return;
	ll res = 0;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] / x < a[i] % x) return;
		res += (a[i] + x) / (x + 1);
	}
	ans = min(ans, res);
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mn = *min_element(a+1,a+n+1);
	int lim = sqrt(mn) + 5;
	
	for(int i=1; i<=n; ++i) ans += a[i];
	for(int i=1; i<=lim; ++i)
	{
		chk_ans(i);
		chk_ans(mn / i);
		chk_ans(mn / i - 1);
	}
	
	printf("%lld",ans);
	return 0;
}