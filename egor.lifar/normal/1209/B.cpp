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
const int MAXN = 2222;

int n;
string s;
int a[MAXN], b[MAXN];
int c[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME); 
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = s[i] - '0';
    }
    int res = 0;
    for (int it = 0; it < 1000; it++) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (it >= b[i] && (it - b[i]) % a[i] == 0) {
                c[i] ^= 1;
            }
            cur += c[i];
        }
        chkmax(res, cur);
    }
    cout << res << '\n';
    return 0; 
}