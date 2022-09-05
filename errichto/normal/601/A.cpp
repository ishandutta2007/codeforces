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
const int nax = 405;

bool kr[nax][nax];
int dp[nax];
bool vis[nax];

int solve(int n) {
	RI(i, n) dp[i] = inf;
	dp[0] = inf;
	dp[1] = 0;
	RI(i, n) vis[i] = false;
	REP(_, n) {
		int best = 0;
		RI(i, n) if(!vis[i]) if(dp[i] < dp[best]) best = i;
		if(best == 0) continue;
		vis[best] = true;
		RI(i, n) if(kr[best][i]) mini(dp[i], dp[best] + 1);
	}
	return dp[n];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		kr[a][b] = kr[b][a] = true;
	}
	int a = solve(n);
	RI(i, n) RI(j, n) if(i != j) kr[i][j] = !kr[i][j];
	int b = solve(n);
	//printf("%d %d\n", a, b);
	int r = max(a, b);
	if(r == inf) r = -1;
	printf("%d\n", r);
	return 0;
}