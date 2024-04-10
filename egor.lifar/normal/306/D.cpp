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
const double Pi = acos(-1);




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 	//read(FILENAME);	
    int n;
    cin >> n;
    if (n < 5) {
        cout << "No solution\n";
        return 0;
    }
    double arg = 0, t = Pi * 2 / n;
    double l = 100;
    double x = -l, y = 0;
    for (int i = 1; i < n; i++) {
        x += cos(arg) * l;
        y += sin(arg) * l;
        arg += t;
        cout << fixed << x << ' ' << y << '\n';
        l += 0.002;
    }
    cout << fixed << x - y / tan(arg) << ' ' << 0 << '\n';
}