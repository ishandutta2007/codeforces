#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>


using namespace std;


int inf = 1e9;
long long big_inf = 1e18;	
int mod = 1e9 + 7;


int main(){
	ios_base::sync_with_stdio(false);
	
	
	vector <long long> power(300228), pow_sum(300228);
	power[0] = 1;
	for (int i = 1; i < 300228; ++i){
		power[i] = (power[i - 1] * 2) % mod;
	}

	pow_sum[0] = 1;
	for (int i = 1; i < 300228; ++i){
		pow_sum[i] = (pow_sum[i - 1] + power[i]) % mod;
	}


	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	
	vector <long long> dp(n);
	dp[0] = 0;
	for (int i = 1; i < n; ++i){
		dp[i] = (dp[i - 1] * 2 + (a[i] - a[i - 1]) * pow_sum[i - 1]) % mod;
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i){
		ans = (ans + dp[i]) % mod;
	}

	cout << ans;
	return 0;
}