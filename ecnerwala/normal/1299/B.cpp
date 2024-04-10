#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<pair<ll, ll>> P(N+1);
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
	}
	P[N] = P[0];
	for (int i = 0; i < N; i++) {
		P[i].first = P[i+1].first - P[i].first;
		P[i].second = P[i+1].second - P[i].second;
	}
	P.pop_back();

	bool good = (N % 2 == 0);
	for (int i = 0; good && i < N/2; i++) {
		good = good && (P[i].first == -P[i+N/2].first && P[i].second == -P[i+N/2].second);
	}
	cout << (good ? "YES" : "NO") << '\n';

	return 0;
}