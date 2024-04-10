#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5;
int N;
ll V[MAXN];
ll T[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> V[i];
	for (int i = 0; i < N; i++) cin >> T[i];

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	ll cur = 0;
	for (int i = 0; i < N; i++) {
		pq.push(V[i] + cur);
		ll v = 0;
		while (!pq.empty() && pq.top() <= T[i] + cur) {
			assert(pq.top() >= cur);
			v += pq.top() - cur;
			pq.pop();
		}
		v += ll(pq.size()) * T[i];
		cout << v << '\n';
		cur += T[i];
	}

	return 0;
}