#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 512 * 1024;
const int pot = 512 * 1024;

int w, h, ile_wiez, q;
pii wieza[nax];
pii zap[nax][2];
int tr[2 * pot];
bool res[nax]; // tego nie zeruje!!!
vi vec[nax];
vi zapy[nax];

void f() {
	REP(i, 2 * pot) tr[i] = inf;
	REP(i, nax) vec[i].clear();
	REP(i, nax) zapy[i].clear();
	RI(i, ile_wiez) vec[wieza[i].y].pb(wieza[i].x);
	RI(i, q) zapy[zap[i][0].y].pb(i);
	FORD(Y, nax - 1, 0) {
		for(auto a : vec[Y]) {
			tr[pot + a] = Y;
			for(int i = (pot + a) / 2; i; i /= 2)
				tr[i] = max(tr[2*i], tr[2*i+1]);
		}
		for(auto i : zapy[Y]) {
			int low = pot + zap[i][0].x;
			int high = pot + zap[i][1].x;
			int m = max(tr[low], tr[high]);
			while(low < high - 1) {
				maxi(m, tr[low+1]);
				maxi(m, tr[high-1]);
				low /= 2;
				high /= 2;
			}
			if(m <= zap[i][1].y) res[i] = true;
		}
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	scanf("%d%d", &w, &h);
	scanf("%d%d", &ile_wiez, &q);
	RI(i, ile_wiez) scanf("%d%d", &wieza[i].x, &wieza[i].y);
	RI(i, q) REP(j, 2) scanf("%d%d", &zap[i][j].x, &zap[i][j].y);
	f();
	swap(w, h);
	RI(i, ile_wiez) swap(wieza[i].x, wieza[i].y);
	RI(i, q) REP(j, 2) swap(zap[i][j].x, zap[i][j].y);
	f();
	RI(i, q) puts(res[i] ? "YES" : "NO");
	
	return 0;
}