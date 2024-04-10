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
const int MAXN = 507;

bool dp[MAXN][MAXN];

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

	dp[0][0] = true;
	for (int i = 0; i < n; ++i){
		for (int sum = MAXN - 1; sum >= 0; --sum){
			for (int want = MAXN - 1; want >= 0; --want){
				dp[sum][want] = (dp[sum][want] || (a[i] <= sum && dp[sum - a[i]][want]) || (a[i] <= sum && a[i] <= want && dp[sum - a[i]][want - a[i]]));
			}
		}
	}

	vector <int> ans;
	for (int want = 0; want < MAXN; ++want){
		if (dp[k][want]){
			ans.push_back(want);
		}
	}

	cout << ans.size() << '\n';
	for (int elem : ans){
		cout << elem << ' ';
	}

	return 0;
}