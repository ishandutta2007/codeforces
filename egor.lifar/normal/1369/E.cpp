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
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
int w[MAXN];
int a[MAXN], b[MAXN];
int need[MAXN];
bool ok[MAXN];
bool del[MAXN];
vector<int> who[MAXN];
vector<int> res;
queue<int> q;
bool good[MAXN];



void check(int x) {
	if (!good[x] && w[x] >= need[x]) {
		good[x] = true;
		q.push(x);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		need[a[i]]++;
		need[b[i]]++;
		who[a[i]].pb(i);
		who[b[i]].pb(i);
	} 
	for (int i = 0; i < n; i++) {
		if (w[i] >= need[i]) {
			q.push(i);
			good[i] = true;
		}
	}
	while (!q.empty()) {
		int as = q.front();
		q.pop();
		for (auto h: who[as]) {
			if (!del[h]) {
				//cout << h << endl;
				del[h] = true;
				res.pb(h);
				need[a[h]]--;
				need[b[h]]--;
				check(a[h]);
				check(b[h]);
			}
		}
	}
	reverse(all(res));
	if (sz(res) != m) {
		cout << "DEAD\n";
	} else {
		cout << "ALIVE\n";
		for (auto x: res) {
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;	 	
}