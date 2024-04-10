#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int A[MAXN], B[MAXN];
pair<int, int> P[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		P[i].first = B[i] - A[i];
		P[i].second = i;
	}
	sort(P + 1, P + N + 1);
	ll res = 0;
	for (int j = 1; j <= N; j++) {
		int i = P[j].second;
		res += ll(A[i]) * ll(j-1) + ll(B[i]) * ll(N - j);
	}
	cout << res << '\n';

	return 0;
}