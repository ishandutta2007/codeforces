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
const int MAXN = 100228;




int n;
vector<int> g[MAXN];
int who[MAXN];
int cur[MAXN];
bool alive[MAXN];
int cnt[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 0; i < n; i++) {
		who[i] = i;
		cur[i] = -1;
	}
	queue<int> q;
	for (int i = 0; i < n; i++) {
		alive[i] = true;
		cnt[i] = sz(g[i]);
		if (sz(g[i]) == 1) {
			q.push(i);
		}        
	}
	int ans = 0;
	while (!q.empty()) {
		int x = q.front();
		//cout << x << endl;
		q.pop();
		alive[x] = false;
		for (auto h: g[x]) {
			if (alive[h]) {
				cnt[h]--;
				if (cnt[h] == 1) {
					q.push(h);
				}
			}
		}
		if (who[x] != x) {
			continue;
		}
		bool was = false;
		for (auto h: g[x]) {
			if (alive[h]) {
				swap(who[h], who[x]);
				cur[who[x]] = x;
				cur[who[h]] = h;
				ans += 2;
				was = true;
				break;
			}
		}
		if (!was) {
			for (auto h: g[x]) {
				swap(who[h], who[x]);
				cur[who[x]] = x;
				cur[who[h]] = h;
				ans += 2;
				break;
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		cout << cur[i] + 1 << ' ' ;
	}
	cout << '\n';
}