#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int dx[30], dy[30];

char s[MAXN];

int maxx[MAXN], minx[MAXN], maxy[MAXN], miny[MAXN];
int mxx, mnx, mxy, mny;

ll ans = linf;

void check(int x,int y,int i)
{
	ll res = (ll)(max(mxx, x + maxx[i+1]) - min(mnx, x + minx[i+1]) + 1) * (max(mxy, y + maxy[i+1]) - min(mny, y + miny[i+1]) + 1);
	ans = min(ans, res);
}

void solve(void)
{
	dx['W' - 'A'] = -1; dx['S' - 'A'] = 1;
	dy['A' - 'A'] = -1; dy['D' - 'A'] = 1;
	
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	int x = 0, y = 0;
	for(int i=1; i<=n; ++i)
		x += dx[s[i] - 'A'], y += dy[s[i] - 'A'];
	
	maxx[n+1] = minx[n+1] = maxy[n+1] = miny[n+1] = 0;
	
	mxx = x; mnx = x; mxy = y; mny = y;
	for(int i=n; i>=1; --i)
	{
		x -= dx[s[i] - 'A']; y -= dy[s[i] - 'A'];
		mxx = max(mxx, x); mnx = min(mnx, x);
		mxy = max(mxy, y); mny = min(mny, y);
		
		maxx[i] = mxx - x; minx[i] = mnx - x;
		maxy[i] = mxy - y; miny[i] = mny - y;
	}
	
	ans = linf;
	
	x = 0; y = 0;
	mxx = mnx = mxy = mny = 0;
	for(int i=0; i<=n; ++i)
	{
		if(i) x += dx[s[i]-'A'], y += dy[s[i]-'A'];
		mxx = max(mxx, x); mnx = min(mnx, x);
		mxy = max(mxy, y); mny = min(mny, y);
		
		for(int k=0; k<26; ++k)
			check(x+dx[k], y+dy[k], i);
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