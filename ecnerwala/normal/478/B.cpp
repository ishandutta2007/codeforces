#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c2(ll a) { return a * (a - 1) / 2; }

int main() {
	ll n, m; cin >> n >> m;
	cout << c2(n / m) * (m - n % m) + c2(n / m + 1) * (n % m) << ' ';
	cout << c2(n - m + 1) << '\n';
	return 0;
}