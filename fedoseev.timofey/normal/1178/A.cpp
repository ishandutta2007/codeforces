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
    int n;
    cin >> n;
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    vector <int> id = {0};
	int ts = a[0];
	for (int i = 1; i < n; ++i) {
		if (2 * a[i] <= a[0]) id.push_back(i), ts += a[i];
	}
	if (2 * ts > sum) {
		cout << id.size() << '\n';
		for (int i : id) cout << i + 1 << ' ';
	} else {
		cout << "0\n";
	}
}