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
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 998244353;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 5007;

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int sum(int a, int b){
	return form(a + b);
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

int dp1[MAXN], dp2[MAXN];

int get(int n, int k){
	for (int i = 0; i < MAXN; ++i){
		dp1[i] = 0;
		dp2[i] = 0;
	}

	dp1[k] = 1;
	for (int i = 1; i <= n; ++i){
		dp2[k] = 1;

		for (int j = 0; j < k; ++j){
			dp2[j] = sum(dp1[j], fact(j + 1, dp1[j + 1]));
		}

		for (int j = 0; j < MAXN; ++j){
			dp1[j] = dp2[j];
		}
	}

	int ans = 0;
	for (int i = 0; i <= k; ++i){
		ans = sum(ans, dp1[i]);
	}

	return ans;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	cout << fact(get(a, b), fact(get(b, c), get(c, a)));
	return 0;
}