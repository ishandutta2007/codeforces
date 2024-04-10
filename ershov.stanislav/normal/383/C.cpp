#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int n, m, a[200100], nowt, used[200100], fenv[200100], d[200100];
vector<int> u[200100];
vector<int> t[200100];
pair<int, int> sb[200100];

void dfs(int i, int dd) {
	sb[i].first=nowt; nowt++;
	d[i]=dd;
	for (int j=0; j<(int)u[i].size(); j++) if (!used[u[i][j]]) {
		used[u[i][j]]=1;
		dfs(u[i][j], dd+1);
	}
	sb[i].second=nowt-1;
}

int get(int i) {
	if (i==-1) return 0;
	else {
		return fenv[i]+get((i&(i+1))-1);
	}
}

void inc(int i, int val) {
	for (; i<200010; i=i|(i+1)) fenv[i]+=val;
}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n-1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		u[a].push_back(b);
		u[b].push_back(a);
	}
	used[0]=1;
	dfs(0, 0);
	for (int i=0; i<m; i++) {
		int b, x, val;
		cin >> b >> x;
		x--;
		if (b==1) {
			cin >> val;
			if (d[x]%2) val=-val;
			inc(sb[x].first, val);
			inc(sb[x].second+1, -val);
		}
		else {
			val=get(sb[x].first);
			if (d[x]%2) val=-val;
			cout << val+a[x] << endl;
		}
	}
	return 0;
}