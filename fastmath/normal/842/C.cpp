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

#define x first
#define y second
#define prev _prev
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 3e5 + 7;

vector <int> g[MAXN];
int ans[MAXN], a[MAXN];
bool used[MAXN];
vector <int> div1;

vector <int> get_div(int n){
	vector <int> res;
	for (int div = 1; div * div <= n; ++div){
		if (!(n % div)){
			res.push_back(div);
			if (div * div != n){
				res.push_back(n / div);
			}
		}
	}

	return res;
}

int gcd(int a, int b){
	while (b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

void dfs(int u, vector <int> sum, int h, int pref_nod){
	used[u] = true;

	for (int i = 0; i < div1.size(); ++i){
		int d = div1[i];
		if (!(a[u] % d)){
			++sum[i];
		}
	}

	if (h) {
		pref_nod = gcd(pref_nod, a[u]);
	}

	for (int v : g[u]){
		if (!used[v]){
			dfs(v, sum, h + 1, pref_nod);
		}
	}

	ans[u] = pref_nod;
	for (int i = 0; i < div1.size(); ++i){
		if (sum[i] >= h){
			ans[u] = max(ans[u], div1[i]);
		}
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int u, v;
	for (int i = 0; i < n - 1; ++i){
		cin >> u >> v;
		g[u - 1].push_back(v - 1);
		g[v - 1].push_back(u - 1);
	}

	div1 = get_div(a[0]);
	vector <int> sum(div1.size(), 0);
	dfs(0, sum, 0, 0);

	for (int i = 0; i < n; ++i){
		cout << ans[i] << ' ';
	}

	return 0;
}