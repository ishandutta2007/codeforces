#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)im=*p=='-';while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);if(im)(x)=-(x);
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define MAXN (505)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

char str[MAXN][MAXN];
int mxy, mxx, mny, mnx, cnt;
int H, W;

int main() {
	scanf("%d%d", &H, &W);
	for(int i = 1; i <= H; i++) scanf(" %s", str[i]+1);
	mxy = mxx = -INF; mny = mnx = INF; cnt = 0;
	for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) {
		if('X' != str[i][j]) continue;
		upmin(mny, i); upmin(mnx, j);
		upmax(mxy, i); upmax(mxx, j);
		cnt++;
	}
	if(!cnt) { puts("NO"); return 0; }
	puts((mxy-mny+1) * (mxx-mnx+1) == cnt ? "YES" : "NO");
	return 0;
}