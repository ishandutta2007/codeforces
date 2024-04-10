#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


template <typename T> void sortv(std::vector<T> &v) {
	sort(v.begin(), v.end());
}


#include <algorithm>


int n;

vector< pair<int, int> > ev;

void solve() {
	scanf("%d", &n);	
	REP(i, n) {
		int x, w;
		scanf("%d %d", &x, &w);
		ev.push_back({x+w, x-w});
	}

	sortv(ev);

	int b = 0;
	int loc = ev[0].second - 1; 
	for (pii p : ev) {
		if (loc <= p.second) {
			b++;
			loc = p.first;
		}
	}

	printf("%d\n", b);
}


int main() {
    solve();
}