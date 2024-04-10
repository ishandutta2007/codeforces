/*
KAMUI!
 
 

 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;


int n;
int a[MAXN];
vector<int> cnt[5000002];
pair<short, short> sums[10000002][3];
char uk[10000002];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
 	cin >> n;
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 		cnt[a[i]].pb(i);
 	}
 	for (int i = 1; i <= 5000000; i++) {
 		if (sz(cnt[i]) >= 4) {
 			cout << "YES\n";
 			for (int j = 0; j < 4; j++) {
 				cout << cnt[i][j] + 1 << ' ';
 			}
 			cout << '\n';
 			return 0;
 		}
 	}
 	vector<int> t;
 	for (int i = 1; i <= 5000000; i++) {
 		if (sz(cnt[i]) >= 2) {
 			t.pb(i);
 			if (sz(t) >= 2) {
 				break;
 			}
 		}	
 	}
 	if (sz(t) >= 2) {
		cout << "YES\n";
		cout << cnt[t[0]][0] + 1 << ' ' << cnt[t[1]][0] + 1 << ' ' << cnt[t[0]][1] + 1 << ' ' << cnt[t[1]][1] + 1 << '\n';
		return 0;
	}
 	for (int i = 0; i < min(n, 4000); i++) {
 		for (int j = i + 1; j < min(n, 4000); j++) {
 			int val = a[i] + a[j];
 			if (uk[val] <= 2) {
 				sums[val][uk[val]] = mp(i + 1, j + 1);
 				uk[val]++;
 			}
 		}
 	}
 	for (int i = 1; i <= 10000000; i++) {
 		for (int f = 0; f < uk[i]; f++) {
 			for (int f1 = f + 1; f1 < uk[i]; f1++) {
 				int a = sums[i][f].first;
 				int b = sums[i][f].second;
 				int c = sums[i][f1].first;
 				int d = sums[i][f1].second;
 				if (a != c && a != d && b != c && b != d) {
 					cout << "YES\n";
 					cout << a << ' ' << b << ' ' << c << ' '  << d << '\n';
 					return 0;
 				}
 			}
 		}
 	}
 	cout << "NO\n";
}