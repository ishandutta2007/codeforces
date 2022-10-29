#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9 * 2;		
const int MAXN = 111111;
const int MAXK = 20;

struct query {
	int type, id;
	int x;
	
	query() {};
	query(int a, int b, int c): type(a), id(b), x(c) {};
};

bool operator<(query a, query b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.type < b.type;
}

int n, m;
pii songs[MAXN];
int ans[MAXN];
pair<int, pii> actors[MAXN];
vector<query> q;
set<pii> a;

int main() {

	cin >> n;
	forn(i, n)
		scanf("%d%d", &songs[i].X, &songs[i].Y);
		
	cin >> m;
	forn(i, m)
		scanf("%d%d%d", &actors[i].Y.X, &actors[i].Y.Y, &actors[i].X); 

	forn(i, n) {
		q.pb(query(1, i, songs[i].X)); 
	}        
	forn(i, m) {
		q.pb(query(0, i, actors[i].Y.X)); 
		q.pb(query(2, i, actors[i].Y.Y)); 
	}
		
	a.insert(mp(INF, INF));
	
	sort(all(q));
	forn(i, q.size()) {
		if (q[i].type == 0) {
			//printf("ACTOR OPEN %d\n", q[i].id);
			
			int id = q[i].id;
			a.insert(mp(actors[id].Y.Y, id));
		} else if (q[i].type == 2) {
			//printf("ACTOR CLOSED %d\n", q[i].id);
			
			int id = q[i].id;
			if (actors[id].X != 0)
				a.erase(mp(actors[id].Y.Y, id));
		} else if (q[i].type == 1) {
			//printf("SONG %d\n", q[i].id);
			
			int id = q[i].id;
		 	auto f = a.lower_bound(mp(songs[id].Y, -1));
		 	if (f->X == INF) {
		 		cout << "NO\n";
		 		return 0;
		 	} else {
		 		int aid = f->Y;
		 		ans[id] = aid;
		 		actors[aid].X--;
		 		if (actors[aid].X == 0)
		 			a.erase(f);	
		 	}
		}		
	}
	
	cout << "YES\n";
	forn(i, n)
		cout << ans[i] + 1 << ' ';
		
	return 0;
}