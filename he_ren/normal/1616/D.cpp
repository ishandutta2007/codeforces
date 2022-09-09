#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e4 + 5;

int a[MAXN];
ll sum[MAXN], val[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	ll x;
	scanf("%lld",&x);
	
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + a[i];
		val[i] = sum[i] - x * i;
	}
	
	int ans = 0, lst = -1;
	
	static int sta[MAXN];
	int tp = 0;
	for(int i=1; i<=n; ++i)
	{
		if(tp && val[sta[1]] > val[i])
		{
			int l = 1, r = tp;
			while(l<r)
			{
				int mid = (l+r+1)>>1;
				if(val[sta[mid]] > val[i]) l = mid;
				else r = mid-1;
			}
			if(lst <= sta[l])
			{
				lst = i;
				++ans;
			}
		}
		while(tp && val[sta[tp]] <= val[i-1]) --tp;
		sta[++tp] = i-1;
	}
	
	printf("%d\n",n-ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}