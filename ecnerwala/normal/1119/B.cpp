#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e3;
int N;
ll H;
ll A[MAXN];

bool isGood(int k) {
	vector<ll> tmp;
	for (int i = 0; i < k; i++) {
		tmp.push_back(A[i]);
	}
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	ll t = 0;
	for (int i = 0; i < k; i += 2) t += tmp[i];
	return t <= H;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int mi = 0;
	int ma = N+1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (isGood(md)) mi = md;
		else ma = md;
	}
	cout << mi << '\n';

	return 0;
}