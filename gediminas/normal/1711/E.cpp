
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "../includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

const long long mod = 998244353;
#define MOD(x) ((x)%mod)

/*input
101
*//*output
12
*/
/*input
1110
*//*output
780
*/
/*input
11011111101010010
*//*output
141427753
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	long long din[n + 1][8][8] = {};
	din[0][7][0] = 1;

	const int different[] = {0, 1, 2, 4, 4, 2, 1, 0};
	// 000 001 010 011 100 101 110 111

	for (int i = 0; i < n; ++i) {
		for (int waseqmax = 0; waseqmax < 8; ++waseqmax) {
			for (int bitsnow = 0; bitsnow < 8; ++bitsnow) {
				if (s[i] == '0' and (waseqmax & bitsnow)) {
					continue;
				}

				int iseqmax = waseqmax & ~bitsnow;

				for (int lessnow = 0; lessnow < 8; ++lessnow) {
					int lessnxt = lessnow | different[bitsnow];
					din[i + 1][iseqmax][lessnxt] += din[i][waseqmax][lessnow];
					din[i + 1][iseqmax][lessnxt] %= mod;
				}
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < 8; ++i) {
		ans += din[n][i][7];
	}

	ans %= mod;
	cout << ans;
}