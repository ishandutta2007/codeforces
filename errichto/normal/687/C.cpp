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
const int nax = 505;

bool dp[nax][nax];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	dp[0][0] = true;
	REP(_, n) {
		int x;
		scanf("%d", &x);
		FORD(i, nax - 1, 0) FORD(j, nax - 1, 0) if(dp[i][j]) {
			if(i + x < nax) dp[i+x][j] = true;
			if(j + x < nax) dp[i][j+x] = true;
		}
	}
	vi ans;
	FOR(i, 0, k) if(dp[i][k-i]) ans.pb(i);
	printf("%d\n", sz(ans));
	for(int x : ans) printf("%d ", x);
	puts("");
	return 0;
}