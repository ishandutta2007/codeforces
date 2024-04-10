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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define next next224
#define rank rank224
#define prev prev224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
const string FILENAME = "input";
const int MAXN = 400228;


int n, I;
int a[MAXN];
map<int, int> cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    cin >> n >> I;
    I *= 8;
    I /= n;
    chkmin(I, 28);
    int cnts = (1 << I);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    vector<int> g;
    for (auto x: cnt) {
    	g.pb(x.first);
    }
    if (cnts >= sz(g)) {
    	cout << 0 << endl;
    	return 0;
    }
    int sum = 0;
    for (int i = cnts; i < sz(g); i++) {
    	sum += cnt[g[i]];
    }
    int res = 1e9;
    for (int i = 0; i <= sz(g) - cnts; i++) {
    	chkmin(res, sum);
    	if (i + cnts < sz(g)) {
    		sum -= cnt[g[i + cnts]];
    	}
    	sum += cnt[g[i]];
    }
    cout << res << endl;
    return 0;
}