#include <bits/stdc++.h>
using namespace std;

// [x, x + n - 1]
// w_1|a_1 - x| + w_2|a_2 - x| + ...
// optimal value when x = median of multiset {(a1, w1), (a2, w2), (a3, w3) ... }
// Let s = w_1 + w_2 + ... w_n;
// if s is odd
//     find smallest i such that w_1 + w_2 + ... + w_i >= (s + 1)/2
// else
//     find smallest i such that w_1 + w_2 + ... + w_i >= s/2

struct Data{
	long long wsum, tsum;
	Data(long long iw = 0, long long it = 0){
		wsum = iw; tsum = it;
	}
};

const int maxN = 200005;
const int mod = 1000000007;

Data tree[maxN << 2];
long long a[maxN], w[maxN];

inline int add(int x, int y){
	if(x + y < mod)return x + y;
	return x + y - mod;
}

void build(int v, int l, int r){
	if(l == r){
		tree[v].wsum = w[l];
		tree[v].tsum = a[l]*w[l]%mod;
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	tree[v].wsum = tree[v1].wsum + tree[v2].wsum;
	tree[v].tsum = add(tree[v1].tsum, tree[v2].tsum);
}

void update(int v, int l, int r, int i){
	if(l == r){
		tree[v].wsum = w[l];
		tree[v].tsum = a[l]*w[l]%mod;
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update(v1, l, m, i);
	else update(v2, m + 1, r, i);
	tree[v].wsum = tree[v1].wsum + tree[v2].wsum;
	tree[v].tsum = add(tree[v1].tsum, tree[v2].tsum);
}

Data query(int v, int s, int e, int l, int r){
	if(r < s || e < l || r < l)return Data();
	if(l <= s && e <= r)return tree[v];
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	Data dl = query(v1, s, m, l, r);
	Data dr = query(v2, m + 1, e, l, r);
	return Data(dl.wsum + dr.wsum, add(dl.tsum, dr.tsum));
}

int findpos(int v, int s, int e, int l, int r, long long &pos){
	if(r < s || e < l || r < l)return -1;
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(l <= s && e <= r){
		if(tree[v].wsum < pos){
			pos -= tree[v].wsum;
			return -1;
		}
		if(s == e)return s;
	}
	int tmp = findpos(v1, s, m, l, r, pos);
	if(tmp == -1)tmp = findpos(v2, m + 1, e, l, r, pos);
	return tmp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; a[i] -= i - 1;
	}
	for(int i = 1; i <= n; i++){
		cin >> w[i];
	}
	build(1, 1, n);
	while(q--){
		int x, y;
		cin >> x >> y;
		if(x < 0){
			w[-x] = y;
			update(1, 1, n, -x);
		}else{
			Data d = query(1, 1, n, x, y);
			long long pos = (d.wsum + 1)/2;
			int ind = findpos(1, 1, n, x, y, pos);
			Data dl = query(1, 1, n, x, ind - 1);
			Data dr = query(1, 1, n, ind + 1, y);
			int ans = add(dr.tsum, mod - dl.tsum);
			ans = add(ans, (mod + (dl.wsum - dr.wsum)%mod)*a[ind]%mod);
			cout << ans << '\n';
		}
	}

	return 0;
}