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
const string FILENAME = "input";
const int MAXN = 200228;
const int MAGIC = 999;



int shift[10];


vector<int> mymove(vector<int> v) {
	cout << "next";
	for (auto x: v) {
		shift[x]++;
		cout << ' ' << x;
	}
	cout << endl;
	int k;
	cin >> k;
	vector<int> id;
	id.resize(10);
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		for (auto x: s) {
			id[x - '0'] = i;
		}
	}
	return id;
} 


int c;
int kek;



int  main() {
	ios_base::sync_with_stdio(false);
	//read(FILENAME);
	int fs = 0;	
	while (true) {
		mymove({1, 0});
		fs++;
		vector<int> res = mymove({1});
		if (res[0] == res[1]) {
			break;
		}
	}
	while (true) {
		c++;
		vector<int> cur = mymove({1, 2});
		if (cur[0] == cur[1]) {
			break;
		}
	}
	int t = 0;
	while (true) {
		vector<int> cur = mymove({2, 3, 4, 5, 6, 7, 8, 9});
		t++;
		if (cur[2] == cur[3]) {
			break;
		}
	}
	int f = (fs - t) % c;
	for (int t = 0; t < (c - f) % c; t++) {
		mymove({0, 1});
	}
	cout << "done" << endl;
 	return 0; 
}