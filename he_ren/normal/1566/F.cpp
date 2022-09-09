#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
pii p[MAXM];
ll f[MAXN][2];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int mm = 0;
	for(int i=1; i<=m; ++i)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int pos = lower_bound(a+1,a+n+1,l) - a;
		if(pos <= n && a[pos] <= r) continue;
		p[++mm] = make_pair(r, -l);
	}
	m = mm;
	
	sort(p+1,p+m+1);
	
	int mxl = -inf;
	static pii tmp_p[MAXM];
	mm = 0;
	for(int i=1; i<=m; ++i)
	{
		int l = -p[i].second, r = p[i].first;
		if(l <= mxl) continue;
		tmp_p[++mm] = make_pair(l, r);
		mxl = l;
	}
	m = mm;
	for(int i=1; i<=m; ++i) p[i] = tmp_p[i];
	
	if(m == 0)
	{
		printf("0\n");
		return;
	}
	
	static int pos[MAXN];
	for(int i=1; i<=n; ++i)
		pos[i] = lower_bound(p+1,p+m+1,make_pair(a[i], -inf)) - p - 1;
	
	for(int i=1; i<=n; ++i)
		f[i][0] = f[i][1] = linf;
	f[1][1] = pos[1] == 0? 0: a[1] - p[1].second;
	f[1][0] = f[1][1] * 2;
	
	for(int i=1; i<n; ++i)
	{
		if(pos[i] == pos[i+1])
		{
			f[i+1][0] = f[i+1][1] = min(f[i][0], f[i][1]);
			continue;
		}
		int l = pos[i] + 1, r = pos[i+1];
		
		for(int t=l-1; t<=r; ++t)
		{
			ll x = 0, y = 0;
			if(t >= l) x = p[t].first - a[i];
			if(t < r) y = a[i+1] - p[t+1].second;
			
			for(int j=0; j<=1; ++j)
				for(int k=0; k<=1; ++k)
				{
					ll xx = j == 1? x + x: x;
					ll yy = k == 0? y + y: y;
					f[i+1][k] = min(f[i+1][k], f[i][j] + xx + yy);
				}
		}
	}
	
	ll tmp = pos[n] == m? 0: p[m].first - a[n];
	f[n][0] += tmp; f[n][1] += tmp * 2;
	printf("%lld\n",min(f[n][0], f[n][1]));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}