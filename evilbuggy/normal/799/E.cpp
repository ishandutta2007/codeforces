#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

pair<long long, int> tree[N << 2];
vector<int> arr[4];
int c[N], type[N];

void update(int v, int l, int r, int i, long long x, int c){
	if(l == r){
		tree[v] = {x, c};
		return;
	}
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(i <= m)update(v1, l, m, i, x, c);
	else update(v2, m + 1, r, i, x, c);
	tree[v].first = tree[v1].first + tree[v2].first;
	tree[v].second = tree[v1].second + tree[v2].second;
}

long long query(int v, int l, int r, int cnt){
	if(cnt == 0)return 0;
	if(tree[v].second == cnt)return tree[v].first;
	int m = (l + r)/2;
	int v1 = v << 1;
	int v2 = v1 | 1;
	if(tree[v1].second > cnt){
		return query(v1, l, m, cnt);
	}else{
		return tree[v1].first + query(v2, m + 1, r, cnt - tree[v1].second);
	}
}

void reorder(int n){
	vector<pair<int, int> > vec;
	for(int i = 1; i <= n; i++){
		vec.emplace_back(c[i], type[i]);
	}
	sort(vec.begin(), vec.end());
	for(int i = 1; i <= n; i++){
		c[i] = vec[i - 1].first;
		type[i] = vec[i - 1].second;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		type[i] = 0;
	}
	int a;
	cin >> a;
	for(int i = 1; i <= a; i++){
		int x;
		cin >> x;
		type[x] ^= 1;
	}
	cin >> a;
	for(int i = 1; i <= a; i++){
		int x;
		cin >> x;
		type[x] ^= 2;
	}
	reorder(n);
	for(int i = 1; i <= n; i++){
		arr[type[i]].emplace_back(i);
	}
	int sz1 = (int)arr[1].size();
	int sz2 = (int)arr[2].size();
	int sz3 = (int)arr[3].size();
	memset(tree, 0, sizeof(tree));
	for(int p : arr[0]){
		update(1, 1, n, p, c[p], 1);
	}
	int lo = max(0, k - min(sz1, sz2));
	int hi = min(k, sz3);
	if(lo > hi){
		cout << -1 << '\n';
		exit(0);
	}
	for(int i = lo; i < sz3; i++){
		int p = arr[3][i];
		update(1, 1, n, p, c[p], 1);
	}
	for(int i = k - lo; i < sz1; i++){
		int p = arr[1][i];
		update(1, 1, n, p, c[p], 1);
	}
	for(int i = k - lo; i < sz2; i++){
		int p = arr[2][i];
		update(1, 1, n, p, c[p], 1);
	}
	long long sum = 0;
	for(int i = 0; i < lo; i++){
		sum += c[arr[3][i]];
	}
	for(int i = 0; i < k - lo; i++){
		sum += c[arr[1][i]];
		sum += c[arr[2][i]];
	}
	long long answer = 2e18;
	for(int r = lo; r <= hi; r++){
		if(2*k - r <= m){
			answer = min(answer, sum + query(1, 1, n, m - 2*k + r));
		}
		if(r < sz3){
			sum += c[arr[3][r]];
			update(1, 1, n, arr[3][r], 0, 0);
		}
		if(k - r > 0){
			int p = arr[1][k - r - 1];
			update(1, 1, n, p, c[p], 1);
			sum -= c[p];
		}
		if(k - r > 0){
			int p = arr[2][k - r - 1];
			update(1, 1, n, p, c[p], 1);
			sum -= c[p];
		}
	}
	if(answer > 1e18){
		cout << -1 << '\n';
	}else{
		cout << answer << '\n';
	}

	return 0;
}