#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int arr[n];
	ll sum[n+1][n+1]; // l, r
	sum[0][0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < i+1; j++) {
			sum[j][i+1] = sum[j][i] + arr[i];
		} sum[i+1][i+1] = 0;
	}
	pii minleft[n+1]; // up to but not including i
	minleft[0] = pii(0,0);
	for (int i = 1; i <= n; i++) {
		minleft[i] = minleft[i-1];
		ll currsum = sum[minleft[i].first][minleft[i].second];
		for (int left = 0; left < i; left++) {
			if (sum[left][i] < currsum) {
				currsum = sum[left][i];
				minleft[i] = pair<int,int>(left, i);
			}
		}
		//cerr << "minleft " << i << ": " << minleft[i].first << " " << minleft[i].second << nl;
	}
	// get ans
	int a, b, c; // ans
	ll best = INFLL;
	for (int i = 0; i <= n; i++) {
		int bestleft = i;
		for (int j = i; j <= n; j++) {
			if (sum[i][n] < sum[bestleft][n])
				bestleft = i;
		}
		if (sum[minleft[i].first][minleft[i].second] + sum[bestleft][n] < best) {
			best = sum[minleft[i].first][minleft[i].second] + sum[bestleft][n];
			a = minleft[i].first;
			b = minleft[i].second;
			c = bestleft;
		}
	}
	cout << a << " " << b << " " << c << nl;

	return 0;
}