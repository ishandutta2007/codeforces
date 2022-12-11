#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string s, t;
		cin >> s >> s >> t;
		vector<int> ans;

		int pos1 = (int)s.size() - 1;
		int pos2 = 0;
		for (int i = (int)s.size() - 1, j = 0; i >= 0; --i, ++j) {
			int pos = pos1;
			if (j % 2 == 0) {
				pos = pos2;
			} else {
				pos = pos1;
			}

			// cout << s[pos] << ' ' << t[i] << endl;
			if (t[i] == s[pos]) {
				if (j % 2 == 0) {
					ans.pb(1);
				}
			} else {
				if (j % 2 == 1) {
					ans.pb(1);
				}
			}
			ans.pb(i + 1);

			if (j % 2 == 0) {
				++pos2;
			} else {
				--pos1;
			}
		}

		cout << ans.size() << " ";
		for (int x : ans) cout << x << ' ';
		cout << "\n";
	}
}