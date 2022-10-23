#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXA = 1e6 + 5;

vector<int> fact[MAXA];

int n;
pii a[MAXN];

int mxlef[MAXN], mxrig[MAXN], mnrig[MAXN], pos[MAXA];

ll getres(void)
{
	static int sta[MAXN];
	int tp = 0; sta[tp] = 0;
	for(int i=1; i<=n; ++i)
	{
		while(tp && a[sta[tp]] < a[i])
			mxrig[sta[tp]] = i-1, --tp;
		mxlef[i] = sta[tp] + 1;
		mxrig[i] = n;
		sta[++tp] = i;
	}
	
	tp = 0;
	for(int i=1; i<=n; ++i)
	{
		while(tp && a[sta[tp]] > a[i])
			mnrig[sta[tp]] = i-1, --tp;
		mnrig[i] = n;
		sta[++tp] = i;
	}
	
	ll res = 0;
	tp = 0;
	for(int i=1; i<=n; ++i)
	{
		while(tp && a[sta[tp]].first >= a[i].first)
		{
			pos[a[sta[tp]].first] = 0;
			--tp;
		}
		sta[++tp] = i;
		pos[a[i].first] = tp;
		
		for(int x: fact[a[i].first])
		{
			int t = pos[x];
			if(t == 0) continue;
			if(sta[t] < mxlef[i]) continue;
			res += (ll)(sta[t] - max(mxlef[i], sta[t-1]+1) + 1)
				* (min(mxrig[i], mnrig[sta[t]]) - i + 1);
		}
	}
	while(tp) pos[a[sta[tp]].first] = 0, --tp;
	return res;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].first), a[i].second = i;
	
	ll ans = getres();
	reverse(a+1, a+n+1);
	ans += getres();
	ans -= n;
	printf("%lld\n",ans);
}

int main(void)
{
	for(int i=1; i<MAXA; ++i)
		for(int j=i; j<MAXA; j+=i)
			fact[j].emplace_back(i);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}