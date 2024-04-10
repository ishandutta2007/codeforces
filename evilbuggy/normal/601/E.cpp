#include <bits/stdc++.h>
using namespace std;

const int N = 30005;
const int P = 10000019;
const int Q = 1000000007;
const long long Q2 = Q*1LL*Q;

vector<pair<int, int> > tree[N << 2];
int iter, st[N], en[N], val[N], wei[N], type[N], ind[N], ans[N], pw[N];

void update(int v, int s, int e, int l, int r, int va, int we){
	if(l <= s && e <= r){
		tree[v].emplace_back(we, va);
		return;
	}
	int m = (s + e)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(l <= m)update(v1, s, m, l, r, va, we);
	if(m < r)update(v2, m + 1, e, l, r, va, we);
}

void dfs(int v, int l, int r, int k, vector<int> &mx){
	vector<int> nmx = mx;
	for(auto x : tree[v]){
		for(int i = k - x.first; i >= 0; i--){
			nmx[i + x.first] = max(nmx[i + x.first], nmx[i] + x.second);
		}
	}
	if(l == r){
		long long sum = 0;
		for(int m = 1; m <= k; m++){
			sum += nmx[m]*1LL*pw[m - 1];
			if(sum >= Q2)sum -= Q2;
		}
		ans[l] = sum%Q;
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	dfs(v1, l, m, k, nmx);
	dfs(v2, m + 1, r, k, nmx);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> val[i] >> wei[i];
		st[i] = 1; en[i] = -1;
	}
	pw[0] = 1;
	for(int i = 1; i <= k; i++){
		pw[i] = pw[i - 1]*1LL*P%Q;
	}
	int q;
	cin >> q;
	iter = n;
	for(int i = 1; i <= q; i++){
		cin >> type[i];
		if(type[i] == 1){
			++iter;
			cin >> val[iter] >> wei[iter];
			st[iter] = i; en[iter] = -1;
		}else if(type[i] == 2){
			int x;
			cin >> x;
			en[x] = i;
		}
	}
	for(int i = 1; i <= iter; i++){
		if(en[i] == -1){
			en[i] = q;
		}
		update(1, 1, q, st[i], en[i], val[i], wei[i]);
	}
	vector<int> mx(k + 1);
	dfs(1, 1, q, k, mx);
	for(int i = 1; i <= q; i++){
		if(type[i] == 3){
			cout << ans[i] << '\n';
		}
	}


	return 0;
}