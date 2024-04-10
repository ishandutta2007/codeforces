#include<bits/stdc++.h>
using namespace std;

const int MAXK = 1.1e6;
const int MAXN = 2.1e5;
int N;
int A[MAXN];
int K;
int cnt[MAXK];
int D;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> K >> D;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			cnt[A[i]] = 0;
		}

		int val = 0;
		for (int i = 0; i < D; i++) {
			val += !(cnt[A[i]]++);
		}
		int ans = val;
		for (int i = D; i < N; i++) {
			val -= !(--cnt[A[i-D]]);
			val += !(cnt[A[i]]++);
			ans = min(ans, val);
		}
		cout << ans << '\n';
	}

	return 0;
}