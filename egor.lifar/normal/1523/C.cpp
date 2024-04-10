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
const int Mod = 1000000007;


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


const int MAXN = 1005;


int n;
int a[MAXN];
string s[MAXN];
vector<int> last[MAXN];


void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++) {
        last[i].clear();
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            s[i] = (i == 0 ? "1": s[i - 1] + ".1");
            last[a[i]].pb(i);
        } else {
            int id = last[a[i] - 1].back();
            last[a[i] - 1].pop_back();
            for (int j = 0; j <= n; j++) {
                while (!last[j].empty() && last[j].back() >= id) {
                    last[j].pop_back();
                }
            }
            s[i] = s[id];
            while (!s[i].empty() && s[i].back() != '.') {
                s[i].pop_back();
            }
            int t = a[i];
            string f;
            while (t) {
                f += char('0' + t % 10);
                t /= 10;
            }
            reverse(all(f));
            s[i] += f;
            last[a[i]].pb(i);
        }
        cout << s[i] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}