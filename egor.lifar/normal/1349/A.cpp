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
const int MAXN = 200228;



int n;
int a[MAXN];
bool b[MAXN];
vector<pair<int, int> > k[MAXN];
int val[MAXN];
ll ans = 1;


void check(int x) {
    int mn1 = 1e9, mn2 = 1e9;
    for (int i = 0; i < n; i++) {
        int t = val[a[i]];
        if (mn1 > t) {
            mn2 = mn1;
            mn1 = t;
        } else if (mn2 > t) {
            mn2 = t;
        }
        if (mn2 == 0) {
            break;
        }
    }
    for (int j = 0; j < mn2; j++) {
        ans *= x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //	read(FILENAME);	
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < MAXN; i++) {
        if (!b[i]) {
            for (int j = i; j < MAXN; j += i) {
                b[j] = true;
                int j1 = j;
                int cnt = 0;
                while (j1 % i == 0) {
                    j1 /= i;
                    cnt++;
                }
                val[j] = cnt;
            }
            check(i);
            for (int j = i; j < MAXN; j += i) {
                val[j] = 0;
            }
        }
    }
    cout << ans << '\n';
}