#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 4e5;
int N;
int A[MAXN];
int cnt[MAXN][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	ll res = 0;

	A[0] = 0;
	cnt[0][0] = 1;
	cnt[0][1] = 0;

	for (int i = 0; i < N; i++) {
		unsigned long long v; cin >> v;
		A[i+1] = A[i] + __builtin_popcountll(v);

		res += cnt[i][A[i+1]&1];

		cnt[i+1][0] = cnt[i][0];
		cnt[i+1][1] = cnt[i][1];
		cnt[i+1][A[i+1]&1]++;
	}

	for (int i = 0; i < N; i++) {
		int v = (A[i+1] - A[i]) * 2;
		assert(v > 0);
		int l = i;
		int r = i+1;
		assert(A[r] - A[l] < v);
		while (l > 0 && A[r] - A[l-1] < v) l--;
		for (; l <= i; l++) {
			while (r+1 <= N && A[r+1] - A[l] < v) r++;
			assert(A[r] - A[l] < v);
			assert(r >= i+1);
			assert(l <= i);
			res -= cnt[r][A[l]&1] - cnt[i][A[l]&1];
		}
	}
	cout << res << '\n';

	return 0;
}