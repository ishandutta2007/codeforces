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
const int MOD = 1e18 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 5e3 + 7;

int a[MAXN], sums[MAXN], pref[MAXN], pref_i[MAXN];

int get(int l, int r){
	if (l > r) return 0;
	return sums[r] - sums[l - 1];
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

	sums[0] = 0;
	for (int i = 1; i <= n; ++i){
		sums[i] = sums[i - 1] + a[i - 1];
	}
	sums[n + 1] = sums[n];

	for (int i = 0; i <= n; ++i){
		pref[i] = -MOD;
		for (int j = 0; j <= i; ++j){

			if (get(1, j) - get(j + 1, i) > pref[i]){
				pref[i] = get(1, j) - get(j + 1, i);
				pref_i[i] = j;
			}
			
		}
	}

	int ans = -MOD;
	int best1, best2, best3;
	for (int i = 1; i <= n; ++i){
		for (int j = i; j <= n; ++j){

			if (get(i + 1, j) - get(j + 1, n) + pref[i] > ans){
				ans = get(i + 1, j) - get(j + 1, n) + pref[i];
				best1 = pref_i[i];
				best2 = i;
				best3 = j;
			}

		}
	}

	cout << best1 << ' ' << best2 << ' ' << best3 << '\n';
	return 0;
}