#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXX = 1e6 + 5;

inline void Yes(void){ printf("Yes"), exit(0);}
inline void No(void){ printf("No"), exit(0);}

void solve(void)
{
	ll d, nl, nr, t, x, y;
	scanf("%lld%lld%lld%lld%lld%lld",&d,&nl,&nr,&t,&x,&y);
	ll n = nr - nl;
	d -= nl;
	
	if(y < x)
	{
		if(d + y <= n) d += y;
		if(d - x < 0) No();
		d -= x;
		--t;
		
		if(d / (x - y) >= t) Yes();
		else No();
	}
	
	ll res = d / x; d %= x;
	if(res >= t) Yes();
	
	ll len = y / x, del = y % x;
	static bool vis[MAXX];
	
	while(1)
	{
		vis[d] = 1;
		if(d + y > n) break;
		int nxt = (d + del) % x;
		res += len;
		if(vis[nxt]) Yes();
		d = nxt;
	}
	
	if(res >= t) Yes();
	else No();
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}