#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 1e5+5;

int a[ms];

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	int total = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] != total && a[i] != 0) {
			total = a[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}