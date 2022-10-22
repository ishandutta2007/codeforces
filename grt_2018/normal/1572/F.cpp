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

const int nax = 200 * 1000 + 10, INF = 1e9;
int n, q;

struct Node2 {
	ll sum, lazy;
};

Node2 T2[(1 << 19)];

void push_lazy(int v, int x, int l, int r) {
	T2[v].sum += (ll)(r - l + 1) * x;
	T2[v].lazy += x;
}

void push2(int v, int l, int r) {
	int mid = (l + r) >> 1;
	if(T2[v].lazy != 0) {
		push_lazy(v << 1, T2[v].lazy, l, mid);
		push_lazy(v << 1 | 1, T2[v].lazy, mid + 1, r);
		T2[v].lazy = 0;
	}
}

void add(int a, int b, int x, int l = 1, int r = n, int v = 1) {
	if(a <= l && r <= b) {
		push_lazy(v,x,l,r);
		return;
	}
	push2(v,l,r);
	int mid = (l + r) >> 1;
	if(a <= mid) add(a,b,x,l,mid,v<<1);
	if(mid < b) add(a,b,x,mid+1,r,v<<1|1);
	T2[v].sum = T2[v<<1].sum + T2[v<<1|1].sum;
}

ll qr(int a, int b, int l = 1, int r = n, int v = 1) {
	if(r < a || l > b) return 0LL;
	if(a <= l && r <= b) {
		return T2[v].sum;
	}
	push2(v,l,r);
	int mid = (l + r) >> 1;
	return qr(a,b,l,mid,v<<1) + qr(a,b,mid+1,r,v<<1|1);
}

struct Node {
	int max1, max2, maxc;
};

Node T[(1 << 19)];

void push_max(int v, int x) {
	//assert(T[v].max1 >= x && x > T[v].max2);
	T[v].max1 = min(T[v].max1, x);
}

void push(int v) {
	push_max(v<<1, T[v].max1);
	push_max(v<<1|1,T[v].max1);
}

void merge(int v) {
	if(T[v<<1].max1 == T[v<<1|1].max1) {
		T[v].max1 = T[v<<1].max1;
		T[v].maxc = T[v<<1].maxc + T[v<<1|1].maxc;
		T[v].max2 = max(T[v<<1].max2, T[v<<1|1].max2);
	} else if(T[v << 1].max1 > T[v<<1|1].max1) {
		T[v].max1 = T[v << 1].max1;
		T[v].maxc = T[v<<1].maxc;
		T[v].max2 = max(T[v << 1].max2, T[v << 1 | 1].max1);
	} else {
		T[v].max1 = T[v << 1 | 1].max1;
		T[v].maxc = T[v<<1|1].maxc;
		T[v].max2 = max(T[v << 1].max1, T[v << 1 | 1].max2);
	}
}	

void chmin(int a, int b, int x, int l = 1, int r = n, int v = 1) {
	if(r < a || l > b || T[v].max1 <= x) return;
	if(a <= l && r <= b && T[v].max2 < x) {
		add(x + 1, T[v].max1, -T[v].maxc);
		push_max(v, x);
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	chmin(a,b,x,l,mid,v<<1);
	chmin(a,b,x,mid+1,r,v<<1|1);
	merge(v);
}

void chset(int a, int x, int l = 1, int r = n, int v = 1) {
	if(l == r) {
		T[v].max1 = x;
		return;
	}
	push(v);
	int mid = (l + r) >> 1;
	if(a <= mid) chset(a,x,l,mid,v<<1);
	else chset(a,x,mid+1,r,v<<1|1);
	merge(v);
}

void build(int l = 1, int r = n, int v = 1) {
	if(l == r) {
		T[v].max1 = l;
		T[v].max2 = -INF;
		T[v].maxc = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	merge(v);
}

int main() {_
	cin >> n >> q;
	build();
	add(1,n,1);
	while(q--) {
		int t, a, b;
		cin >> t >> a >> b;
		if(t == 1) {
			chmin(1,a,a-1);
			chset(a,b);
			add(a, b, 1);
		} else {
			cout << qr(a,b) << "\n";
		}
	}
	
	
}