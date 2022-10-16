#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	ll sum = 0;
	int max1 = -1;
	int max2 = -1;
	for(int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		sum += v;
	}	
	for(int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		if (v > max1) {
			max2 = max1;
			max1 = v;
		} else if (v > max2) {
			max2 = v;
		}
	}
	cout << (max1 + max2 >= sum ? "YES" : "NO");
	return 0;
}