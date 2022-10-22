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
const int MAXN = 2e5 + 7;
const int MAXVAL = 1e6 + 228;
typedef long long ll;

ll kratn[MAXVAL];
ll power[MAXVAL];
ll ans[MAXVAL];

void add(int x){
	int div = 1;
	while (div * div < x){
		if (!(x % div)){
			kratn[div]++;
			kratn[x / div]++;
		}

		++div;
	}

	if (div * div == x){
		kratn[div]++;
	}
}

int sum(int a, int b){
	int res = a + b;
	if (res >= MOD){
		return res - MOD;
	}

	return res;
}

int fact(ll a, ll b){
	ll res = (a * b) % MOD;
	if (res < 0){
		return res + MOD;
	}

	if (res >= MOD){
		return res - MOD;
	}

	return res;
}

signed main(){
	power[0] = 1;
	for (int i = 1; i < MAXVAL; ++i){
		power[i] = fact(power[i - 1], 2);
	}

	//freopen("input.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; ++i){
		cin >> x;
		add(x);
	}

	ll myans = 0;
	for (ll i = MAXVAL - 1; i >= 2; --i){
		ans[i] = fact(power[kratn[i] - 1], kratn[i]);
		for (int j = i * 2; j < MAXVAL; j += i){
			ans[i] -= ans[j];
		}

		myans = sum(myans, fact(ans[i], i));
	}

	cout << myans;
	return 0;
}