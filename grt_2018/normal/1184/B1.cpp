//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 1e5 + 10;
int n, m;
vector<pi>ship;
vector<pi>station;
ll ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	ship.resize(n); station.resize(m);
	for(int i = 0; i < n; ++i) {
		cin >> ship[i].ST;
		ship[i].ND = i;
	}
	for(int i = 0; i < m; ++i) {
		cin >> station[i].ST >> station[i].ND;
	}
	sort(station.begin(), station.end());
	sort(ship.begin(), ship.end());
	int ptr = 0;
	ll sum = 0;
	for(auto [a, id] : ship) {
		while(ptr < m && station[ptr].ST <= a) {
			sum += station[ptr].ND;
			ptr++;
		}
		ans[id] = sum;
	}
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
}