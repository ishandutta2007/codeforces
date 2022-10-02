 /*
 



















 
 */
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
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
const string FILENAME = "input";
const int MAXN = 100228;


int n, q;
string s;
string t[3];
int last[MAXN][26];
int dp[255][255][255];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> q;
 	cin >> s;
 	for (int j = 0; j < 26; j++) {
 		last[n][j] = n;
 	}
 	for (int i = n - 1; i >= 0; i--) {
 		for (int j = 0; j < 26; j++) {
 			last[i][j] = last[i + 1][j];
 		}
 		last[i][s[i] - 'a'] = i;
 	}
 	for (int i = 0; i <= 250; i++) {
		for (int j = 0; j <= 250; j++) {
			for (int k = 0; k <= 250; k++) {
				dp[i][j][k] = 1e9;
			}
		}
	}
	dp[0][0][0] = 0;
 	for (int it = 0; it < q; it++) {
 		char ts;
 		cin >> ts;
 		if (ts == '+') {
 			int id;
 			cin >> id;
 			id--;
 			char c;
 			cin >> c;
 			t[id] += c;
 			int fi = 0;
 			int fj = 0;
 			int fk = 0;
 			if (id == 0) {
 				fi = sz(t[0]) - 1;
 				for (int i = 0; i <= sz(t[1]); i++) {
 					for (int k = 0; k <= sz(t[2]); k++) {
 						dp[sz(t[0])][i][k] = 1e9;
 					}
 				}
 			} else if (id == 1) {
 				fj = sz(t[1]) - 1;
 				for (int i = 0; i <= sz(t[0]); i++) {
 					for (int k = 0; k <= sz(t[2]); k++) {
 						dp[i][sz(t[1])][k] = 1e9;
 					}
 				}
 			} else {
 				for (int i = 0; i <= sz(t[0]); i++) {
 					for (int k = 0; k <= sz(t[1]); k++) {
 						dp[i][k][sz(t[2])] = 1e9;
 					}
 				}
 				fk = sz(t[2]) - 1;
 			}
	 		for (int i = fi; i <= sz(t[0]); i++) {
	 			for (int j = fj; j <= sz(t[1]); j++) {
	 				for (int k = fk; k <= sz(t[2]); k++) {
	 					if (dp[i][j][k] >= n) {
	 						continue;
	 					}
	 					if (i + 1 <= sz(t[0])) {
	 					int pos = dp[i][j][k];
	 					chkmin(dp[i + 1][j][k], last[pos][t[0][i] - 'a'] + 1); 
	 					}
	 					if (j + 1 <= sz(t[1])) {
	 					int pos = dp[i][j][k];
	 					chkmin(dp[i][j + 1][k], last[pos][t[1][j] - 'a'] + 1); 
	 					}
	 					if (k + 1 <= sz(t[2])) {
	 					int pos = dp[i][j][k];
	 					chkmin(dp[i][j][k + 1], last[pos][t[2][k] - 'a'] + 1); 
	 					}
	 				}
	 			}
	 		}
 		} else {
 			int id;
 			cin >> id;
 			id--;
 			t[id].pop_back();

 		}
 		//cout << t[0] << ' ' << t[1] << ' ' << t[2] << endl; 
 		
 		if (dp[sz(t[0])][sz(t[1])][sz(t[2])] <= n) {
 			cout << "YES\n"; 
 		} else {
 			cout << "NO\n";
 		}
 	}
	return 0; 	
}