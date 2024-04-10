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
const int Mod = 998244353;


int sum(int a, int b) {
	return (a + b >= Mod ? a + b - Mod: a + b);
}


int mul(int a, int b) {
	return ((ll)a * b) % Mod;
}


int powm(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int inv(int a) {
    return powm(a, Mod - 2);
}



const int MAXN = 300228;
const int MAXM = 1000228;

int n;
int a[MAXN];
vector<pair<int, int> > st[MAXM];
bool bad[MAXM];
int q;
vector<int> cur[MAXN];
map<vector<int>, int> z;


void solve() {
	z.clear();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cur[i].clear();
		for (auto x: st[a[i]]) {
			if (x.second & 1) {
				cur[i].pb(x.first);
			}
		}
	}	
	for (int i = 0; i < n; i++) {
		z[cur[i]]++;
	}
	int res = 0;
	for (auto x: z) {
		chkmax(res, x.second);
	}
	int res1 = 0;
	for (auto x: z) {
		if (x.first.empty() || x.second % 2 == 0) {
			res1 += x.second;
		}
	}
	chkmax(res1, res);
	cin >> q;
	for (int i = 0; i < q; i++) {
		ll w;
		cin >> w;
		if (w == 0) {
			cout << res << '\n';
		} else {
			cout << res1 << '\n';
		}
	}	
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    for (int i = 2; i <= 1000000; i++) {
    	if (bad[i]) {
    		continue;
    	}
    	for (int j = i; j <= 1000000; j+= i) {
    		bad[j] = true;
    		int j1 = j;
    		int cnt = 0;
    		while (j1 % i == 0) {
    			j1 /= i;
    			cnt++;
    		}
    		st[j].pb(mp(i, cnt));
    	}
    }
	int t;
	cin >> t;
	while (t--) {
		solve();
	}    
   	return 0;
}