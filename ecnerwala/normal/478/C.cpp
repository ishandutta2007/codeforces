#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	ll r, g, b; cin >> r >> g >> b;
	ll res = min((r + g + b) / 3, r + g + b - max(r, max(g, b)));
	cout << res << '\n';
	return 0;
}