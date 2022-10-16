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
	vector<int> l(n);
	for(int i = 0; i < n; ++i) cin >> l[i];
	int survived = 0;
	int next = -1;
	for(int i = n-1; i >= 0; --i) {
		if (i == n-1) {
			++survived;
			next = l[i];
			continue;
		}
		if (next == 0) ++survived;
		next = max(next - 1, l[i]);
	}	
	cout << survived;
	return 0;
}