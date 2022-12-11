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
	string s;
	cin >> s;


	int len = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (char c : s) {
		if (c == 'A') {
			++cnt1;
		} else {
			if (cnt1 > 0) {
				cnt1--;
				len += 2;
			} else {
				++cnt2;
			}
		}
	}

	len += cnt2 - (cnt2 % 2);

	cout << (int)s.size() - len << "\n";
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