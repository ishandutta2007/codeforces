#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
4
1
a
a
3
rll
rrr
3
caa
aca
5
ababa
aabba

*/
/*input
1
5
ddcba
bbcde
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
		long long n;
		string s, t;
		cin >> n >> s >> t;
		{
			string b = s;
			sort(b.begin(), b.end());

			if (b >= t) {
				cout << "-1\n";
				continue;
			}
		}
		deque<int> nxt[30];

		for (int i = 0; i < n; ++i) {
			nxt[s[i] - 'a'].push_back(i);
		}

		long long ans = n * (n + 1);
		long long suk = 0;
		int curi = 0;

		ordered_set sss;

		for (int i = 0; i < n; ++i) {
			while (s[curi] == '.') {
				curi++;
			}

			while (sss.size() and *sss.begin() <= curi) {
				sss.erase(sss.begin());
			}

			if (s[curi] < t[i]) {
				ans = min(suk, ans);
				break;
			}

			{
				int aa = 100000000;
				long long aaj = 0;
				bool rad = false;

				for (int j = 0; j < t[i] - 'a'; ++j) {
					if (nxt[j].size() and nxt[j][0] < aa) {
						aaj = j;
						aa = nxt[j][0];
						rad = true;
					}
				}

				if (rad) {
					ans = min(ans, (long long)(aa - curi - sss.order_of_key(aa)) + suk);
				}
			}

			debug(t[i] - 'a', nxt[t[i] - 'a']);

			if (nxt[t[i] - 'a'].empty()) {
				break;
			}

			int tt = nxt[t[i] - 'a'][0];
			nxt[t[i] - 'a'].pop_front();
			suk += tt - curi - sss.order_of_key(tt);
			s[tt] = '.';
			sss.insert(tt);

			debug(s, suk, ans);
		}

		debug(ans);
		cout << ans << "\n";
	}

}