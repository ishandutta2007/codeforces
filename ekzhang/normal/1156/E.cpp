#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAXLG 18
int N;
int A[MAXN], iA[MAXN];
int T[MAXLG][MAXN];
LL ans = 0;

inline int qry(int lo, int hi) {
	int len = (hi - lo + 1);
	int k = 31 - __builtin_clz(len);
	return max(T[k][lo], T[k][hi - (1<<k) + 1]);
}

void solve(int s, int e) {
	if (s >= e)
		return;
	int mx = qry(s, e);
	int mid = iA[mx];
	if (mid - s < e - mid) {
		for (int i = s; i < mid; i++) {
			int j = iA[mx - A[i]];
			if (mid < j && j <= e)
				++ans;
		}
	}
	else {
		for (int i = mid + 1; i <= e; i++) {
			int j = iA[mx - A[i]];
			if (s <= j && j < mid)
				++ans;
		}
	}
	solve(s, mid - 1);
	solve(mid + 1, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		iA[A[i]] = i;
		T[0][i] = A[i];
	}

	for (int k = 0; k < MAXLG - 1; k++)
		for (int i = 0; i + (1<<k) < N; i++)
			T[k + 1][i] = max(T[k][i], T[k][i + (1<<k)]);

	solve(0, N - 1);

	cout << ans << endl;
	return 0;
}