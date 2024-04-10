#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll go(ll l, ll r) {
	assert(l <= r);
	if(l == r) return l;
	else if(l / 2 == r / 2) return r;
	else return go(l / 2, (r - 1) / 2) * 2 + 1;
}

int main() {
	int N; cin >> N;
	for(int i = 0; i < N; i++) {
		ll l, r; cin >> l >> r;
		cout << go(l, r) << '\n';
	}
	return 0;
}