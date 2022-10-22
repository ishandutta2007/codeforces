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
	int l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for (int i = x; i <= y; ++i){
		if (i * k >= l && i * k <= r){
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}