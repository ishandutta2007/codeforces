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

	int n, k, total;
	cin >> n >> k >> total;
	int sub[k];
	int sum = 0;
	for (int i = 0; i < k; i++) {
		cin >> sub[i];
		sum += sub[i];
	} sort(sub, sub+k);

	int ans = 0;
	for (int c = 0; c <= n; c++) {
		if (sum * c > total) break;
		int curr = c*(k+1);
		int temp = total - sum*c;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < n-c; j++) {
				temp -= sub[i];
				if (temp < 0) break;
				else curr++;
			}
		}
		ans = max(ans, curr);
	}
	cout << ans << nl;

	return 0;
}