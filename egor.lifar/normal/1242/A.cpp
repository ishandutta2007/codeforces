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





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  //  read(FILENAME);
    ll n;
    cin >> n;
    ll a = 2;
    vector<ll> st;
    while (a * a <= n) {
        if (n % a == 0) {
            while (n % a == 0) {
                n /= a;
            }
            st.pb(a);
        }
        a++;
    }
    if (n != 1) {
        st.pb(n);
    }
    if (sz(st) == 1) {
        cout << st[0] << '\n';
    } else {
        cout << 1 << '\n';
    }
    return 0;
}