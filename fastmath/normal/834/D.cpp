#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

#define x first
#define y second
mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const int MAXN = 5e4;
const int MAXK = 57;
const int MAXSZ = 4e5;
typedef long long ll;

int a[MAXN];
map <int, int> last;
int _prev[MAXN];
int dp[MAXK][MAXN];
int tree[MAXSZ], add[MAXSZ];

void push(int v){
	add[v * 2 + 1] += add[v];
	add[v * 2 + 2] += add[v];
	tree[v * 2 + 1] += add[v];
	tree[v * 2 + 2] += add[v];
	add[v] = 0;
}

void build(int v, int tl, int tr, int i){
	add[v] = 0;

	if (tl == tr){
		tree[v] = dp[i][tl];
		return;
	}

	int m = (tl + tr) / 2;
	build(v * 2 + 1, tl, m, i);
	build(v * 2 + 2, m + 1, tr, i);
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

void update(int v, int tl, int tr, int l, int r){
	if (tl > r || l > tr){
		return;
	}

	if (tl >= l && tr <= r){
		add[v]++;
		tree[v]++;
		return;
	}

	push(v);
	int m = (tl + tr) / 2;
	update(v * 2 + 1, tl, m, l, r);
	update(v * 2 + 2, m + 1, tr, l, r);
	tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]) + add[v];
}

int get(int v, int tl, int tr, int l, int r){
	if (tl > r || l > tr){
		return -MOD;
	}

	if (tl >= l && tr <= r){
		return tree[v];
	}

	int m = (tl + tr) / 2;
	int res = max(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m + 1, tr, l, r)) + add[v];
	return res;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = n - 1; i >= 0; --i){
		if (last.find(a[i]) != last.end()){
			_prev[last[a[i]]] = i;
		}

		last[a[i]] = i;
	}

	set <int> s;
	dp[1][0] = -MOD;
	for (int i = 1; i <= n; ++i){
		s.insert(a[i - 1]);
		dp[1][i] = s.size();
	}

	for (int i = 2; i <= k; ++i){
		build(0, 0, n, i - 1);

		for (int j = 0; j < i; ++j){
			if (j) update(0, 0, n, _prev[j - 1] + 1, j - 1);
			dp[i][j] = -MOD;
		}

		update(0, 0, n, _prev[i - 1] + 1, i - 1);
		dp[i][i] = i;

		for (int j = i + 1; j <= n; ++j){
			update(0, 0, n, _prev[j - 1] + 1, j - 1);
			dp[i][j] = get(0, 0, n, 0, j - 1);
		}
	}

	cout << dp[k][n];
	return 0;
}