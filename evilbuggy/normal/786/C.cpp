#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int K = 18;
const int M = N*K*4;

int iter, a[N], tree[M][2], val[M], root[N], last[N];

int update(int v, int l, int r, int i, int x){
	int u = iter++;
	if(l == r){
		val[u] = val[v] + x;
		return u;
	}
	int m = (l + r)/2;
	if(i <= m){
		tree[u][0] = update(tree[v][0], l, m, i, x);
		tree[u][1] = tree[v][1];
		val[u] = val[tree[u][0]] + val[tree[u][1]];
	}else{
		tree[u][1] = update(tree[v][1], m + 1, r, i, x);
		tree[u][0] = tree[v][0];
		val[u] = val[tree[u][0]] + val[tree[u][1]];
	}
	return u;
}

int query(int v, int l, int r, int k){
	if(val[v] < k)return 1e9;
	if(l == r){
		return l;
	}
	int m = (l + r)/2;
	if(k <= val[tree[v][0]]){
		return query(tree[v][0], l, m, k);
	}
	return query(tree[v][1], m + 1, r, k - val[tree[v][0]]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	iter = 1;
	memset(val, 0, sizeof(val));
	memset(tree, 0, sizeof(tree));
	memset(last, 0, sizeof(last));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	root[n + 1] = 0;
	for(int i = n; i >= 1; i--){
		root[i] = root[i + 1];
		if(last[a[i]]){
			root[i] = update(root[i], 1, n, last[a[i]], -1);
		}
		last[a[i]] = i;
		root[i] = update(root[i], 1, n, last[a[i]], 1);
	}
	for(int k = 1; k <= n; k++){
		int ans = 0;
		for(int en, st = 1; st <= n; st = en + 1){
			// cout << st << " ";
			en = query(root[st], 1, n, k + 1) - 1;
			// cout << en << " " << k << endl;
			ans++;
		}
		cout << ans << " ";
	}
	cout << '\n';

	return 0;
}