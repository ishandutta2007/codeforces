#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 3005;

vi w[nax];
int d[nax][nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	REP(_, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	RI(i, n) {
		RI(j, n) d[i][j] = inf;
		d[i][i] = 0;
		queue<int> q;
		q.push(i);
		while(!q.empty()) {
			int a = q.front();
			q.pop();
			for(int b : w[a]) if(d[i][b] == inf) {
				d[i][b] = d[i][a] + 1;
				q.push(b);
			}
		}
	}
	int a[2],b[2],lim[2];
	REP(r, 2) scanf("%d%d%d", &a[r], &b[r], &lim[r]);
	int res = inf;
	RI(i,n)RI(j,n) REP(_, 2) {
		int dist[2];
		REP(r, 2) dist[r] = d[a[r]][i] + d[i][j] + d[j][b[r]];
		if(dist[0] <= lim[0] && dist[1] <= lim[1])
			mini(res, dist[0] + dist[1] - d[i][j]);
		swap(a[0], b[0]);
	}
	int dist[2];
	REP(r,2) dist[r] = d[a[r]][b[r]];
	if(dist[0] <= lim[0] && dist[1] <= lim[1])
		mini(res, dist[0] + dist[1]);
	printf("%d\n", res == inf ? -1 : m - res);
	return 0;
}