#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 300'000 + 10, kax = 1e6;
int n, m, q;
int pls[nax], mins[nax];
int T[(1 << 21)], R, F[(1 << 21)];

void upd(int a, int x) {
	a += R;
	T[a] += x;
	F[a] = min(T[a], 0);
	while(a > 1) {
		a /= 2;
		T[a] = T[2*a]+T[2*a+1];
		F[a] = min(F[2*a], T[2*a] + F[2*a+1]);
	}
}

int qr() {
	int v = 1, add = 0;
	while(v < R) {
		if(add + F[2 * v] < 0) {
			v = v * 2;
		} else {
			add += T[2 * v];
			v = v * 2 + 1;
		}
	}
	if(add + T[v] < 0) {
		return v - R;
	} else {
		return kax + 1;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	R = (1 << 20);
	for(int i = 1; i <= n; ++i) {
		cin >> mins[i];
		mins[i] = -mins[i] + kax;
		upd(mins[i], -1);
	}
	for(int i = 1; i <= m; ++i) {
		cin >> pls[i];
		pls[i] = -pls[i] + kax;
		upd(pls[i], 1);
	}
	cin >> q;
	while(q--) {
		int e, id, val;
		cin >> e >> id >> val;
		if(e == 1) {
			upd(mins[id], 1);
			mins[id] = -val+kax;
			upd(mins[id], -1);
		} else {
			upd(pls[id], -1);
			pls[id] = -val+kax;
			upd(pls[id], 1);
		}
		cout << kax - qr() << "\n";
	}
}