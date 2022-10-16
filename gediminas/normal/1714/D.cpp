#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
6
bababa
2
ba
aba
caba
2
bac
acab
abacabaca
3
aba
bac
aca
baca
3
a
c
b
codeforces
4
def
code
efo
forces
aaaabbbbcccceeee
4
eeee
cccc
aaaa
bbbb
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		string a;
		int m;
		cin >> a >> m;
		int n = a.size();

		string p[m];

		for (int i = 0; i < m; ++i) {
			cin >> p[i];
		}

		vector<int> din(n + 1, 10000000);
		vector<int> ejim(n + 1, -1);
		vector<int> prev(n + 1, -1);
		din[0] = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a.substr(i, p[j].size()) == p[j]) {
					for (int k = 1; k <= p[j].size(); ++k) {
						if (din[i] + 1 < din[i + k]) {
							din[i + k] = din[i] + 1;
							prev[i + k] = i;
							ejim[i + k] = j;
						}
					}
				}
			}
		}

		debug(din[n]);

		if (din[n] > n) {
			cout << -1 << "\n";
			continue;
		}

		cout << din[n] << "\n";
		int t = n;

		while (t > 0) {
			cout << ejim[t] + 1 << " " << prev[t] + 1 << "\n";
			t = prev[t];
		}
	}

}