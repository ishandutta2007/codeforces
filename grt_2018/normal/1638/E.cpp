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

const int nax = 1e6 + 10;
int n, q;
ll sum[nax];
ll val[nax];

struct Node {
	int x;
	ll dx;
	bool flag;
	int mi, mx;
};

Node T[(1<<21)];

void putflag(int v, int x) {
	T[v].x = x;
	T[v].flag = 1;
	T[v].mi = T[v].mx = x;
}

void push(int v) {
	T[v << 1].dx += T[v].dx;
	T[v << 1 | 1].dx += T[v].dx;
	T[v].dx = 0;
	if(!T[v].flag) return;
	putflag(v << 1, T[v].x);
	putflag(v << 1 | 1, T[v].x);
	T[v].flag = 0;
}

void merge(int v) {
	if(T[v].flag) {
		return;
	}
	T[v].mi = min(T[v << 1].mi, T[v << 1 | 1].mi);
	T[v].mx = max(T[v << 1].mx, T[v << 1 | 1].mx);
}
	

void upd(int a, int b, int x, int l = 1, int r = n, int v = 1) {
	if(a <= l && r <= b && (l == r || T[v].mx == T[v].mi)) {
		T[v].dx += sum[T[v].mx] - sum[x];
		putflag(v, x);
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if(a <= mid) upd(a, b, x, l, mid, v << 1);
	if(mid < b) upd(a, b, x, mid + 1, r, v << 1 | 1);
	merge(v);
}

pair<ll,int> qr(int a, int l = 1, int r = n, int v = 1) {
	if(l == r) {
		return {T[v].dx, T[v].x};
	}
	push(v);
	int mid = (l + r) >> 1;
	pair<ll,int>w;
	if(a <= mid) w = qr(a, l, mid, v << 1);
	else w = qr(a, mid + 1, r, v << 1 | 1);
	merge(v);
	return w;
}

int main() {_
	cin >> n >> q;
	upd(1, n, 1);
	while(q--) {
		string s;
		cin >> s;
		if(s[0] == 'C') {
			int l, r, c;
			cin >> l >> r >> c;
			upd(l, r, c);
		} else if(s[0] == 'A') {
			int c, x;
			cin >> c >> x;
			sum[c] += x;
		} else {
			int x;
			cin >> x;
			auto [v, c] = qr(x);
			cout << v + sum[c] << "\n";
		}
	}
	
}