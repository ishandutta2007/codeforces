#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int n, m, k;
//vector<pi>V[nax];
int val[nax], last[nax];
ll sum[10][10];
pi edge[nax];
int deg[nax];
int ans;
ll all;

void rec(int cur, ll cur_sum) {
	if(cur == k + 1) {
		if(cur_sum == all) {
			ans++;
		}
		return;
	}
	for(int i = 1; i <= cur; ++i) {
		rec(cur + 1, cur_sum + sum[cur][i]);
	}
}

int main() {_
	cin >> n >> m >> k;
	for(int a,b,c,i=1; i <= m; ++i) {
		cin >> a >> b >> c;
		edge[c] = {a,b};
		deg[a]++;
	}
	for(int i = 1; i <= n; ++i) {
		val[i] = rng() % (1000000000);
		all += val[i];
	}
	for(int i = 1; i <= m; ++i) {
		sum[deg[edge[i].ST]][++last[edge[i].ST]] += val[edge[i].ND];
	}
	rec(1, 0);
	cout << ans;
}