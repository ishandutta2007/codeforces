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
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 1000228;


int n, m;
string s[MAXN];
vector<int> d[MAXN];
vector<int> res[MAXN];
vector<bool> can[MAXN];
vector<int> add[MAXN];

int get(int i, int j, int i1, int j1) {
    return d[i1][j1] - (i ? d[i - 1][j1]: 0) - (j ? d[i1][j - 1]: 0) + (i && j ? d[i - 1][j - 1]: 0);
}


bool check(int x) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            can[i][j] = false;
            add[i][j] = 0;
        }
    }
    for (int i = x; i < n - x; i++) {
        for (int j = x; j < m - x; j++) {
            can[i][j] = get(i - x, j - x, i + x, j + x) == ((2 * x + 1) * (2 * x + 1));
            if (can[i][j]) {
                add[i - x][j - x]++;
                if (j + x + 1 < m) {
                   add[i - x][j + x + 1]--;
                }
                if (i + x + 1 < n) {
                    add[i + x + 1][j - x]--;
                } 
                if (i + x + 1 < n && j + x + 1 < m) {
                    add[i + x + 1][j + x + 1]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = add[i][j];
            if (i) {
                res[i][j] += res[i - 1][j];
            }
            if (j) {
                res[i][j] += res[i][j - 1];
            }
            if (i && j) {
                res[i][j] -= res[i - 1][j - 1];
            }
            if (s[i][j] == 'X' && res[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //	read(FILENAME);
  	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        d[i].resize(m);
        can[i].resize(m);
        add[i].resize(m);
        res[i].resize(m);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') {
                d[i][j] = 1;
            } else {
                d[i][j] = 0;
            }
            if (i) {
                d[i][j] += d[i - 1][j];
            }
            if (j) {
                d[i][j] += d[i][j - 1];
            }
            if (i && j) {
                d[i][j] -= d[i - 1][j - 1];
            }
        }
    }
    int l = 0;
    int r = min(n, m);
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    check(l);
    cout << l << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (can[i][j]) {
                cout << 'X'; 
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}