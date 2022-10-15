#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1013
int N;
LL X;
LL A[MAXN];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c >> A[i];
		if (c == '-') {
			// cout << X << ' ' << ans << endl;
			if (X >= A[i]) {
				X -= A[i];
			}
			else {
				ans++;
			}
		}
		else {
			X += A[i];
		}
	}



	cout << X << ' ' << ans << endl;
	return 0;
}