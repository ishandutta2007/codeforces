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
const int MAXN = 5e5 + 7;
const int BASE = 129;

int power[MAXN];
vector <int> h[MAXN];

int form(int n){
	if (n < 0) return n + MOD;
	if (n >= MOD) return n - MOD;
	return n;
}

int sum(int a, int b){
	return form(a + b);
}

int fact(int a, int b){
	return form((a * b) % MOD);
}

int get(int i, int l, int r){
	return sum(h[i][r], -fact(h[i][l - 1], power[r - l + 1]));
}

signed main(){
	power[0] = 1;
	for (int i = 1; i < MAXN; ++i){
		power[i] = fact(power[i - 1], BASE);
	}

	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i){
		h[i].resize(a[i].size() + 1);
		for (int j = 1; j <= a[i].size(); ++j){
			h[i][j] = sum(fact(h[i][j - 1], BASE), a[i][j - 1]);
		}
	}

	int last = a[n - 1].size();
	vector <string> ans(n);
	ans[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i){
		int l = 1;
		int r = min((int)a[i].size(), last) + 1;
		while (l < r - 1){
			int m = (l + r) / 2;
			if (h[i][m] == h[i + 1][m]){
				l = m;
			}
			else{
				r = m;
			}
		}

		if (l == min((int)a[i].size(), last)){
			if (a[i].size() <= last){
				for (int j = 0; j < a[i].size(); ++j){
					ans[i] += a[i][j];
				}

				last = a[i].size();
			}
			else{
				for (int j = 0; j < last; ++j){
					ans[i] += a[i][j];
				}

				last = last;
			}
		}
		else{
			if (a[i][l] < a[i + 1][l]){
				ans[i] = a[i];
				last = a[i].size();
			}
			else{
				for (int j = 0; j < l; ++j){
					ans[i] += a[i][j];
				}

				last = l;
			}
		}
	}

	for (int i = 0; i < n; ++i){
		cout << ans[i] << '\n';
	}

	return 0;
}