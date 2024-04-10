#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	unordered_set<char> a;
	for (int i = 0; i < 26; i++) {
		a.insert('a'+i);
	}

	int n;
	cin >> n;

	char c;
	string s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> c >> s;
		if (a.size() == 1) {
			if (c == '!')
				ans++;
			else if (c == '?' && !a.count(s[0]))
				ans++;
			continue;
		}

		if (c == '!') {
			unordered_set<char> temp;
			for (char j : s) {
				temp.insert(j);
			}
			for (auto it = a.begin(); it != a.end(); ) {
				if (temp.count(*it))
					it++;
				else
					it = a.erase(it);
			}
		}
		else if (c == '.') {
			for (char j : s) {
				a.erase(j);
			}
		}
		else if (c == '?') {
			a.erase(s[0]);
		}
	}

	cout << ans << nl;

	return 0;
}