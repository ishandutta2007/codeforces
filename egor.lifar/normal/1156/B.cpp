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


int t;
int cnt[26];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 //	read(FILENAME);
 	cin >> t;
 	for (int it = 0; it < t; it++) {
 		string s;
 		cin >> s;
 		memset(cnt, 0, sizeof(cnt));
 		for (auto x: s) {
 			cnt[x - 'a']++;
 		}
 		vector<int> st;
 		for (int i = 0; i < 26; i++) {
 			if (cnt[i]) {
 				st.pb(i);
 			}
 		}
 		//cout << sz(st) << endl;
 		if (sz(st) >= 5 || sz(st) == 1) {
 			vector<int> order;
 			for (int i = 0; i < sz(st); i++) {
 				if (i % 2 == 0) {
 					order.pb(st[i]);
 				}
 			}
 			for (int i = 0; i < sz(st); i++) {
 				if (i % 2 == 1) {
 					order.pb(st[i]);
 				}
 			}
 			string ss;
	 			for (auto x: order) {
	 				for (int j = 0; j < cnt[x]; j++) {
	 					ss += char(x + 'a');
	 				}
	 			}
	 			cout << ss << endl;
 			continue;
 		}
 		bool was = false;
 		do {
 			bool bad = false;
 			for (int i = 0; i< sz(st) - 1; i++) {
 				if (abs(st[i] - st[i + 1]) == 1) {
 					bad = true;
 				}
 			}
 			if (!bad) {
 				string ss;
	 			for (auto x: st) {
	 				for (int j = 0; j < cnt[x]; j++) {
	 					ss += char(x + 'a');
	 				}
	 			}
	 			cout << ss << endl;
	 			was = true;
	 			break;
 			}
 		} while (next_permutation(all(st)));
 		if (!was) {
 			cout << "No answer\n";
 			continue;
 		}
 	}
	return 0; 	
}