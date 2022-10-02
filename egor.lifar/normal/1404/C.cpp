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
const int MAXN = 300228;
 
 
int n, q;
int a[MAXN];
int f[MAXN];


void inc(int pos) {
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        f[pos]++;
    }
  
}
 
 
int getr(int pos) {
    int ans = 0;
    for (; pos <= n; pos |= (pos + 1)) {
        ans += f[pos];
    }
    return ans;
}


int val[MAXN];
int ans[MAXN];
vector<pair<int, int> > z[MAXN];


int main() {
  	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            val[i] = i - a[i];
        } else {
            val[i] = n + 1;
        }
    }
    for (int it = 0; it < q; it++) {
        int x, y;
        cin >> x >> y;
        int l = x;
        int r = n - y - 1;
        z[r].pb(mp(l, it));
    }
    for (int i = 0; i < n; i++) {
        int l = -1;
        int r = i + 1;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
        //    cout << l << ' ' << r << endl; 
           // cout << getr(mid) << endl;
            if (val[i] <= getr(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        inc(l);
      // cout << l << endl;
        for (auto x: z[i]) {
            ans[x.second] = getr(x.first);
        }
    }
    for (int it = 0; it < q; it++) {
    	cout << ans[it] << '\n';
    }
   	return 0;
}