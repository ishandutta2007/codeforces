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

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 3e5 + 7;

int tree[4 * MAXN];

void build(int v, int tl, int tr){
	tree[v] = tl;
	if (tl == tr) return;
	int m = (tl + tr) / 2;
	build(v * 2 + 1, tl, m); build(v * 2 + 2, m + 1, tr);
}

int get(int v, int tl, int tr, int l, int r){
	if (tl > r || l > tr) return MOD;
	if (tl >= l && tr <= r) return tree[v];
	int m = (tl + tr) / 2;
	return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m + 1, tr, l, r));
}

void upd(int v, int tl, int tr, int i){
	if (tl == tr) {
		tree[v] = MOD;
		return;
	}

	int m = (tl + tr) / 2;
	if (i <= m){
		upd(v * 2 + 1, tl, m, i);
	}
	else{
		upd(v * 2 + 2, m + 1, tr, i);
	}

	tree[v] = min(tree[v * 2 + 1], tree[v * 2 + 2]);
}

bool comp(pair <int, int> a, pair <int, int> b){
	return a.first > b.first;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	build(0, k, n + k - 1);
	vector <pair <int, int> > a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), comp);

	int ans = 0;
	vector <int> v(n);
	for (int i = 0; i < n; ++i){
		int p = get(0, k, n + k - 1, a[i].second, n + k - 1);
		ans += (p - a[i].second) * a[i].first;
		upd(0, k, n + k - 1, p);
		v[a[i].second] = p + 1;
	}

	cout << ans << '\n';
	for (int i = 0; i < n; ++i) cout << v[i] << ' ';
	return 0;
}