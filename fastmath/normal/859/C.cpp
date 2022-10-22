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
const int MAXN = 107;

int a[MAXN], dp[MAXN], post[MAXN];

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

	post[n] = 0;
	for (int i = n - 1; i >= 0; --i){
		post[i] = post[i + 1] + a[i];
	}

	dp[n] = 0;
	for (int i = n - 1; i >= 0; --i){

		dp[i] = -MOD;
		for (int get = i; get < n; ++get){
			dp[i] = max(dp[i], a[get] + post[get + 1] - dp[get + 1]);
		}
	}

	cout << post[0] - dp[0] << ' ' << dp[0] << '\n';
	return 0;
}