#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

typedef pair<ll, ll> pii;
#define A first
#define B second

pii operator *(pii a, pii b) {
	// apply a then b
	return pii(a.A * b.A % MOD, (a.B * b.A + b.B) % MOD);
}

pii op[20];

int main() {
	ios_base::sync_with_stdio(0);
	for(int i = 0; i < 10; i++) op[i] = pii(10, i);
	vector<pair<int, string>> ops;
	string s; cin >> s;
	ops.push_back(make_pair(0, s));
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> s;
		int d = s[0] - '0';
		s = s.substr(3);
		ops.push_back(make_pair(d, s));
	}
	reverse(ops.begin(), ops.end());

	for(auto it : ops) {
		int d = it.first;
		string s = it.second;
		pii val(1, 0);
		for(char c : s) {
			int v = c - '0';
			val = val * op[v];
		}
		op[d] = val;
	}

	cout << op[0].second << '\n';
	return 0;
}