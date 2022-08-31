#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
ll S[MAXN];
ll pref[MAXN];
const int MAXQ = 1.1e5;
int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	sort(S, S + N);

	for (int i = 0; i+1 < N; i++) {
		S[i] = S[i+1] - S[i];
	}
	// the differences
	sort(S, S + N-1);

	pref[0] = 0;
	for (int i = 0; i < N-1; i++) {
		pref[i+1] = pref[i] + S[i];
	}

	cin >> Q;
	for (int q = 0; q < Q; q++) {
		ll L, R; cin >> L >> R;
		ll W = R - L + 1;
		ll ind = lower_bound(S, S + N - 1, W) - S;
		cout << (N - ind) * W + pref[ind] << " \n"[q+1 == Q];
	}

	return 0;
}