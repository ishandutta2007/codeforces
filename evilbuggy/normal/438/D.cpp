#include <bits/stdc++.h>
using namespace std;

struct Data{
	int max;
	long long sum;
	Data(){
		sum = max = 0;
	}
};

const int maxn = 100005;

int a[maxn];
Data tree[maxn << 2];

void build(int v, int l, int r){
	if(l == r){
		tree[v].sum = tree[v].max = a[l];
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	tree[v].sum = tree[v1].sum + tree[v2].sum;
	tree[v].max = max(tree[v1].max, tree[v2].max);
}

void updatePoint(int v, int s, int e, int ind){
	if(s == e){
		tree[v].sum = tree[v].max = a[ind];
		return;
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(ind <= m)updatePoint(v1, s, m, ind);
	else updatePoint(v2, m + 1, e, ind);
	tree[v].sum = tree[v1].sum + tree[v2].sum;
	tree[v].max = max(tree[v1].max, tree[v2].max);
}

void updateMod(int v, int s, int e, int l, int r, int mod){
	if(tree[v].max < mod)return;
	if(s == e){
		a[s] %= mod;
		tree[v].sum = a[s];
		tree[v].max = a[s];
		return;
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m){
		updateMod(v1, s, m, l, r, mod);
	}else if(m + 1 <= l){
		updateMod(v2, m + 1, e, l, r, mod);
	}else{
		updateMod(v1, s, m, l, r, mod);
		updateMod(v2, m + 1, e, l, r, mod);
	}
	tree[v].sum = tree[v1].sum + tree[v2].sum;
	tree[v].max = max(tree[v1].max, tree[v2].max);
}

long long query(int v, int s, int e, int l, int r){
	if(l <= s && e <= r)return tree[v].sum;
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query(v1, s, m, l, r);
	if(m + 1 <= l)return query(v2, m + 1, e, l, r);
	return query(v1, s, m, l, r) + query(v2, m + 1, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	while(m--){
		int t; cin >> t;
		if(t == 1){
			int l; cin >> l;
			int r; cin >> r;
			cout << query(1, 1, n, l, r) << '\n';
		}else if(t == 2){
			int l; cin >> l;
			int r; cin >> r;
			int x; cin >> x;
			updateMod(1, 1, n, l, r, x);
		}else{
			int k; cin >> k;
			int x; cin >> x;
			a[k] = x;
			updatePoint(1, 1, n, k);
		}
	}

	return 0;
}