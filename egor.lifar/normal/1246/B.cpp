
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
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;
const ll INF = 10000000000LL;


int n, k;
ll a[MAXN];
int cnt[MAXN];
int kek[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 0; i < n; i++) {
        int f = 2;
        int g1 = 1;
        int g = 1;
        while (f * f <= a[i]) {
            if (a[i] % f == 0) {
                int cnt = 0;
                while (a[i] % f == 0) {
                    cnt++;
                    a[i] /= f;
                }
                if (cnt % k != 0) {
                    for (int t = 0; t < cnt % k; t++) {
                        g *= f;
                    }
                    if (g1) {
                        for (int t = 0; t < k - cnt % k; t++) {
                            if (g1 > 100000 / f) {
                                g1 = 0;
                                break;
                            }
                            g1 *= f;
                        }
                    }
                }
            }
            f++;
        }
        if (a[i] != 1) {
            g *= a[i];
            if (g1) {
                for (int t = 0; t < k - 1; t++) {
                    if (g1 > 100000 / a[i]) {
                        g1 = 0;
                        break;
                    }
                    g1 *= a[i];
                }
            }
        }
       //cout << kek[g1] << ' ';
        res += kek[g1];
        kek[g]++;
    }
   // cout << endl;
    cout << res << '\n';
	return 0;
}