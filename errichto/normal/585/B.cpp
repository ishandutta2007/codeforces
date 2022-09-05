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
const int nax = 105;

bool dp[3][nax];
char sl[3][nax];
int n;

bool empty(int i, int j) {
	if(j >= n) return true;
	return sl[i][j] == '.' || sl[i][j] == 's';
}

bool te() {
	int k;
	scanf("%d%d", &n, &k);
	REP(i, 3) scanf("%s", sl[i]);
	REP(i,3)REP(j,nax) dp[i][j] = false;
	REP(i,3) dp[i][0] = (sl[i][0] == 's');
	REP(turn, n) {
		REP(i, 3) if(dp[i][turn]) {
			if(turn == n - 1) return true;
			if(!empty(i,turn+1+turn*2)) continue;
			REP(j,3) if(abs(i-j) <= 1) {
				bool ok = true;
				REP(he, 3)
					if(!empty(j,turn+1+turn*2+he)) ok = false;
				if(ok) dp[j][turn+1] = true;
			}
		}
	}
	return false;
}

int main() {
	int z;
	scanf("%d", &z);
	while(z--) puts(te() ? "YES" : "NO");
	return 0;
}