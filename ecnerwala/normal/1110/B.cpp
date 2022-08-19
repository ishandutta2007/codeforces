#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll M;
ll B[MAXN];
int K;
ll segs[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	ll ans = B[N-1] - B[0] + 1;

	for (int i = 0; i < N-1; i++) {
		segs[i] = B[i+1] - B[i] - 1;
	}
	sort(segs, segs + N - 1);
	reverse(segs, segs + N - 1);
	for (int i = 0; i < N-1 && i < K-1; i++) {
		ans -= segs[i];
	}

	cout << ans << '\n';

	return 0;
}