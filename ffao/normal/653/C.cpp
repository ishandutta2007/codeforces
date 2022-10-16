#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int a[160000];
vector<int> not_nice;
bool is_nice[160000];
int n;

bool cnice(int i) {
	bool nic = true;
	if (i % 2 == 0) {
		if (i != n-1 && a[i] >= a[i+1]) nic = false;
		if (i != 0 && a[i] >= a[i-1]) nic = false;
	}
	else {
		if (i != n-1 && a[i] <= a[i+1]) nic = false;
		if (i != 0 && a[i] <= a[i-1]) nic = false;
	}
	return nic;
}

bool check(int x, int y) {
	swap(a[x],a[y]);

	vector<int> m; 
	for (int i = x-1; i <= x+1; i++) if (i >= 0 && i < n) m.push_back(i);
	for (int i = y-1; i <= y+1; i++) if (i >= 0 && i < n) m.push_back(i);
	sort(m.begin(), m.end());
	int l = unique(m.begin(), m.end()) - m.begin();

	int c = 0;
	REP(i,l) {
		bool nn = cnice(m[i]);
		c += (nn - is_nice[m[i]]); 
	}	

	swap(a[x],a[y]);
	return c == (int)not_nice.size();
}

void solve() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &a[i]);

	REP(i,n) {
		is_nice[i] = cnice(i);
		if (!is_nice[i]) not_nice.push_back(i);
	}	

	if (not_nice.size() >= 8) {
		printf("0\n");
		return;
	}

	set< pair<int,int> > s;
	for (int p : not_nice) {
		for (int i = 0; i < n; i++) if (i != p) {
			if (check(i, p)) s.insert({min(i,p), max(i,p)});
		}
	}

	printf("%d\n", s.size());
}

int main() {
    solve();
}