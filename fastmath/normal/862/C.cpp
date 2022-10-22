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
const int MAXN = 1e5 + 7;
const int BIT = 20;
const int MAXV = 1e6;

int want[BIT];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;

	if (n == 2 && x == 0){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	if (n == 1){
		cout << x << '\n';
		return 0;
	}

	if (n == 2){
		cout << x << " 0\n";
		return 0;
	}

	for (int i = 0; i < BIT; ++i){
		want[i] = ((x >> i) & 1);
	}

	vector <int> ans(n);
	for (int i = 1; i <= n - 1; ++i){
		ans[i - 1] = i;

		for (int j = 0; j < BIT; ++j){
			want[j] ^= ((i >> j) & 1);
		}
	}

	int last = 0;
	for (int i = 0; i < BIT; ++i){
		if (want[i]) last += (1 << i);
	}

	if (last <= n - 1){
		if (last == 1){
			ans[1] += (1 << 17);
			last += (1 << 17);
		}
		else{
			ans[0] += (1 << 17);
			last += (1 << 17);
		}
	}

	for (int i = 0; i < n - 1; ++i){
		cout << ans[i] << ' ';
	}

	cout << last << '\n';
	return 0;
}