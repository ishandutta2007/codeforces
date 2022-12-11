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
		string s1, s2;
		cin >> s1 >> s1 >> s2;
		bool ok = 1;
		for (int i = 0; i < s1.size(); ++i) if (s1[i] > s2[i]) ok = 0;
		if (!ok) {
			cout << "-1\n";
			continue;
		}
		int ans = 0;

		for (char c = 'a'; c <= 't'; ++c) {
			char mi = 'z';
			int f = 0;
			for (int i = 0; i < s1.size(); ++i) {
				if (s1[i] == c && s1[i] != s2[i]) {
					mi = min(mi, s2[i]);
					f = 1;
				}
			}
			if (f) {
				++ans;
				for (int i = 0; i < s1.size(); ++i) {
					if (s1[i] == c && s1[i] != s2[i]) {
						s1[i] = mi;
					}
				}
			}
		}

		cout << ans << "\n";
	}
}