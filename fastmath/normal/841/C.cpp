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
const int MAXN = 3e5 + 7;

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector <pair <int, int> > a(n);
	vector <pair <int, int> > b(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i].x;
		a[i].y = i;
	}

	for (int i = 0; i < n; ++i){
		cin >> b[i].x;
		b[i].y = i;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector <int> ans(n);
	for (int i = 0; i < n; ++i){
		ans[b[n - i - 1].y] = a[i].x;
	}

	for (int i = 0; i < n; ++i){
		cout << ans[i] << ' ';
	}

	return 0;
}