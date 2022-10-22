#include <bits/stdc++.h>
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll A[105];

ll H;
int N;

bool isp(ll X) {
	ll ret = 0;
	ll pv = -1;
	for(int i = 0; i < N; i++) {
		ret += (A[i] + X - 1) - max(pv + 1, A[i]) + 1;
		pv = A[i] + X - 1;
	}
	return ret >= H;
}

void solve() {
	cin >> N >> H;
	for(int i = 0; i < N; i++)
		cin >> A[i];

	ll s = 1, e = H;
	while(s < e) {
		ll m = s+e >> 1;
		if(isp(m)) e = m;
		else s = m+1;
	}
	cout << s << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int T;
	cin >> T;

	while(T--) solve();
	return 0;
}