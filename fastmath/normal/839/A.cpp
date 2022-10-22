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

#define x first
#define y second
#define prev _prev
#define rand() rand()<<15+rand()
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
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int ans = 0;
	int have = 0;
	for (int i = 0; i < n; ++i){
		have += a[i];

		int give = min(8, have);
		ans += give;
		have -= give;

		if (ans >= k){
			cout << i + 1 << '\n';
			return 0;
		}

	}

	cout << "-1\n";
	return 0;
}