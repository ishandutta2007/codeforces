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

const int nax = 100 * 1000 + 10;
int n, m;
int T[(1 << 18)], R;
ll T2[(1 << 18)];

void upd(int a, int x) {
	a += R;
	T[a] = x;
	T2[a] = x;
	while(a > 1) {
		a /= 2;
		T[a] = max(T[2*a], T[2*a+1]);
		T2[a] = T2[a*2] + T2[a*2+1];
	}
}

int get_mx(int v) {
	while(v < R) {
		if(T[2*v] >= T[2*v+1]) {
			v = v * 2;
		} else {
			v = v * 2 + 1;
		}
	}
	return v - R;
}

ll qr(int a, int b) {
	a += R; b += R;
	ll w = T2[a];
	if(a != b) w += T2[b];
	while(a/2!=b/2) {
		if(a%2==0) w += T2[a + 1];
		if(b % 2 == 1) w += T2[b - 1];
		a /= 2;
		b /= 2;
	}
	return w;
}

void fixSegment(int v, int mod) {
	while(T[v] >= mod) {
		int id = get_mx(v);
		upd(id, T[v] % mod);
	}
}

void get_mod(int a, int b, int mod) {
	a += R; b += R;
	fixSegment(a,mod);
	fixSegment(b,mod);
	while(a / 2 != b/ 2) {
		if(a % 2 == 0) fixSegment(a + 1,mod);
		if(b % 2 == 1) fixSegment(b - 1,mod);
		a /= 2;
		b /= 2;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	R = 1;
	while(R <= n) R *= 2;
	for(int a, i = 1; i <= n; ++i) {
		cin >> a;
		upd(i, a);
	}
	while(m--) {
		int t;
		cin >> t;
		if(t == 1) {
			int l, r;
			cin >> l >> r;
			cout << qr(l,r) << "\n";
		} else if(t == 2) {
			int l, r, mod;
			cin >> l >> r >> mod;
			get_mod(l,r,mod);
		} else {
			int a, k;
			cin >> a >> k;
			upd(a, k);
		}
	}
}