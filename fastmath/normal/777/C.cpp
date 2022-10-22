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

int pref[MAXN];

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > a(n), dp(n);
	for (int i = 0; i < n; ++i){
		a[i].resize(m);
		dp[i].resize(m);
		for (int j = 0; j < m; ++j) cin >> a[i][j];
	}

	vector <int> best(n);
	best[n - 1] = 1;
	for (int i = 0; i < m; ++i) dp[n - 1][i] = 1;
	for (int i = n - 2; i >= 0; --i){
		best[i] = -MOD;
		for (int j = 0; j < m; ++j){
			if (a[i][j] <= a[i + 1][j]){
				dp[i][j] = dp[i + 1][j] + 1;
			}
			else{
				dp[i][j] = 1;
			}

			best[i] = max(best[i], dp[i][j]);
		}
	}

	int q;
	cin >> q;
	int l, r;
	for (int i = 0; i < q; ++i){
		cin >> l >> r;
		if (best[l - 1] >= r - l + 1){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
	}

	return 0;
}