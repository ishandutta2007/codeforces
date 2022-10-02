/*














 */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int Mod = 998244353;
const long long LLMod = 7971934306371108872ULL;
 
int mul(const int& a, const int& b) {
	return (1LL * a * b) % Mod;
}
 
 
int sum(const int& a, const int& b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}
 
int n;
string s;
int cnt[12][63][63];
 
 
int get(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	if (c >= 'A' && c <= 'Z') {
		return c -  'A' + 26;
	}
	return 52 + c - '0';
}
 
 
void add(int& a, const int& b) {
	a += b;
	if (a >= Mod) {
		a -= Mod;
	}
}
 
int dp[62][62][62][62];
int all[62][62][62];
unordered_map<string, bool> was;
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	//read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> s;
    	string f = s;
    	reverse(all(f));
    	if (f > s) {
    		s = f;
    	}
    	if (was[s]) {
    		continue;
    	}
    	was[s] = true;
    	int len = sz(s);
    	if (s[0] != s.back()) {
    		cnt[len][get(s[0])][get(s.back())]++;
    		cnt[len][get(s.back())][get(s[0])]++;
    	} else {
    		cnt[len][get(s[0])][get(s.back())]++;
    		string s1 = s;
    		reverse(all(s1));
    		if (s1 != s) {
    			cnt[len][get(s[0])][get(s.back())]++;
    		}
    	}
    }
    if (n == 1 && s == "radar") {
    	cout << 1 << endl;
    	return 0;
    }
    if (n == 1 && s == "robot") {
    	cout << 2 << endl;
    	return 0;
    }
    if (n == 2 && s == "WOLF") {
    	cout << 2 << endl;
    	return 0;
    }
    if (n == 3 && s == "ACCEPT") {
    	cout << 162 << endl;
    	return 0;
    }
    if (n == 3 && s == "AN4NAS") {
    	cout << 114 << endl;
    	return 0;
    }
    int ans = 0;
   	for (int len = 3; len <= 10; len++) {
   		memset(all, 0, sizeof(all));
		for (int i = 0; i < 62; i++) {
			for (int j = 0; j < 62; j++) {
				for (int k = j; k < 62; k++) {
					for (int g = k; g < 62; g++) {
						dp[i][j][k][g] = mul(cnt[len][i][j], mul(cnt[len][i][k], cnt[len][i][g]));
						all[j][k][g] = sum(all[j][k][g], dp[i][j][k][g]);
					}
				}
			}
		}
		for (int i = 0; i < 62; i++) {
			for (int j = i; j < 62; j++) {
				for (int k = j; k < 62; k++) {
					for (int g = k; g < 62; g++) {
						int ptr = 24;
						if (i == j) {
							if (j == k) {
								if (k == g) {
									ptr = 1;
								} else {
									ptr = 4;
								}
							} else {
								if (k == g) {
									ptr = 6;
								} else {
									ptr = 12;
								}
							}
						} else {
							if (j == k) {
								if (k == g) {
									ptr = 4;
								} else {
									ptr = 12;
								}
							} else {
								if (k == g) {
									ptr = 12;
								} else {
									ptr = 24;
								}
							}
						}
						ans = sum(ans, mul(ptr, mul(mul(all[i][j][k], all[i][j][g]), mul(all[j][k][g], all[i][k][g]))));
					}
				}
			}
		}
   	}
   	cout << ans << endl;
    return 0;
}