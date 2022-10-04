#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector <int> a(10);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	char c;
    	cin >> c;
    	if (c == 'L') {
    		int uk = 0;
    		while (a[uk] == 1) ++uk;
    		a[uk] = 1;
    	} else if (c == 'R') {
    		int uk = 9;
    		while (a[uk] == 1) --uk;
    		a[uk] = 1;
    	} else {
    		a[c - '0'] = 0;
    	}
	}
	for (int i = 0; i < 10; ++i) {
		cout << a[i];
	}
}