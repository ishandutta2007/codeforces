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
const int MAXN = 107;


signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; ++i){
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	if (a[n - 1] == a[n]){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}

	return 0;
}