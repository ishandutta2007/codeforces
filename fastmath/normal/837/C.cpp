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
mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const int MAXN = 107;
typedef long long ll;

pair <int, int> a[MAXN];

bool in(int x1, int y1, int x2, int y2){
	return (x1 <= x2 && y1 <= y2) || (y1 <= x2 && x1 <= y2);
}

bool check(int x1, int y1, int x2, int y2, int x, int y){
	if (x1 <= x && y1 <= y){
		if (in(x2, y2, x - x1, y) || in(x2, y2, x, y - y1)){
			return true;
		}
	}

	swap(x1, y1);

	if (x1 <= x && y1 <= y){
		if (in(x2, y2, x - x1, y) || in(x2, y2, x, y - y1)){
			return true;
		}
	}

	return false;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; ++i){
		cin >> a[i].x >> a[i].y;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (check(a[i].x, a[i].y, a[j].x, a[j].y, x, y)){
				ans = max(ans, a[i].x * a[i].y + a[j].x * a[j].y);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}