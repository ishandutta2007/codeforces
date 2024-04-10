#include <bits/stdc++.h>
#define ll int64_t
#define elif else if
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
	cin >> n;
	if (n % 2020 <= n / 2020) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
    }
}