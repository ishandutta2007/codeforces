#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 2e5 + 5;

char s[MAXM];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	int m = strlen(s+1);
	if(s[1] == 'D')
	{
		for(int i=1; i<=m; ++i)
			s[i] = 'R' + 'D' - s[i];
	}
	int fir = find(s+1, s+m+1, 'D') - s;
	if(fir > m)
	{
		printf("%d\n",n);
		return;
	}
	
	static int mn[MAXM], mx[MAXM];
	memset(mn, 0x3f, (m+1)<<2);
	memset(mx, 0xc0, (m+1)<<2);
	int cx = 0, cy = 0;
	mn[0] = mx[0] = 0;
	for(int i=fir+1; i<=m; ++i)
	{
		if(s[i] == 'D') ++cx;
		else ++cy;
		mn[cy] = min(mn[cy], cx);
		mx[cy] = max(mx[cy], cx);
	}
	
	ll R = n-1, C = n-(fir-1);
	ll ans = R * C + (n - cy);
	for(int i=0; i<=cy; ++i)
	{
		ans -= cx - mx[i];
		ans -= mn[i];
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}