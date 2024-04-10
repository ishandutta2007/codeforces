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

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const int MAXN = 207;
const int MAXFIVE = 6e3;
typedef long long ll;

int dp[MAXN][MAXFIVE];
ll a[MAXN];

int f5(ll n){
	int res = 0;
	while (!(n % 5)){
		n /= 5;
		++res;
	}

	return res;
}

int f2(ll n){
	int res = 0;
	while (!(n % 2)){
		n /= 2;
		++res;
	}

	return res;
}

signed main(){
	for (int i = 0; i < MAXN; ++i){
		for (int j = 0; j < MAXFIVE; ++j){
			dp[i][j] = -MOD;
		}
	}

	dp[0][0] = 0;

	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i){
		int new5 = f5(a[i - 1]);
		int new2 = f2(a[i - 1]);

		for (int j = k; j; --j){
			for (int fives = MAXFIVE; fives >= 0; --fives){
				dp[j][fives] = max(dp[j][fives], dp[j - 1][max(0, fives - new5)] + new2);
			}
		}
	}

	int ans = 0;
	for (int j = 0; j < MAXFIVE; ++j){
		ans = max(ans, min(j, dp[k][j]));
	}

	cout << ans << '\n';
	return 0;
}