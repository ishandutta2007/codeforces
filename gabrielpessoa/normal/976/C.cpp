#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 3e5 + 5;

iii a[ms];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second;
		a[i].first.second = -a[i].first.second;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	for(int i = 1; i < n; i++) {
		if(a[i].first.second >= a[i-1].first.second) {
			cout << a[i].second << ' ' << a[i-1].second << '\n';
			return 0;
		}
	}
	cout << -1 << ' ' << -1 << '\n';
}