#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// r rooms, i levels
// N = r * 3 - i
// r >= i * (i + 1) / 2
int main() {
	ll N; cin >> N;
	ll res = 0;
	for(ll i = 1; i * (i + 1) / 2 * 3 - i <= N; i++) {
		if((N + i) % 3 == 0) res++;
	}
	cout << res << '\n';
	return 0;
}