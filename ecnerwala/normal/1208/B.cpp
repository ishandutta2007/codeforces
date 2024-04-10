#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4000;
int N;
int A[MAXN];


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int numDup = 0;
	unordered_map<int, int> cnt;
	for (int i = 0; i < N; i++) {
		numDup += ((++cnt[A[i]]) == 2);
	}

	int ans = N+1;
	for (int l = 0, r = 0; l <= N; l++) {
		while (numDup) {
			if (r == N) goto done;
			numDup -= ((cnt[A[r]]--) == 2);
			r++;
		}
		ans = min(ans, r - l);
		// insert A[l]
		if (l == r) {
			r++;
		} else {
			numDup += ((++cnt[A[l]]) == 2);
		}
	}
done:
	cout << ans << '\n';


	return 0;
}