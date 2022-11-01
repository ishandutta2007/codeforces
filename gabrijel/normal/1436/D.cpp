#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

struct cvor {
	ll listovi = 0, maxi = 0, slobodni = 0;
	vector <int> sus;
	cvor() {}
};

vector <cvor> graf;
vector <ll> poc;

void dfs(int tr) {
	if(!(graf[tr].sus).size()) {
		graf[tr].listovi = 1;
		graf[tr].maxi = poc[tr];
		graf[tr].slobodni = 0;
		return;
	}
	ll listovi = 0, maxi = 0, slobodni = 0;
	for(int sus : graf[tr].sus) {
		dfs(sus);
		listovi += graf[sus].listovi;
		maxi = max(maxi, graf[sus].maxi);
	}
	graf[tr].listovi = listovi;
	graf[tr].maxi = maxi;
	for(int sus : graf[tr].sus) {
		slobodni += graf[sus].slobodni + (maxi - graf[sus].maxi) * graf[sus].listovi;
	}
	graf[tr].slobodni = slobodni;
	if(slobodni >= poc[tr]) {
		graf[tr].slobodni -= poc[tr];
	}
	else {
		poc[tr] -= slobodni;
		graf[tr].maxi += (poc[tr] + listovi - 1) / (listovi);
		graf[tr].slobodni = listovi - (poc[tr]) % (listovi);
		if(graf[tr].slobodni == listovi) graf[tr].slobodni = 0;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	cin >> n;
	REP(i, n) graf.push_back(cvor());
	poc.resize(n, 0);
	REP(i, n - 1) {
		cin >> a;
		a--;
		graf[a].sus.push_back(i + 1);
	}
	REP(i, n) cin >> poc[i];
	dfs(0);
	cout << graf[0].maxi << "\n";
	return 0;
}