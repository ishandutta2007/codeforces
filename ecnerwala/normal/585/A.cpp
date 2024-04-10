#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN = 5e3;

ll N;
ll V[MAXN];
ll D[MAXN];
ll P[MAXN];
ll nxt[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for(ll i = 0; i < N; i++) cin >> V[i] >> D[i] >> P[i];
	for(ll i = 0; i < N; i++) nxt[i] = i + 1;
	vector<ll> res;

	for(ll cur = 0; cur < N; cur++) {
		if(nxt[cur] == -1) continue;
		res.push_back(cur);
		ll d = 0;
		ll v = V[cur];
		for(ll prv = cur, i = nxt[cur]; i != N; ) {
			if(v > 0) P[i] -= v;
			P[i] -= d;
			if(P[i] < 0) {
				d += D[i];
				nxt[prv] = nxt[i];
				nxt[i] = -1;
				i = nxt[prv];
			} else {
				prv = i;
				i = nxt[i];
			}
			v--;
		}
	}

	cout << res.size() << '\n';
	for(ll i : res) cout << i+1 << ' '; cout << '\n';
	return 0;
}