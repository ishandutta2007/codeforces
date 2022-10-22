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

int rst(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) *  abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2);
}

int kv(int n){
	return n * n;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int r, d, n;
	cin >> r >> d >> n;
	int x1, y1, r1;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		cin >> x1 >> y1 >> r1;

		if (rst(0, 0, x1, y1) >= kv((r - d) + r1) && rst(0, 0, x1, y1) <= kv(r - r1)){
			++ans;
		}
	}

	cout << ans;
	return 0;
}