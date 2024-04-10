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



int n, k;
string s;
vector<int> kek[MAXN];


void solve() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < k; i++) {
        kek[i].clear();
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            kek[i % k].pb(s[i] - '0');
        }
    }    
    int c = 0;
    int bal = 0;
    for (int i = 0; i < k; i++) {
        if (kek[i].empty()) {
            c++;
            continue;
        }
        sort(all(kek[i]));
        kek[i].resize(distance(kek[i].begin(), unique(all(kek[i]))));
        if (sz(kek[i]) > 1) {
            cout << "NO\n";
            return;
        }
        if (kek[i][0] == 0) {
            bal++;
        } else {
            bal--;
        }
    }
    if (abs(bal) > c) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}