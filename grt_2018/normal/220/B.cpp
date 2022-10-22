#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100 * 1000 + 10;
int n, m;
int a[nax], cnt[nax], w[nax], ans[nax];
pi q[nax];
vi possible;


int main() {_
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] <= n) cnt[a[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(cnt[i] >= i) {
			possible.PB(i);
		}
	}
	for(int i = 1; i <= m; ++i) {
		cin >> q[i].ST >> q[i].ND;
	}
	for(int x : possible) {
		for(int i = 1; i <= n; ++i) w[i] = w[i - 1] + (a[i] == x);
		for(int i = 1; i <= m; ++i) {
			if(w[q[i].ND] - w[q[i].ST - 1] == x) {
				ans[i]++;
			}
		}
	}
	for(int i = 1; i <= m; ++i) {
		cout << ans[i] << "\n";
	}
	
	
}