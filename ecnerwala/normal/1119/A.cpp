#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int C[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> C[i];
	int hi = N-1; while (C[hi] == C[0]) --hi;
	int lo = 0; while (C[lo] == C[N-1]) ++lo;
	cout << max(N-1-lo, hi-0) << '\n';

	return 0;
}