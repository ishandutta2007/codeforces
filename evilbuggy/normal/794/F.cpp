#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
long long nsum[10], sum[N << 2][10];
int a[N], ngo[10], lazy[N << 2], go[N << 2][10];

void build(int v, int l, int r){
	iota(go[v] + 1, go[v] + 10, 1);
	if(l == r){
		int x = a[l], prod = 1;
		while(x){
			sum[v][x%10] += prod;
			prod *= 10;
			x /= 10;
		}
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	for(int i = 0; i < 10; i++){
		sum[v][i] = sum[v1][i] + sum[v2][i];
	}
}

inline void push(int v, int s, int e){
	if(lazy[v]){
		memset(nsum, 0, sizeof(nsum));
		for(int i = 0; i < 10; i++){
			nsum[go[v][i]] += sum[v][i];
		}
		if(s != e){
			int v1 = v << 1;
			int v2 = v1 | 1;
			lazy[v1] = 1;
			lazy[v2] = 1;
			for(int i = 0; i < 10; i++){
				ngo[i] = go[v][go[v1][i]];
			}
			for(int i = 0; i < 10; i++){
				go[v1][i] = ngo[i];
			}
			for(int i = 0; i < 10; i++){
				ngo[i] = go[v][go[v2][i]];
			}
			for(int i = 0; i < 10; i++){
				go[v2][i] = ngo[i];
			}
		}
		for(int i = 0; i < 10; i++){
			sum[v][i] = nsum[i];
			go[v][i] = i;
		}
		lazy[v] = 0;
	}
}

void update(int v, int s, int e, int l, int r, int x, int y){
	if(l <= s && e <= r){
		lazy[v] = 1;
		for(int i = 0; i < 10; i++){
			if(go[v][i] == x){
				go[v][i] = y;
			}
		}
		push(v, s, e);
		return;
	}
	push(v, s, e);
	if(r < s || e < l)return;
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	update(v1, s, m, l, r, x, y);
	update(v2, m + 1, e, l, r, x, y);
	for(int i = 0; i < 10; i++){
		sum[v][i] = sum[v1][i] + sum[v2][i];
	}
}

long long query(int v, int s, int e, int l, int r){
	push(v, s, e);
	if(l <= s && e <= r){
		long long ret = 0;
		for(int i = 1; i < 10; i++){
			ret += i*sum[v][i];
		}
		return ret;
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query(v1, s, m, l, r);
	if(m < l)return query(v2, m + 1, e, l, r);
	return query(v1, s, m, l, r) + query(v2, m + 1, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	memset(sum, 0, sizeof(sum));
	memset(lazy, 0, sizeof(lazy));
	build(1, 1, n);
	int type, l, r, x, y;
	for(int it = 0; it < q; it++){
		cin >> type >> l >> r;
		if(type == 1){
			cin >> x >> y;
			update(1, 1, n, l, r, x, y);
		}else{
			cout << query(1, 1, n, l, r) << '\n';
		}
	}

	return 0;
}