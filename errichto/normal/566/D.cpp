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
const int nax = 1e6 + 5;

set<int> s;
int gr[nax], n;
vi odw[nax];

void ogarnij(int a) {
	if(1 <= a && a <= n - 1) {
		s.erase(a);
		if(gr[a] != gr[a+1]) s.insert(a);
	}
}

void merge(int a, int b) {
	if(a == b) return;
	if(sz(odw[a]) > sz(odw[b])) swap(a,b);
	// a mniejsze
	for(int c : odw[a]) {
		gr[c] = b;
		odw[b].pb(c);
	}
	for(int c : odw[a]) {
		ogarnij(c);
		ogarnij(c-1);
	}
	odw[a].clear();
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int q;
	scanf("%d%d", &n, &q);
	RI(i, n - 1) s.insert(i);
	RI(i, n) {
		gr[i] = i;
		odw[i].pb(i);
	}
	while(q--) {
		int rodz, x, y;
		scanf("%d%d%d", &rodz, &x, &y);
		if(rodz == 1) merge(gr[x], gr[y]);
		else if(rodz == 2) {
			while(true) {
				auto it = s.lower_bound(x);
				if(it == s.end()) break;
				int c = *it;
				if(c >= y) break;
				merge(gr[c], gr[c+1]);
			}
		}
		else {
			assert(rodz == 3);
			puts(gr[x] == gr[y] ? "YES" : "NO");
		}
	}
	
	return 0;
}