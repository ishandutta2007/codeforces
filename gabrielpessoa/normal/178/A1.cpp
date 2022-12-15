#include<bits/stdc++.h>
using namespace std;

const int ms = 1e5+5;

int a[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int t = 1;
		while(i + (t << 1) < n) {
			t <<= 1;
		}
		ans += a[i];
		a[i+t] += a[i];
		a[i] = 0;
		cout << ans << '\n';
	}
	return 0;
}