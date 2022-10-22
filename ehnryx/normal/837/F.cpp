#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of python_is_lame:

int n;
ll k;
cin >> n >> k;
vector<ll> a(n);
for (int i = 0; i < n; i++) {
	cin >> a[i];
	if (a[i] >= k) {
		cout << 0 << endl;
		return 0;
	}
}

// binary search
ll left, right, ans;
ll factor, sum;
long double tsum, temp;
left = 1;
right = 1e18-1;
while (left <= right) {
	ans = (left+right)/2;
	// find sum
	sum = 0;
	factor = 1;
	for (int r = 0; r < n; r++) {
		if (factor > 0) {
			tsum = sum + (long double)factor*a[n-r-1];
			if (tsum > 1.1e18) {
				sum = -1;
				break;
			}
			else {
				sum = (ll) tsum;
			}
			if (sum < 0 || sum >= k) {
				sum = -1;
				break;
			}
			temp = (long double)factor*(ans-1+r+1)/(r+1);
			if (temp > 1.1e18) {
				factor = -1;
			}
			else {
				factor = (ll)temp;
			}
		}
		else {
			if (a[n-r-1] == 0) {
				continue;
			}
			else {
				sum = -1;
				break;
			}
		}
	}
	if (sum > 0 && sum < k) {
		left = ans+1;
	}
	else {
		right = ans-1;
	}
}
if (sum > 0 && sum < k)
	ans++;
cout << ans << endl;

The End