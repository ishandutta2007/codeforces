#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
int A[MAXN];
int invB[MAXN];

int exitTime[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i] --;
	}
	for (int i = 0; i < N; i++) {
		int b; cin >> b; b--;
		invB[b] = i;
	}

	for (int i = 0; i < N; i++) {
		exitTime[i] = invB[A[i]];
	}

	int lastExit = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		assert(exitTime[i] < N);
		if (exitTime[i] < lastExit) {
			ans++;
		}
		lastExit = max(lastExit, exitTime[i]);
	}

	cout << ans << '\n';
	return 0;
}