#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e6;
int N;
ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack<pair<ll, ll>> st;
	for (int i = 0; i < N; i++) {
		pair<ll, ll> v(A[i], 1);
		while (!st.empty() && v.first * st.top().second <= st.top().first * v.second) {
			v.first += st.top().first;
			v.second += st.top().second;
			st.pop();
		}
		st.push(v);
	}
	vector<pair<ll, ll>> res(st.size());
	while (!st.empty()) {
		res[st.size()-1] = st.top();
		st.pop();
	}

	for (auto it : res) {
		long double v = ((long double)(it.first)) / it.second;
		for (int z = 0; z < it.second; z++) {
			cout << fixed << setprecision(20) << v << '\n';
		}
	}

	return 0;
}