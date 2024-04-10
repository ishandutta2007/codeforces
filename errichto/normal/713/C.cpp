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
const int nax = 4005;
const ll INF = 3e18 + 6423;

int t[nax];
int value[nax];
map<int,int> m;
ll dp[nax];

int main() {
	int n;
	scanf("%d", &n);
	set<int> s;
	REP(i, n) {
		scanf("%d", &t[i]);
		t[i] -= i;
		s.insert(t[i]);
	}
	//REP(i, n) printf("%d ", t[i]);
	//puts("");
	int k = 0;
	for(int x : s) {
		value[k] = x;
		m[x] = k++;
	}
	REP(i, k) dp[i] = abs(t[0] - value[i]);
	RI(i, n - 1) {
		ll so_far = INF;
		REP(j, k) {
			mini(so_far, dp[j]);
			dp[j] = so_far + abs(t[i] - value[j]);
			// so_far += value[j+1] - value[j];
		}
	}
	ll ans = INF;
	REP(i, k) mini(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}