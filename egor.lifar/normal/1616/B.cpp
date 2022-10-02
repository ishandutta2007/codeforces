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



int n;
string s;


void solve() {
    cin >> n;
    cin >> s;
    string ans = s;
    for (int i = n - 1; i >= 0; i--) {
        ans += s[i];
    }
    string f;
    f += s[0];
    f += f;
    chkmin(ans, f);
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] < s[i + 1]) {
            string ans1;
            for (int j = 0; j <= i; j++) {
                ans1 += s[j];
            }   
            for (int j = i; j >= 0; j--) {
                ans1 += s[j];
            }
            chkmin(ans, ans1);
            break;
        }
        if (i + 1 < n && s[i] > s[i + 1]) {
            string ans1;
            for (int j = 0; j <= i + 1; j++) {
                ans1 += s[j];
            }   
            for (int j = i + 1; j >= 0; j--) {
                ans1 += s[j];
            }
            chkmin(ans, ans1);
        }
        if (i + 1 < n && s[i] > s[i + 1]) {
            string ans1;
            for (int j = 0; j <= i; j++) {
                ans1 += s[j];
            }   
            for (int j = i; j >= 0; j--) {
                ans1 += s[j];
            }
            chkmin(ans, ans1);
        }
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}