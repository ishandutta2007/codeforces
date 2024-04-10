#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;
string s;

void solve() {
	cin >> n >> k >> s;
	k = min(k, n);
	int cnt = 0;

	vector<int> len;

	char last = 'L';
	int na = 0;
	int le = 0;
	int za = 0;
	int fr = 1;
	for (char c : s) {
		if (c == 'W') {
			if (last == 'L') ++na;
			++cnt;
			if (fr) {
				za = le;
				fr = 0;
			} else {
				if (le > 0) len.pb(le);
			}
			le = 0;
		} else {
			++le;
		}
		last = c;
	}
	le += za;

	if (cnt == 0) {
		if (k == 0) {
			cout << "0\n";
		} else {
			cout << 1 + (k - 1) * 2 << "\n";
		}
		return;
	}

	sort(all(len));

	for (int x : len) {
		if (x <= k) {
			k -= x;
			na--;
			cnt += x;
		} else {
			cnt += k;
			k = 0;
			break;
		}
	}

	while (le > 0 && k > 0) {
		--le;
		--k;
		++cnt;
	}


	cout << 2 * cnt - na << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solve() ;
	}

}