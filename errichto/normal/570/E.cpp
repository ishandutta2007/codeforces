#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= (b); ++i)
#define FORD(i,a,b) for(int i = a; i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 505;
const int mod = 1e9 + 7;

int dp[2][nax][nax];
char sl[nax][nax];
int h, w;

bool ok(int x, int y) {
	return 0 <= x && x < w && 0 <= y && y < h;
}

int main()
{
	scanf("%d%d", &h, &w);
	if(h == 1 && w == 1) {
		puts("1");
		return 0;
	}
	REP(i, h) scanf("%s", sl[i]);
	if(sl[0][0] != sl[h-1][w-1]) {
		puts("0");
		return 0;
	}
	/*if(h > w) {
		REP(i, h) REP(j, i) swap(sl[i][j], sl[j][i]);
		swap(h,w);
	}*/
	dp[0][0][w-1] = 1;
	int res = 0;
	for(int s = 1; true; ++s) {
		int k = s % 2;
		REP(i,nax)REP(j,nax)dp[k][i][j] = 0;
		for(int x = 0; x <= s; ++x) {
			int y = s - x;
			if(!ok(x,y)) continue;
			for(int xd = 0; xd <= s; ++xd) {
				int xx = w-1-xd;
				int yy = h-1-(s-xd);
				if(!ok(xx,yy)) continue;
				ll me = 0;
				if(sl[y][x] == sl[yy][xx]) {
					me += dp[k^1][x][xx];
					if(x)me += dp[k^1][x-1][xx];
					if(xx+1<w)me += dp[k^1][x][xx+1];
					if(x && xx+1<w) me += dp[k^1][x-1][xx+1];
					//printf("%d %d - %lld\n", x, xx, me);
				}
				while(me >= mod) me -= mod;
				dp[k][x][xx] = me;
				if(2 * s + 2 == w + h && x == xx)
					res = (res + (ll) dp[k][x][x]) % mod;
				if(2 * s + 3 == w + h && (x == xx || x + 1 == xx))
					res = (res + dp[k][x][xx]) % mod;
			}
		}
		if(2 * s + 2 == w + h || 2 * s + 3 == w + h) break;
		//puts("");
	}
	printf("%d\n", res);
	return 0;
}