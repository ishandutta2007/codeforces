#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 5e6 + 5;

int a[MAXN];

void solve(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) cin >> a[i];
	
	static bool has[MAXM];
	memset(has, 0, m+2);
	for(int i=1; i<=n; ++i) has[a[i]] = 1;
	
	static int f[MAXM], cnt[MAXM];
	fill(f+1, f+m+1, m+1);
	memset(cnt, 0, (m+2)<<2);
	for(int i=1; i<=m; ++i)
		if(has[i]) ++cnt[m+1];
	
	auto upd = [&] (int i,int k)
	{
		if(f[i] <= k) return;
		if(has[i]) --cnt[f[i]];
		f[i] = k;
		if(has[i]) ++cnt[f[i]];
	};
	
	int ans = m+1;
	for(int i=m,j=m+1; i>=1; --i)
	{
		upd(i, i);
		if(i > 1)
		{
			for(ll k=(ll)i*i; k<=m; k+=i)
				upd(k, f[k/i]);
		}
		while(!cnt[j]) --j;
		if(j <= m)
			ans = min(ans, j-i);
	}
	cout << ans << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}