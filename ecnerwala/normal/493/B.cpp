#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

list<ll> m[2];
ll s[2];
int main() {
	int n; cin >> n;
	int last;
	for(int i = 0; i < n; i++) {
		ll v; cin >> v;
		last = v > 0;
		m[v > 0].push_back(abs(v));
		s[v > 0] += abs(v);
	}
	m[0].push_front(s[0]);
	m[1].push_front(s[1]);
	if(m[0] == m[1]) m[last].push_back(1);
	cout << ((m[1] > m[0]) ? "first" : "second") << '\n';
	return 0;
}