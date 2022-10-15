#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int T;
int N, A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N >> A >> B;
		int ma = 0, mb = 0;
		while (A--) { int a; cin >> a; ma = max(ma, a); }
		while (B--) { int a; cin >> a; mb = max(mb, a); }
		cout << ((ma > mb) ? "YES\n" : "NO\n");
	}

	cout.flush();
	return 0;
}