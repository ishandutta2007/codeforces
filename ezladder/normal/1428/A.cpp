#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2) {
		cout << abs(y1 - y2) << "\n";
	} else if (y1 == y2) {
		cout << abs(x1 - x2) << "\n";
	} else {
		cout << abs(y1 - y2) + abs(x1 - x2) + 2 << "\n";
	}
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}