#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
const int MAXS = 2e5;
int N;
ll S;


map<ll, ll> neg, pos;

// returns weighted sum
ll rem_last(map<ll, ll> &mp, ll cnt) {
	ll val = 0;
	while (cnt) {
		assert(!mp.empty());
		auto it = mp.end();
		it--;
		ll s = it->second;
		val += it->first * min(s, cnt);
		if (s <= cnt) {
			cnt -= s;
			mp.erase(it);
		} else {
			it->second -= cnt;
			cnt = 0;
		}
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> S;
	ll res = 0;
	ll tot = 0;
	ll tot_neg = 0;
	ll tot_pos = 0;
	for (int i = 0; i < N; i++) {
		ll s, a, b;
		cin >> s >> a >> b;
		res += s * a;
		ll diff = b-a;
		tot += s;
		if (diff >= 0) {
			pos[diff] += s;
			tot_pos += s;
		} else {
			neg[-diff] += s;
			tot_neg += s;
		}
	}
	res += rem_last(pos, tot_pos / S * S);
	rem_last(neg, tot_neg / S * S);
	tot_pos %= S;
	tot_neg %= S;
	if (tot_pos + tot_neg > S) {
		res += rem_last(pos, tot_pos);
		rem_last(neg, tot_neg);
	} else if (tot_pos + tot_neg > 0) {
		ll cnd = 0;
		for (auto it : pos) {
			cnd += it.first * it.second;
		}
		for (auto it : neg) {
			cnd -= it.first * it.second;
		}
		if (cnd > 0) res += cnd;
	}
	cout << res << '\n';
	return 0;
}