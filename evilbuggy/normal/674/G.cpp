#include <bits/stdc++.h>
using namespace std;

struct Node{
	pair<int, int> arr[5];
};

const int N = 150005;

Node tree[N << 2];
int n, m, p, vec[55],a[N], iter, freq[N], when[N], lazy[N << 2];

inline Node combine(Node a, Node b){
	++iter;
	int sz = 0;
	for(int i = 0; i < 5; i++){
		if(!a.arr[i].first)break;
		freq[a.arr[i].second] = a.arr[i].first;
		vec[sz] = a.arr[i].second; ++sz;
		when[a.arr[i].second] = iter;
	}
	for(int i = 0; i < 5; i++){
		if(!b.arr[i].first)break;
		if(when[b.arr[i].second] == iter){
			freq[b.arr[i].second] += b.arr[i].first;
		}else{
			freq[b.arr[i].second] = b.arr[i].first;
			vec[sz] = b.arr[i].second; ++sz;
			when[b.arr[i].second] = iter;
		}
	}
	Node ret;
	for(int i = 0; i < 5; i++){
		ret.arr[i].first = ret.arr[i].second = 0;
	}
	if(sz == 0)return ret;
	sort(vec, vec + sz, [&](int i, int j){
		return freq[i] > freq[j];
	});
	while(sz > 5){
		for(int i = 1; i <= 5; i++){
			freq[vec[sz - 1 - i]] -= freq[vec[sz - 1]];
		}
		sz--;
	}
	for(int i = 0; i < sz; i++){
		ret.arr[i] = {freq[vec[i]], vec[i]};
	}
	return ret;
}

void build(int v, int l, int r){
	if(l == r){
		for(int i = 0; i < 5; i++){
			tree[v].arr[i].first = tree[v].arr[i].second = 0;
		}
		tree[v].arr[0] = {1, a[l]};
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	tree[v] = combine(tree[v1], tree[v2]);
}

inline void push(int v, int s, int e){
	if(lazy[v] != 0){
		for(int i = 0; i < 5; i++){
			tree[v].arr[i].first = tree[v].arr[i].second = 0;
		}
		tree[v].arr[0] = {e - s + 1, lazy[v]};
		if(s != e){
			lazy[2*v] = lazy[2*v + 1] = lazy[v];
		}
		lazy[v] = 0;
	}
}

void update(int v, int s, int e, int l, int r, int x){
	if(l <= s && e <= r){
		lazy[v] = x;
		push(v, s, e);
		return;
	}
	push(v, s, e);
	if(r < s || e < l)return;
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	update(v1, s, m, l, r, x);
	update(v2, m + 1, e, l, r, x);
	tree[v] = combine(tree[v1], tree[v2]);
}

Node query(int v, int s, int e, int l, int r){
	push(v, s, e);
	if(l <= s && e <= r)return tree[v];
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query(v1, s, m, l, r);
	if(m < l)return query(v2, m + 1, e, l, r);
	return combine(query(v1, s, m, l, r), query(v2, m + 1, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int lim = 100/p;
	build(1, 1, n);
	int type, l, r, x;
	while(m--){
		cin >> type >> l >> r;
		if(type == 1){
			cin >> x;
			update(1, 1, n, l, r, x);
		}else{
			Node qr = query(1, 1, n, l, r);
			vector<int> ans;
			for(int i = 0; i < lim; i++){
				if(!qr.arr[i].first)break;
				ans.emplace_back(qr.arr[i].second);
			}
			cout << ans.size() << ' ';
			for(auto x : ans){
				cout << x << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}