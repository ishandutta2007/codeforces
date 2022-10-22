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

const ll INF = 1e18;
int cur;

struct Line {
	ll a, b;
	int id;
	ll eval(int x) {
		if(id != cur) return INF;
		return (ll)min(a * x, INF) + b;
	}
};

const int nax = 200 * 1000 + 10;
int n;
int A[nax];
ll sum[nax];
Line T[(1<<23)];

void add(Line line, int l, int r, int v) {
	int mid = (l + r) / 2;
	bool lef = line.eval(l) < T[v].eval(l);
	bool m = line.eval(mid) < T[v].eval(mid);
	if(m) {
		swap(line, T[v]);
	}
	if(r - l == 1) {
		return;
	} else if(lef != m) {
		add(line, l, mid, 2 * v);
	} else {
		add(line, mid, r, 2 * v + 1);
	}
}

ll get(int x, int l, int r, int v) {
	int mid = (l + r) / 2;
	if(r - l == 1) {
		return T[v].eval(x);
	} else if(x < mid) {
		return min(T[v].eval(x), get(x, l, mid, v * 2));
	} else {
		return min(T[v].eval(x), get(x, mid, r, v * 2 + 1));
	}
}

int main() {_
	cin >> n;
	int mx = -1000*1000, mi = 1000*1000;
	ll init = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> A[i];
		init += (ll)i * A[i];
		mx = max(mx, A[i]);
		mi = min(mi, A[i]);
	}
	ll ans = init;
	cur = 1;
	ll S = 0;
	for(int i = 1; i <= n; ++i) {
		add({-i, S, cur}, mi, mx + 1, 1);
		ll w = get(A[i], mi, mx + 1, 1) + (ll)i * A[i] - S;
		S += A[i];
		sum[i] = S;
		ans = max(ans, init-w);
	}
	cur = 2;
	sum[n + 1] = sum[n];
	for(int i = n; i >= 1; --i) {
		add({-i, sum[i], cur}, mi, mx + 1, 1);
		ll w = get(A[i], mi, mx + 1, 1) - sum[i] + (ll)i * A[i];
		//~ cout << -w << "\n";
		ans = max(ans, init-w);
	}
	cout << ans;	
		
	
	
	
	
}