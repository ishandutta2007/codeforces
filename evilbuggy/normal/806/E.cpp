#include <bits/stdc++.h>
using namespace std;

struct Data{
	int val, cnt;
};

const int N = 500005;
const int inf = 1e9;

int a[N], ord[N], pos[N];
Data tree1[N << 2];
Data tree2[N << 2];

void build(int v, int l, int r){
	tree1[v].val = -inf;
	tree2[v].val = +inf;
	tree1[v].cnt = 0;
	tree2[v].cnt = 0;
	if(l == r)return;
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	build(v1, l, m);
	build(v2, m + 1, r);
}

void update1(int v, int l, int r, int i, int x){
	if(l == r){
		tree1[v] = {x, 1};
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update1(v1, l, m, i, x);
	else update1(v2, m + 1, r, i, x);

	tree1[v].cnt = tree1[v1].cnt + tree1[v2].cnt;
	tree1[v].val = max(tree1[v1].val, tree1[v2].val + tree1[v1].cnt);
}

pair<int, int> query1(int v, int l, int r, int cnt){
	if(l == r)return {l, cnt};
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(cnt + tree1[v1].val < 0){
		return query1(v2, m + 1, r, cnt + tree1[v1].cnt);
	}
	return query1(v1, l, m, cnt);
}

void update2(int v, int l, int r, int i, int x){
	if(l == r){
		tree2[v] = {x, 1};
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update2(v1, l, m, i, x);
	else update2(v2, m + 1, r, i, x);

	tree2[v].cnt = tree2[v1].cnt + tree2[v2].cnt;
	tree2[v].val = min(tree2[v2].val, tree2[v1].val + tree2[v2].cnt);
}

pair<int, int> query2(int v, int s, int e, int l, int r, int cnt){
	if(l <= s && e <= r){
		return {tree2[v].val + cnt, cnt + tree2[v].cnt};
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(r <= m)return query2(v1, s, m, l, r, cnt);
	if(m < l)return query2(v2, m + 1, e, l, r, cnt);
	pair<int, int> tmp1 = query2(v2, m + 1, e, l, r, cnt);
	pair<int, int> tmp2 = query2(v1, s, m, l, r, tmp1.second);
	return {min(tmp1.first, tmp2.first), tmp2.second};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&](int i, int j){
		return a[i] < a[j];
	});
	for(int i = 1; i <= n; i++){
		pos[ord[i]] = i;
	}
	build(1, 1, n);
	for(int i = 1; i <= n; i++){
		update1(1, 1, n, pos[i], a[i]);
		update2(1, 1, n, pos[i], a[i]);
		if(tree1[1].val < 0){
			cout << -i << '\n';
			continue;
		}
		pair<int, int> pp = query1(1, 1, n, 0);
		int rem = i - pp.second;
		int ans = rem - pp.second;
		ans = min(ans, query2(1, 1, n, pp.first, n, 0).first);
		cout << ans << '\n';
	}

	return 0;
}