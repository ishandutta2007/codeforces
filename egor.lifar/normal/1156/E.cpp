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
const int MAXN = 200228;


int n;
int p[MAXN];
int l[MAXN], r[MAXN];
int where[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 //read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> p[i];
 		where[p[i]] = i;
 	}
 	vector<int> st;
	for (int i = 0; i < n; i++) {
		while (!st.empty() && p[st.back()] < p[i]) {
			st.pop_back();
		}
		l[i] = (st.empty() ? 0: st.back() + 1);
		st.pb(i);
	} 	
	st.clear();
	for (int i = n - 1; i >= 0; i--) {
		while (!st.empty() && p[st.back()] < p[i]) {
			st.pop_back();
		}
		r[i] = (st.empty() ? n - 1: st.back() - 1);
		st.pb(i);
	} 
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int f = where[i];
		//cout << l[f] << ' ' << r[f] << endl;
		if (f - l[f] < r[f] - f) {
			for (int j = l[f]; j < f; j++) {
				if (where[i - p[j]] >= f + 1 && where[i - p[j]] <= r[f]) {
					ans++;
				}
			}
		} else {
			for (int j = f + 1; j <= r[f]; j++) {

				if (where[i - p[j]] >= l[f] && where[i - p[j]] < f) {
					ans++;
				}
			}	
		}
	}
	cout << ans << '\n';
	return 0; 	
}