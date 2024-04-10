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

#define x first
#define y second
#define prev _prev
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	int a[6];
	for (int i = 0; i < 6; ++i){
		a[i] = s[i] - '0';
	}

	int b[6];
	vector <int> p = { 1000000, 100000, 10000, 1000, 100, 10, 1 };
	int ans = MOD;
	for (int i = 0; i < 1e7; ++i){
		for (int j = 0; j < 6; ++j){
			b[j] = (i / p[j]) % 10;
		}

		if (b[0] + b[1] + b[2] == b[3] + b[4] + b[5]){
			int otl = 0;
			for (int j = 0; j < 6; ++j){
				otl += (a[j] != b[j]);
			}

			ans = min(ans, otl);
		}
	}

	cout << ans << '\n';
	return 0;
}