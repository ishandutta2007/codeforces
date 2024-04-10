#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline bool in_seg(int l,int r,int x)
{
	if(l>r) swap(l,r);
	return l <= x && x <= r;
}

ll t[MAXN];
int x[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld%d",&t[i],&x[i]);
	t[n+1] = linf;
	
	int at = 0, to = 0, ans = 0;
	for(int i=1; i<=n; ++i)
	{
		if(at == to) to = x[i];
		
		int lst = at;
		ll tm = t[i+1] - t[i];
		if(abs(to - at) <= tm) at = to;
		else at = to < at? at - tm: at + tm;
		
		if(in_seg(lst, at, x[i])) ++ans;
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}