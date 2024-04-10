#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
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
const int nax = 1e5 + 5;

int t[nax];
ll dp[nax];
ll suf[nax];

int main() {
	int n;
	scanf("%d", &n);
	RI(i, n) scanf("%d", &t[i]);
	sort(t + 1, t + n + 1);
	RI(b, n) RI(a, b-1) ++dp[t[b]-t[a]];
	FORD(i, nax-2, 0) suf[i] = suf[i+1] + dp[i];
	ll ans = 0;
	RI(i, 5005) RI(j, 5005-i) ans += dp[i] * dp[j] * suf[i+j+1];
	ld m = n * (n - 1) / 2;
	ld tmp = ans / m / m / m;
	printf("%.10lf\n", double(tmp));
	return 0;
}