#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	priority_queue<ll> pq;
	
	ll res = 0;
	for(int i = 0; i < N; i++) {
		ll v; cin >> v;
		res += v;
		pq.push(v);
	}

	while(pq.size() >= 2) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		ll v = a + b;
		res += v;
		pq.push(v);
	}

	cout << res << '\n';
	return 0;
}