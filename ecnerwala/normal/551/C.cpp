#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

typedef long long ll;

ll N, M;
ll A[MAXN];

ll r[MAXN];

bool is_good(ll t) {
	memcpy(r, A, sizeof(A));
	for(ll i = N, s = M, b = 0; i > 0; ) {
		if(r[i]) {
			if(!b) {
				if(!s) {
					return false;
				}
				b = t - i;
				s --;
			}
			ll v = min(b, r[i]);
			b -= v;
			r[i] -= v;
		} else {
			i--;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(ll i = 1; i <= N; i++) {
		cin >> A[i];
	}

	ll mi = 0, ma = 1e18;

	while(ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if(is_good(md)) ma = md;
		else mi = md;
	}

	cout << ma << '\n';

	return 0;
}