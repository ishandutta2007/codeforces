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
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int dp1[MAXN], dp2[MAXN];
int a[MAXN];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int n, p, q, r;
	cin >> n >> p >> q >> r;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	dp1[0] = p * a[0];
	for (int i = 1; i < n; ++i){
		dp1[i] = max(dp1[i - 1], a[i] * p);
	}

	dp2[0] = p * a[0] + q * a[0];
	for (int i = 1; i < n; ++i){
		dp2[i] = max(dp2[i - 1], a[i] * q + dp1[i]);
	}

	int ans = -8e18;
	for (int i = 0; i < n; ++i){
		ans = max(ans, a[i] * r + dp2[i]);
	}

	cout << ans;
	return 0;
}