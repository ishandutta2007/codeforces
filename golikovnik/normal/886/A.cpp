#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	vector<int> a(6);
	int s = 0;
	for (int i = 0; i < 6; ++i) {
		cin >> a[i];
		s += a[i];
	}	
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			for (int k = j + 1; k < 6; ++k) {
				int s1 = a[i] + a[j] + a[k];
				int s2 = s - s1;
				if (s1 == s2) {
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	return 0;
}