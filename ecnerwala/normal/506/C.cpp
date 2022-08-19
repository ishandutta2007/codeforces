#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;
#define A first
#define B second

const int MAXN = 2e5;
const int MAXM = 6e3;
const int MAXK = 20;

const ll INF = 1e18;

ll N, M, K, P;
ll H[MAXN], A[MAXN];

ll ceil(ll a, ll b) {
	if(a < 0) return 0;
	return (a + b - 1) / b;
}

ll floor(ll a, ll b) {
	if(a < 0) return 0;
	return a / b;
}

// for each suffix, ceil((A[i] * t - r) / P)
// for t = M, ceil((H + A[i] * t - r)/ P)
bool isgood(ll R) {

	ll cnt = 0;

	for(ll i = 0; i < N; i++) {
		cnt += ceil(H[i] + A[i] * M - R, P);
	}
	if(cnt > M * K) return false;

	cnt = 0;

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	for(ll i = 0; i < N; i++) {
		// first t so that 
		// (A[i] * t - r) / P > v
		// A[i] * t - r > P * v
		// A[i] * t > P * v + r
		// t > floor(P * v + r, A[i])
		// t >= floor(P * v + r, A[i]) + 1

		pq.push(pll(R / A[i] + 1, i));
	}

	for(ll t = 1; t <= M; t++) {
		while(!pq.empty() && pq.top().A == t) {
			int i = pq.top().B;
			pq.pop();
			cnt -= ceil(A[i] * (t - 1) - R, P);
			ll v = ceil(A[i] * t - R, P);
			cnt += v;

			ll n = (P * v + R) / A[i] + 1;
			assert(ceil(A[i] * n - R, P) > v);
			assert(n > t);
			if(n <= M) pq.push(pll(n, i));
		}
		if(cnt > (t - 1) * K) return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K >> P;
	for(ll i = 0; i < N; i++) {
		cin >> H[i] >> A[i];
	}

	ll mi = -1, ma = INF;
	while(ma - mi > 1) {
		ll md = (mi + ma) / 2;
		if(isgood(md)) ma = md;
		else mi = md;
	}
	cout << ma << '\n';
	return 0;
}