#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXA = 2e6 + 5;

int a[MAXN];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> a[i];
	n = unique(a+1, a+n+1) - a - 1;
	
	int mxa = a[n];
	
	static int firleq[MAXA];
	for(int i=1; i<n; ++i)
		for(int j=a[i]; j<a[i+1]; ++j)
			firleq[j] = i;
	
	for(int beg=1;; ++beg)
	{
		if((ll)beg * beg + beg < a[1]) continue;
		
		bool ok = 1;
		
		int i = 1, x = beg;
		ll l = max(0ll, (ll)x * x - a[1]), r = (ll)x * x + x - a[1];
		while(i <= n)
		{
			ll need = (ll)x * x + x - l;
			i = need >= mxa? n: firleq[need];
			r = min(r, (ll)x * x + x - a[i]);
			if(++i > n) break;
			
			x = sqrt(a[i] + r);
			while((ll)x * x <= a[i] + r) ++x;
			while((ll)x * x > a[i] + r) --x;
			l = max(l, (ll)x * x - a[i]);
			r = min(r, (ll)x * x + x - a[i]);
			if(l > r){ ok = 0; break;}
		}
		
		if(ok)
		{
			cout << l;
			return 0;
		}
	}
	return 0;
}