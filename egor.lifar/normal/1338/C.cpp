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



void solve() {
    ll n;
    cin >> n;
    n--;
    ll id = n / 3;
    ll pos;
    int it = 0;
    for (ll i = 1; ; i *= 4) {
        it++;
        if (i > id) {
            pos = i;
            break;
        }
        id -= i;
    }
    ll a = pos + id;
    ll b = pos * 2;
    ll g[4] = {0, 2, 3, 1};
    for (int i = 0; i < it - 1; i++) {
        //0 2 3 1 
        pos /= 4;
        ll val = id / pos;
        b += pos * g[val];
        id %= pos;
    }
    if (n % 3 == 0) {
        cout << a;
    } else if (n % 3 == 1) {
        cout << b;
    } else {
        cout << (a ^ b);
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    // set<int> s;
    // for (int i = 1; i <= 17; i++) {
    //     if (s.find(i) != s.end()) {
    //         continue;
    //     }
    //     for (int j = i + 1; j <= 10000; j++) {
    //         if (s.find(j) == s.end()) {
    //             int k = i ^ j;
    //             if (s.find(k) == s.end()) {
    //                 cout << i << '\n';
    //                 cout << j << '\n';
    //                 cout << k << '\n';
    //                 s.insert(i);
    //                 s.insert(j);
    //                 s.insert(k);
    //                 break;
    //             }
    //         }
    //     }
    // }
    // exit(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}