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
const int nax = 2005;
const int pot = 2 * 1024;

int t[nax], goal[nax];
int nn[nax], pp[nax];
bool removed[nax];

void remove(int a) {
	removed[a] = true;
	nn[pp[a]] = nn[a];
	pp[nn[a]] = pp[a];
}

vector<pii> res;
ll S;

void check(int a) {
	int b = nn[a];
	if(b == 0) return;
	if(goal[t[a]] > a && goal[t[b]] < b) {
		res.pb(mp(a,b));
		S += abs(a-b);
		swap(t[a], t[b]);
		if(goal[t[a]] == a) remove(a);
		if(goal[t[b]] == b) remove(b);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,0,n) nn[i] = i + 1;
	FOR(i,1,n+1) pp[i] = i - 1;
	RI(i, n) scanf("%d", &t[i]);
	RI(i, n) {
		int x;
		scanf("%d", &x);
		goal[x] = i;
	}
	RI(i, n) if(goal[t[i]] == i) remove(i);
	REP(rep, max(20 *  n, 10000)) {
		if(rand()%2) {
			for(int i = nn[0]; i <= n; i = nn[i])
				if(!removed[i])
					check(i);
		}
		else {
			for(int i = pp[n+1]; i >= 1; i = pp[i])
				if(!removed[i])
					check(i);
		}
	}
	printf("%lld\n", S);
	printf("%d\n", sz(res));
	for(pii p : res) printf("%d %d\n", p.st, p.nd);
	return 0;
}