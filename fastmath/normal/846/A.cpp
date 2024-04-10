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

#define prev _prev
#define hash _hash;
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 107;

int a[MAXN];
int pref_0[MAXN], post_1[MAXN];

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

	pref_0[0] = 0;
	for (int i = 1; i <= n; ++i){
		pref_0[i] = pref_0[i - 1] + (!a[i - 1]);
	}

	post_1[n] = 0;
	for (int i = n - 1; i >= 0; --i){
		post_1[i] = post_1[i + 1] + a[i];
	}

	int ans = 0;
	for (int i = 0; i <= n; ++i){
		ans = max(ans, pref_0[i] + post_1[i]);
	}

	cout << ans << '\n';
	return 0;
}