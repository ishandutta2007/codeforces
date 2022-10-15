#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 10000013
int T, N;
int A[MAXN];

void generate() {
	LL l, r, range;
	unsigned x, y, z, b1, b2;
	cin >> l >> r >> x >> y >> z >> b1 >> b2;
	range = r - l + 1;

	A[0] = b1 % range + l;
	A[1] = b2 % range + l;
	for (int i = 2; i < N; i++) {
		unsigned b = b1 * x + b2 * y + z;
		A[i] = b % range + l;
		b1 = b2, b2 = b;
	}
}

LL solve(int* A, int N) {
	int pre = numeric_limits<int>::max();
	LL ans = numeric_limits<LL>::max();
	for (int i = 0; i < N; i++) {
		if (A[i] <= pre)
			pre = A[i];
		else
			ans = min(ans, (LL) pre * A[i]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N;
		generate();

		bool pos = true;
		bool neg = true;
		for (int i = 0; i < N; i++) {
			if (A[i] < 0)
				pos = false;
			if (A[i] > 0)
				neg = false;
		}

		LL ans = -1;

		if (neg) {
			for (int i = 0; i < N; i++)
				A[i] *= -1;
			reverse(A, A + N);
		}
		else if (!pos) {
			// mix of pos and neg
			// Case 1: neg before pos, we gud with current algo
			// Case 2: all pos before all neg, we need to consider separately!
			int lastpos = -1, firstneg = -1;
			for (int i = 0; i < N; i++) {
				if (A[i] > 0)
					lastpos = i;
				else if (A[i] < 0 && firstneg == -1)
					firstneg = i;
			}

			// if all disjoint... (otherwise proceed as normal)
			if (lastpos < firstneg) {
				ans = solve(A, lastpos + 1);
				for (int i = firstneg; i < N; i++)
					A[i] *= -1;
				reverse(A + firstneg, A + N);
				ans = min(ans, solve(A + firstneg, N - firstneg));
			}
		}

		if (ans == -1)
			ans = solve(A, N);
		if (ans == numeric_limits<LL>::max())
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}

	cout.flush();
	return 0;
}