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

int all, n;

int get(int l, int r){
	string q = "";
	for (int i = 1; i < l; ++i){
		q += "0";
	}

	for (int i = 0; i < r - l + 1; ++i){
		q += "1";
	}

	for (int i = r + 1; i <= n; ++i){
		q += "0";
	}

	cout << "? " << q << endl;
	fflush(stdout);

	int res;
	cin >> res;
	fflush(stdout);

	int razn = res - all;
	int len = r - l + 1;
	return (razn + len) / 2;
}

int find0(int l, int r){
	if (l == r){
		return l;
	}

	int m = (l + r) / 2;
	int left = get(l, m);
	if (left){
		return find0(l, m);
	}
	else{
		return find0(m + 1, r);
	}
}

int find1(int l, int r){
	if (l == r){
		return l;
	}

	int m = (l + r) / 2;
	int left = (m - l + 1) - get(l, m);
	if (left){
		return find1(l, m);
	}
	else{
		return find1(m + 1, r);
	}
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	ios_base::sync_with_stdio(false);
	cin >> n;
	fflush(stdout);

	string q = "";
	for (int i = 0; i < n; ++i){
		q += "0";
	}

	cout << "? " << q << endl;
	fflush(stdout);
	cin >> all;
	fflush(stdout);

	int l = 1;
	int r = n;
	while (true){
		int m = (l + r) / 2;
		int left = get(l, m);

		if (left == 0){
			int ans0 = find0(m + 1, r);
			int ans1 = m;

			cout << "! " << ans0 << ' ' << ans1 << endl;
			fflush(stdout);
			return 0;
		}

		if (left == m - l + 1){
			int ans0 = m;
			int ans1 = find1(m + 1, r);

			cout << "! " << ans0 << ' ' << ans1 << endl;
			fflush(stdout);
			return 0;
		}

		r = m;
	}

	return 0;
}