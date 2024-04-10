#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;


int n, a[200005], ans[200005], nn, m, b[200005];
vector <int> tree;
pii f[200005];

void add(int v, int l, int r, int x){
	if (l == r && r == x){
		tree[v] = 1;
		return;
	}
	if (r < x || l > x) return;
	add(2 * v, l , (l + r) / 2, x);
	add(2 * v + 1, (l + r) / 2 + 1, r, x);
	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

ll sum(int v, int l, int r, int x){
	if (l > x) return 0;
	if (r <= x) return tree[v];
	return sum(2 * v, l, (l + r) / 2, x) + sum(2 * v + 1, (l + r) / 2 + 1, r, x);
}


ll sum2(int v, int l, int r, int x){
	if (r < x) return 0;
	if (l >= x) return tree[v];
	return sum2(2 * v, l, (l + r) / 2, x) + sum2(2 * v + 1, (l + r) / 2 + 1, r, x);
}


int main(){
// ifstream cin (problem".in");
// ofstream cout(problem".in");
	scanf("%d", &n);
	for (int i = 0;i < n; i++){
		scanf("%d", &a[i]);
		a[i] += i;
		f[i] = mp(a[i], i);
	}
	set <int> num;
	for (int i = 0; i < n; i++){
		if (num.find(a[i]) != num.end()){
			printf(":(\n");
			return 0;
		}
		num.insert(a[i]);
	}
	nn = n;
	m = 1;
	while (nn){
		 nn >>= 1;
		 m <<= 1;
	}
	tree.resize(2 *m, 0);
	sort(f, f + n);
	for (int i = n - 1; i >= 0; i--){
		b[f[i].second] = sum(1, 0, m - 1, f[i].second);
		add(1, 0, m - 1, f[i].second);
	}
	tree.assign(2 * m, 0);
	for (int i = 0; i < n; i++){
		b[f[i].second] -= sum2(1, 0, m - 1, f[i].second);
		add(1, 0, m - 1, f[i].second);
	}
	for (int i = 0; i < n; i++){
		ans[i - b[i]] = a[i] - i + b[i];
	}
	for (int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	return 0;
}