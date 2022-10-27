#include <bits/stdc++.h>
using namespace std;

struct Data{
	vector<pair<int, int> > pref;
	vector<pair<int, int> > suff;
	long long cnt;
	int total;
};

const int N = 100005;
const int M = 1 << 20;

int n, m, X, a[N];
Data tree[N << 2];

inline long long crossCount(vector<pair<int, int> > &le, vector<pair<int, int> > &ri){
	long long ret = 0, cnt = 0;
	int szl = (int)le.size();
	int szr = (int)ri.size();
	for(int i = 0, j = szr; i < szl; i++){
		while(j > 0 && (le[i].first|ri[j - 1].first) >= X){
			j--; cnt += ri[j].second;
		}
		ret += cnt*le[i].second;
	}
	return ret;
}

inline Data combine(Data a, Data b){
	Data ret;
	ret.pref = a.pref;
	for(auto x : b.pref){
		if(ret.pref.back().first == (x.first | a.total)){
			ret.pref.back().second += x.second;
		}else{
			ret.pref.emplace_back(x.first | a.total, x.second);
		}
	}
	ret.suff = b.suff;
	for(auto x : a.suff){
		if(ret.suff.back().first == (x.first | b.total)){
			ret.suff.back().second += x.second;
		}else{
			ret.suff.emplace_back(x.first | b.total, x.second);
		}
	}
	ret.total = a.total | b.total;
	ret.cnt = a.cnt + b.cnt + crossCount(a.suff, b.pref);
	return ret;
}

void build(int v, int l, int r){
	if(l == r){
		tree[v].pref.emplace_back(a[l], 1);
		tree[v].suff.emplace_back(a[l], 1);
		tree[v].total = a[l];
		if(a[l] >= X){
			tree[v].cnt = 1;
		}else{
			tree[v].cnt = 0;
		}
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
	tree[v] = combine(tree[v1], tree[v2]);
}

void update(int v, int l, int r, int i){
	if(l == r){
		tree[v].pref[0].first = a[l];
		tree[v].suff[0].first = a[l];
		tree[v].total = a[l];
		if(a[l] >= X){
			tree[v].cnt = 1;
		}else{
			tree[v].cnt = 0;
		}
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update(v1, l, m, i);
	else update(v2, m + 1, r, i);
	tree[v] = combine(tree[v1], tree[v2]);
}

Data query(int v, int s, int e, int l, int r){
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
	
	cin >> n >> m >> X;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	build(1, 1, n);
	int type, u, v;
	while(m--){
		cin >> type >> u >> v;
		if(type == 1){
			a[u] = v;
			update(1, 1, n, u);
		}else{
			cout << query(1, 1, n, u, v).cnt << '\n';
		}
	}

	return 0;
}