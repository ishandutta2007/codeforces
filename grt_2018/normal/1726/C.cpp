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

const int nax = 200 * 1000 + 10;
int t, n;
string s;
vi V[nax];
bool vis[nax];

void dfs(int x) {
	vis[x] = true;
	for(auto nbh : V[x]) {
		if(!vis[nbh]) {
			dfs(nbh);
		}
	}
}

void solve() {
	cin >> n >> s;
	vi S = {};
	for(int i = 0; i < 2 * n; ++i) {
		V[i].clear();
		vis[i] = false;
	}
	for(int i = 0; i < 2 * n; ++i) {
		if(s[i] == '(') {
			S.PB(i);
		} else {
			V[S.back()].PB(i);
			V[i].PB(S.back());
			S.pop_back();
			if(i != 2 * n - 1 && s[i + 1] == '(') {
				V[i].PB(i + 1);
				V[i + 1].PB(i);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 2 * n; ++i) {
		if(!vis[i]) {
			ans++;
			dfs(i);
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}