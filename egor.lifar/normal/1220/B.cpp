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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 1008;



int n;
int a[MAXN][MAXN];
int fk[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n;
    for (int i = 0; i < n; i++) {
        fk[i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (j > i) {
                fk[i] = __gcd(fk[i], a[i][j]);
            }
        }
    }
    int cur = fk[0];
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = a[i][j];
            ll val = 1LL * a[0][i] * a[0][j] / t;
            val = sqrt(val);
            cur = __gcd(cur, (int)val);
        }
    }
    int s = 2;
    vector<int> can;
    for (int i = 1; i <= (int)sqrt(cur); i++) {
        if (cur % i == 0) {
            can.pb(i);
            can.pb(cur / i);
        }
    }
    for (auto x: can) {
        vector<int> s;
        s.pb(x);
        bool bad = false;
        for (int i = 1; i < n; i++) {
            if (a[0][i] % x != 0) {
                bad = true;
                break;
            }
            s.pb(a[0][i] / x);
        }
        if (!bad) {
            for (int i = 0; i < n; i++) {
                if (fk[i] % s[i] != 0) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (a[i][j] / s[i] != s[j]) {
                            bad = true;
                            break;
                        }
                    }
                    if (bad) {
                        break;
                    }
                }
                if (!bad) {
                    for (int i = 0; i < n; i++) {
                        cout << s[i] << ' ';
                    }
                    cout << '\n';
                    exit(0);
                }
            }
        }
    }
    return 0; 
}