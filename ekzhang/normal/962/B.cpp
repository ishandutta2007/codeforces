#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, A[2];
string S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> A[0] >> A[1] >> S;
	int pre = -1;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == '.') {
			if (pre == -1) {
				if (A[0] < A[1])
					swap(A[0], A[1]);
				if (A[0])
					--A[0], ++ans, pre = 0;
			}
			else {
				pre = !pre;
				if (A[pre])
					--A[pre], ++ans;
			}
		}
		else
			pre = -1;
	}

	cout << ans << endl;
	return 0;
}