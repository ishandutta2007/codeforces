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
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 200228;


int n;
string s;
vector<int> f[26];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	cin >> s;
	for (int i = 0; i < sz(s); i++) {
		f[s[i] - 'a'].pb(i);
	}
	int m;
	cin >> m;
	for (int j = 0; j < m; j++) {
		string k;
		cin >> k;
		int cnts[26];
		memset(cnts, 0, sizeof(cnts));
		for (auto x: k) {
			cnts[x - 'a']++;
		}
		int pos = 0;
		for (int k = 0; k < 26; k++) {
			if (!cnts[k]) continue;
			chkmax(pos, f[k][cnts[k] - 1]);
		}
		cout << pos + 1 << '\n';
	}
	return 0; 		
}