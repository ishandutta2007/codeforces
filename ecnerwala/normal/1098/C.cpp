#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 1.1e5;
ll N, S;

ll P[MAXN];

namespace bf2 {
int M;
ll min2[MAXN];
ll max2[MAXN];

void build(int prv, ll sz, ll sum) {
	assert(sum <= max2[sz]);
	assert(sum >= min2[sz]);
	if (sz == 0) {
		return;
	}

	int cur = ++M;
	P[cur] = prv;

	sum -= sz; // everything drops by 1 depth
	sz--;
	ll mi = -1;
	ll ma = sz / 2;
	assert(min2[ma] + min2[sz - ma] <= sum);
	while (ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if (min2[md] + min2[sz - md] <= sum) {
			ma = md;
		} else {
			mi = md;
		}
	}
	assert(min2[ma] + min2[sz - ma] <= sum);
	assert(max2[ma] + max2[sz - ma] >= sum);

	ll l = ma, r = sz - ma;
	ll lsum = max(min2[l], sum - max2[r]);
	ll rsum = min(sum - min2[l], max2[r]);

	build(cur, l, lsum);
	build(cur, r, rsum);
}

void go() {
	min2[0] = max2[0] = 0;
	for (ll i = 1; i <= N; i++) {
		max2[i] = max2[i-1] + i;
	}
	for (ll d = 0; (1ll << d) <= N; d++) {
		for (ll i = (1ll << d); i <= N && i < 2 * (1ll << d); i++) {
			min2[i] = min2[i-1] + (d+1);
		}
	}

	assert(S <= max2[N]);
	assert(S >= min2[N]);

	// do some recursive stuff I guess
	M = 0;
	build(0, N, S);
	assert(M == N);
}

} // namespace bf2

namespace bfsmall {
void go(ll bf) {
	map<ll, ll> cnts;
	ll sval = S;
	for (ll s = 1, d = 1, cnt = N; cnt > 0; s *= bf, d++) {
		s = min(s, cnt);
		cnts[d] = s;
		sval -= d * s;
		cnt -= s;
	}
	stack<ll> deeps;
	while (sval > 0) {
		auto it = cnts.rbegin();
		ll d = it->first;
		ll c = it->second;
		assert(c > 0);

		if (c == 1) {
			deeps.push(d);
			cnts.erase(d);
		} else {
			cnts[d]--;
			cnts[d+1] ++;
			sval--;
			if (!deeps.empty()) {
				assert(deeps.top() == d+1);
				cnts[d+1] ++;
				deeps.pop();
			}
		}
	}
	while (!deeps.empty()) {
		cnts[deeps.top()]++;
		deeps.pop();
	}
	ll st = 0, en = 0;
	for (auto it : cnts) {
		ll c = it.second;
		// inclusive range
		ll nst = en + 1;
		ll nen = en + c;
		for (ll i = 0; i < c; i++) {
			assert(st + (i / bf) <= en);
			P[nst + i] = st + (i / bf);
		}
		st = nst, en = nen;
	}
}

} // namespace bfsmall

void go() {
	if (S > N * (N+1) / 2) {
		cout << "No" << '\n';
		return;
	}
	if (S < 2 * N - 1) {
		cout << "No" << '\n';
		return;
	}

	// compute the branching factor
	ll bf = 1;
	ll tot;
	do {
		bf++;
		tot = 0;
		ll cnt = N;
		for (ll s = 1, d = 1; cnt > 0; s *= bf, d++) {
			s = min(s, cnt);
			tot += d * s;
			cnt -= s;
		}
	} while (tot > S);
	assert(bf >= 2);
	if (bf == 2) {
		bf2::go();
	} else {
		bfsmall::go(bf);
	}


	cout << "Yes" << '\n';
	for (int i = 2; i <= N; i++) {
		cout << P[i] << " \n"[i==N];
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> S;
	go();
	return 0;
}