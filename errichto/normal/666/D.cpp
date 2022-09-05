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
const int nax = 1e6 + 5;

int dist(int x1, int y1, int x2, int y2) {
	int maybe = inf;
	if(x1 == x2) mini(maybe, abs(y2 - y1));
	if(y1 == y2) mini(maybe, abs(x1 - x2));
	return maybe;
}

int x[4], y[4];

vi ans;


int check_sq(int x1, int x2, int y1, int y2) {
	assert(abs(x1-x2) == abs(y1-y2));
	assert(x1 != x2);
	assert(y1 != y2);
	vector<pii> goal;
	goal.pb(mp(x1,y1));
	goal.pb(mp(x1,y2));
	goal.pb(mp(x2,y1));
	goal.pb(mp(x2,y2));
	vi p;
	REP(i, 4) p.pb(i);
	int best = inf;
	do {
		vi maybe = vi{0};
		REP(i, 4) {
			int j = p[i];
			int d = dist(x[i], y[i], goal[j].first, goal[j].second);
			if(d == inf) {
				maybe[0] = inf;
				break;
			}
			maxi(maybe[0], d);
			maybe.pb(goal[j].first);
			maybe.pb(goal[j].second);
		}
		mini(best, maybe[0]);
		if(maybe[0] < ans[0])
			ans = maybe;
	} while(next_permutation(p.begin(), p.end()));
	return best;
}

int check_sq_x(int x1, int x2, int y1) {
	int best = inf;
	mini(best, check_sq(x1, x2, y1, y1 - abs(x2-x1)));
	mini(best, check_sq(x1, x2, y1, y1 + abs(x2-x1)));
	return best;
}

int check_sq_y(int x, int y1, int y2) {
	int best = inf;
	mini(best, check_sq(x, x + abs(y1-y2), y1, y2));
	mini(best, check_sq(x, x - abs(y1-y2), y1, y2));
	return best;
}

void te() {
	ans = vi{inf};
	set<int> xx, yy;
	REP(i, 4) {
		scanf("%d%d", &x[i], &y[i]);
		xx.insert(x[i]);
		yy.insert(y[i]);
	}
	for(int x1 : xx) for(int x2 : xx) if(x1 < x2) for(int y : yy)
		check_sq_x(x1, x2, y);
	
	for(int y1 : yy) for(int y2 : yy) if(y1 < y2) for(int x : xx)
		check_sq_y(x, y1, y2);
	
	const int M = 300 * 1000 * 1000;
	
	for(int x1 : xx) for(int x2 : xx) if(x1 < x2) {
		int low = -M;
		int high = M + 12582;
		while(high - low > 20) {
			int one = low + (high - low) * 1 / 3;
			int two = low + (high - low) * 2 / 3;
			if(check_sq_x(x1, x2, one) < check_sq_x(x1, x2, two))
				high = two;
			else
				low = one;
		}
		FOR(i, low, high)
			check_sq_x(x1, x2, i);
	}
	for(int y1 : yy) for(int y2 : yy) if(y1 < y2) {
		int low = -M;
		int high = M + 12582;
		while(high - low > 20) {
			int one = low + (high - low) * 1 / 3;
			int two = low + (high - low) * 2 / 3;
			if(check_sq_y(one, y1, y2) < check_sq_y(two, y1, y2))
				high = two;
			else
				low = one;
		}
		FOR(i, low, high)
			check_sq_y(i, y1, y2);
	}
	
	if(ans[0] == inf) {
		puts("-1");
	}
	else {
		REP(i, (int) ans.size()) {
			printf("%d ", ans[i]);
			if(i % 2 == 0) puts("");
		}
	}
}

int main() {
	int z;
	scanf("%d", &z);
	while(z--) te();
	return 0;
}