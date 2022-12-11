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

const int mod = 1e9 + 7;

string s;
int dp[1000007][2];
int ri[1000007];

void add(int& a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int save[1000007];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int cc = 0;

	for (int i = (int)s.size() - 1;i >= 0; --i) {
		if (s[i] == '1') {
			break;
		} else ++cc;
	}


	// dp[(int)s.size() - 1][s.back() - '0'] = 1;

	//vector<pair<int, int>> kek;
	
	/*if (s.back() == '0') {
		ri[(int)s.size() - 1] = 1;
		kek.pb({1, (int)s.size() - 1});
	}*/

	int opt = 0;
	int tot = 0;

	for (int i = (int)s.size() - 1; i >= 0; --i) {
		if (s[i] == '1') {
			add(opt, dp[i + 1][0]);
			add(opt, 1);
		}

		if (s[i] == '0') {
			ri[i] = ri[i + 1] + 1;
			//kek.pb({ri[i], i});
		}

		for (int t = 1; t >= 0; --t) {
			if (t == 1) {
				/*for (int j = i; j < s.size(); ++j) {
					if ((s[j] - '0') == t) {
						add(dp[i][t], dp[j + 1][0] + 1);
					}
				}*/
				dp[i][1] = opt;
			} else {
				
				/*for (int len = 1; ; ++len) {
					int ok = 0;
					for (int p = (int)kek.size() - 1; p >= 0; --p) {
						if (kek[p].x >= len) {
							assert(s[kek[p].y + len - 1] == '0');
							// cout << "===" << dp[kek[p].y][1] << ' ' << dp[kek[p].y + len][1] << ' ' << kek[p].y + len << endl;
							// assert(dp[kek[p].y + len - 1][1] == dp[kek[p].y + len][1]);
							add(dp[i][t], dp[kek[p].y][1]);
							// if (cc >= len) add(dp[i][t], 1);
							ok = 1;
							break;
						}
					}
					if (!ok) break;
				}*/
				if (s[i] == '0') {
					//cout << "===" << i << ' ' << ri[i] << ' ' << dp[i][1] << endl;
					tot -= save[ri[i]];
					if (tot < 0) tot += mod;
					add(tot, dp[i][1]);
					save[ri[i]] = dp[i][1];
				}
				add(dp[i][0], tot);
				add(dp[i][0], min(cc, (int)s.size() - i));
			}
			//cout << dp[i][t] << ' ' << i << ' ' << t << endl;
		}
	}

	int ans = 0;
	for (int len = 0; len <= ri[0]; ++len) add(ans, dp[0][1]);

	if (cc == s.size()) ans = cc;

	cout << ans;
}