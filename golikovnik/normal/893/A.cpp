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
	int sit = 3;
	for(int i = 0; i < n; ++i) {
		int win;
		cin >> win;
		if (win == sit) {
			cout << "NO";
			return 0;
		}
		sit = 6 - sit - win;
	}	
	cout << "YES";
	return 0;
}