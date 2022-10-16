#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n;
pair< pair<int,int>, pair<int, int> > p[110000];
vector< pair<int, pair<int, int> > > events[110000];
long long ans[110000];

int main() {
	scanf("%d %*d", &n);
	REP(i,n) {
		scanf("%d %d %d", &p[i].first.first, &p[i].second.first, &p[i].second.second);
		p[i].first.second = i;
	}

	sort(p,p+n);
	int waiting = 0;
	int pri = 0;
	int loc = 1;
	int la = 0;
	long long t = 1;
	set<int> eventful_floors;

	while (1) {
		while (la < n && p[la].first.first <= t) {
			int ori = p[la].second.first;
			int ws = 0;
			if (ori > loc) ws++;
			else if (ori < loc) ws--; 
			events[ori].push_back({la, {1, ws}});
			pri += ws;
			la++;
			eventful_floors.insert(ori);
			waiting++;
		}

		for (pair<int, pair<int, int> > cp : events[loc]) {
			pri -= cp.second.second;
			if (cp.second.first == 1) {
				int wanted_floor = p[cp.first].second.second;
				int gs = 0;
				if (wanted_floor > loc) gs++;
				else gs--;
				pri += gs;
				events[ wanted_floor ].push_back({cp.first, {-1, gs}});
				eventful_floors.insert(wanted_floor);
			}
			else {
				ans[ p[cp.first].first.second ] = t;
				waiting--;
			}
		}
		events[loc].clear();
		eventful_floors.erase(loc);

		int dir = 0;
		if (waiting > 0) {
			dir = (pri>=0 ? 1 : -1);
		}

		long long nt = 1000000000000000000LL;
		if (la != n) nt = p[la].first.first;

		if (dir == 0) {
			if (la == n) break;
		}
		else if (dir == 1) {
			int nev = *eventful_floors.lower_bound(loc);
			nt = min(nt, t + nev - loc);
		}
		else {
			int nev = *(--eventful_floors.lower_bound(loc));
			nt = min(nt, t + loc - nev);
		}
		loc = loc + (nt-t)*dir;
		t = nt;
	}

	REP(i,n) printf("%lld\n", ans[i]);
}