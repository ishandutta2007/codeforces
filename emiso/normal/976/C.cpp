#include <bits/stdc++.h>

using namespace std;

int n, lc, rc;

struct seg {
	int l, r, id;
	bool operator <(const seg &o) const {
		if(r == o.r) return l > o.l;
		return r < o.r;
	}	
};
vector<seg> v;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &lc, &rc);
		v.push_back(seg{lc, rc, i});
	}
	sort(v.begin(), v.end());
	
	set<pair<int, int> > lbs;
	for(seg sg : v) {
		if(!lbs.empty()) { 
			auto mx = *(lbs.rbegin());
			if(sg.l <= mx.first) {
				printf("%d %d\n", mx.second + 1, sg.id + 1);
				return 0;
			}
		}	
		lbs.insert({sg.l, sg.id});
	}
	
	puts("-1 -1");
	return 0;
}