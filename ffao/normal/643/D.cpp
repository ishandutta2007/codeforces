#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, q;
long long t[110000];

set< pair<long long, int> > global_list;
set< pair<long long, int> > local_lists[110000];
int number_of_children[110000];
vector<int> adj[110000];
int parent[110000];
long long my_val[110000];

void erase_globals(int i) {
	long long k = number_of_children[i] + 2;
	if (number_of_children[i]) {
		pair<long long, int> pp = *local_lists[i].begin();
		pp.first += t[i]/k;
		global_list.erase(pp);
	}
	if (number_of_children[i] > 1) {
		pair<long long, int> pp = *local_lists[i].rbegin();
		pp.first += t[i]/k;
		global_list.erase(pp);
	}
}

void refresh_globals(int i) {
	long long k = number_of_children[i] + 2;
	if (number_of_children[i]) {
		pair<long long, int> pp = *local_lists[i].begin();
		//printf("val = %lld\n", pp.first);
		pp.first += t[i]/k;
		//printf("adding %lld %d from %d\n", pp.first, pp.second, i);
		global_list.insert(pp);
	}
	if (number_of_children[i] > 1) {
		pair<long long, int> pp = *local_lists[i].rbegin();
		pp.first += t[i]/k;
		global_list.insert(pp);
		//printf("adding %lld %d from %d\n", pp.first, pp.second, i);
	}
}

void unattach(int v) {
	long long kp = number_of_children[parent[v]]+2;

	erase_globals(parent[v]);
	local_lists[parent[v]].erase({my_val[v],v});
	number_of_children[parent[v]]--;
	refresh_globals(parent[v]);

	erase_globals(parent[parent[v]]);
	local_lists[parent[parent[v]]].erase({my_val[parent[v]], parent[v]});
	my_val[parent[v]] -= t[v] / (number_of_children[v]+2);
	my_val[parent[v]] += (kp-1) * (t[parent[v]]/kp);
	kp--;
	my_val[parent[v]] -= (kp-1) * (t[parent[v]]/kp);
	local_lists[parent[parent[v]]].insert({my_val[parent[v]], parent[v]});
	refresh_globals(parent[parent[v]]);

	int np = parent[v];
	erase_globals(parent[parent[np]]);
	local_lists[parent[parent[np]]].erase( {my_val[parent[np]], parent[np]});
	my_val[parent[np]] += (t[np]/(number_of_children[np]+2)) - (t[np]/(number_of_children[np]+3));
	local_lists[parent[parent[np]]].insert( {my_val[parent[np]], parent[np]} );
	refresh_globals(parent[parent[np]]);
}

void attach(int v, int np) {
	parent[v] = np;

	erase_globals(np);
	number_of_children[np]++;
	local_lists[np].insert({my_val[v],v});
	refresh_globals(np);

	erase_globals(parent[np]);
	local_lists[parent[np]].erase({my_val[np], np});
	my_val[np] += t[v] / (number_of_children[v]+2);
	my_val[np] += (number_of_children[np]) * (t[np]/(number_of_children[np]+1));
	my_val[np] -= (number_of_children[np]+1) * (t[np]/(number_of_children[np]+2));
	local_lists[parent[np]].insert({my_val[np], np});
	refresh_globals(parent[np]);

	erase_globals(parent[parent[np]]);
	local_lists[parent[parent[np]]].erase( {my_val[parent[np]], parent[np]});
	my_val[parent[np]] += (t[np]/(number_of_children[np]+2)) - (t[np]/(number_of_children[np]+1));
	local_lists[parent[parent[np]]].insert( {my_val[parent[np]], parent[np]} );
	refresh_globals(parent[parent[np]]);
}


void solve() {
	scanf("%d %d", &n, &q);
	REP(i,n) scanf("%lld", &t[i]);
	REP(i,n) {
		scanf("%d", &parent[i]); parent[i]--;
		adj[parent[i]].push_back(i);
		number_of_children[parent[i]]++;
	}

	REP(i,n) {
		long long k = adj[i].size() + 2;
		my_val[i] += t[i] - (k-1)*(t[i]/k);
		my_val[parent[i]] += t[i]/k;
	}
	REP(i,n) local_lists[parent[i]].insert( {my_val[i], i} );

	REP(i,n) refresh_globals(i);

	REP(i,q) {
		int ty;
		scanf("%d", &ty);

		//fprintf(stderr, "process %d\n", ty);

		if (ty == 3) {
			printf("%lld %lld\n", global_list.begin()->first, global_list.rbegin()->first);
		}

		if (ty == 2) {
			int v;
			scanf("%d", &v); v--;
			long long k = number_of_children[parent[v]]+2;
			//printf("val = %lld\n", my_val[v]);
			printf("%lld\n", my_val[v] + (t[parent[v]] / k));
		}

		if (ty == 1) {
			int v, np;
			scanf("%d %d", &v, &np); v--; np--;

			unattach(v);
			attach(v, np);
		}
	}
}

int main() {
    solve();
}