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
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int MAXN = 1505;


int n, q;
int c[MAXN][MAXN];
ll f[MAXN];
vector<pair<int, int> > t[MAXN];
int cnt[MAXN * MAXN];
int cntd = 0;
cc_hash_table<int, int> adds[MAXN];


void add(int i) {
	for (int f = 0; f < sz(t[i]); f++) {
		adds[t[i][f].second][t[i][f].first]++;
	}
}


void del(int i) {
	for (int f = 0; f < sz(t[i]); f++) {
		adds[t[i][f].second][t[i][f].first]--;
		if (adds[t[i][f].second][t[i][f].first] == 0) {
			adds[t[i][f].second].erase(t[i][f].first);
		}
	}
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	} 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<pair<int, int> > nf;
			nf.pb(mp(c[i][j], i));
			for (auto x: t[j]) {
				if (x.first == c[i][j]) {

				} else {
					nf.pb(x);
				}
			}
			t[j] = nf;
			if (sz(t[j]) > q + 1) {
				t[j].pop_back();
			}
		}
		for (int f = 0; f <= n; f++) {
			adds[f].clear();
		}
		int len = 0;
		for (int j = 0; j <= n; j++) {
			if (j) {
				del(j - 1);
				for (int f = 0; f < sz(t[j - 1]); f++) {
					if (t[j - 1][f].second <= i - len) {
						break;
					}
					cnt[t[j - 1][f].first]--;
					if (cnt[t[j - 1][f].first] == 0) {
						cntd--;
					}
				}
				for (auto x: adds[i - len + 1]) {
					if (x.second == 0) continue;
					cnt[x.first]-= x.second;
					if (cnt[x.first] == 0) {
						cntd--;
					}
				}
				len = max(0, len - 1);
			}
			if (j == n) {
				break;
			}
			if (len == 0) {
				len = 1;
				cnt[t[j][0].first]++;
				cntd++;
				add(j);
			}
			while (j + len < n && i >= len) {
				if (sz(adds[i - len]) > q) {
					break;
				}
				for (int f = 0; f < sz(t[j + len]); f++) {
					if (t[j + len][f].second <= i - len - 1) {
						break;
					}
					cnt[t[j + len][f].first]++;
					if (cnt[t[j + len][f].first] == 1) {
						cntd++;
					}
				}
				for (auto f: adds[i - len]) {
					if (f.second == 0) continue;
					if (cnt[f.first] == 0) {
						cntd++;
					}
					cnt[f.first]+= f.second;
				}
				if (cntd <= q) {
					//cout << i << ' ' << len + 1 << endl;
					add(j + len);
					len++;
				} else {
					for (auto f: adds[i - len]) {
						if (f.second == 0) continue;
						cnt[f.first]-= f.second;
						if (cnt[f.first] == 0) {
							cntd--;
						}
					}
					for (int f = 0; f < sz(t[j + len]); f++) {
						if (t[j + len][f].second <= i - len - 1) {
							break;
						}
						cnt[t[j + len][f].first]--;
						if (cnt[t[j + len][f].first] == 0) {
							cntd--;
						}
					}
					break;
				}
			}
			f[len]++;
		}
	}
	for (int i = n; i >= 1; i--) {
		f[i] += f[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		cout << f[i] << '\n';
	}
}