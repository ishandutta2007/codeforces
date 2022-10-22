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
#define prev _prev
#define hash _hash;
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e10 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 50;

int dp[MAXN][MAXN * MAXN];
int pref[MAXN];

int get(int i, int j){
	if (j < 0){
		return dp[i][0];
	}

	return dp[i][j];
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < MAXN; ++i){
		for (int j = 0; j < MAXN * MAXN; ++j){
			dp[i][j] = MOD;
		}
	}
	dp[0][0] = 0;

	int n, k, t;
	cin >> n >> k >> t;
	vector <int> cost(k);
	for (int i = 0; i < k; ++i){
		cin >> cost[i];
	}
	sort(cost.begin(), cost.end());
	pref[0] = 0;
	for (int i = 1; i <= k; ++i){
		pref[i] = pref[i - 1] + cost[i - 1];
	}

	for (int i = 1; i <= n; ++i){
		for (int ball = 0; ball < MAXN * MAXN; ++ball){
			
			dp[i][ball] = MOD;
			for (int last = 0; last < k; ++last){
				dp[i][ball] = min(dp[i][ball], pref[last] + get(i - 1, ball - last));
			}
			dp[i][ball] = min(dp[i][ball], pref[k] + get(i - 1, ball - k - 1));
		}
	}

	int ans = 0;
	for (int i = 0; i < MAXN * MAXN; ++i){
		if (dp[n][i] <= t){
			ans = i;
		}
	}

	cout << ans << '\n';
	return 0;
}