/*
  !










*/
#include <iostream>
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
const int MAXN = 2000001;


int n;
bool used[MAXN];
char c[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	set<int> st;
	for (int i = 0; i < MAXN; i++) {
		st.insert(i);
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int pos;
			cin >> pos;
			int l = pos - 1;
			int r = l + sz(s) - 1;
			while (!st.empty()) {
				auto it = st.lower_bound(l);
				if (it == st.end() || *it > r) {
					break;
				}
				int kek = *it;
				st.erase(kek);
				used[kek] = true;
				c[kek] = s[kek - l];
			}
		}
	}
	int border = 0;
	for (int i = MAXN - 1; i >= 0; i--) {
		if (used[i]) {
			border = i;
			break;
		}
	}
	for (int i = 0; i <= border; i++) {
		if (!c[i]) {
			c[i] = 'a';
		}
		cout << c[i];
	}
	cout << '\n';
	return 0;
}