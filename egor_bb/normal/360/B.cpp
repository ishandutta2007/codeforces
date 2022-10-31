#pragma comment (linker, "/STACK:100000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e17 + 7)
#define sort stable_sort

using namespace std;



ll n, a[2005], k;

/*ll gsum(ll a, ll b){
	return (sum[b] - sum[a - 1]);
}*/

ll min(ll a, ll b){
	if (a < b) return a;
	return b;
}

bool check (ll c){
	ll dp[2005], ans = 0;
	dp[0] = 1;
	for (int i = 1; i < n; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (abs (a[i] - a[j]) <= c * (i - j)) dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	if (n - ans <= k) return true;
	return false;
}

int main(){
//	ifstream cin ("in.txt");
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	check(1000000000);
	ll lft = -1, rgt = INFll;
	while (rgt - lft > 1){
		ll m = (lft + rgt) / 2;
	//	cout << m << '\n';
		if (check(m)){
			rgt = m;
		}
		else lft = m;
	}
	cout << rgt;
	return 0;
}