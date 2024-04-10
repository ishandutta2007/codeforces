#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define f first
#define s second
#define INF 1000000007

using namespace std;


ll c[19], l[1005], r[1005];
double dp[1005][1005];


ll sum (ll a){
	if (a == -1) return 0;
	ll aa = a, pow = 1;
	ll k = 0;
	while (a > 9){
		k++;
		pow *= 10;
		a /= 10;
	}
	if (a > 1) return c[k];
	else if (k == 0) return a;
	else return c[k - 1] + aa - pow + 1;
}


double p(ll a, ll b){
	return 1. * (-sum(a - 1) + sum(b)) / (b - a + 1); 
}

int main(){
	cout.precision(10);
	c[0] = 1;
	ll k = 10;
	for (int i = 1; i < 19; i++) {
		c[i] = c[i - 1] + k;
		k *= 10;
	}
	int n, w, num;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	cin >> w;
	num = (n * w + 99) / 100;
	for (int i = 0; i < n; i++){
		double prob = p(l[i], r[i]);
		if (i == 0) {
			dp[i][0] = 1 - prob; dp[i][1] = prob;
		} else 
		for (int j = 0; j <= i + 1; j++){
			if (j == 0) dp[i][j] = (1 - prob) * dp[i - 1][j];
			else dp[i][j] = prob * dp[i - 1][j - 1] + (1 - prob) * dp[i - 1][j]; 
		}
	}
	double ans = 0, s = 0;
	for (int i = n; i > num - 1; i--){
		ans += dp[n - 1][i];
	}

	cout << ans;
	return 0;
}