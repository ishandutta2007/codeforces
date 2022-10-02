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


int n, k;
string s;


void solve() {
    cin >> n >> k;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < sz(s); i++) {
        cnt[s[i] - 'a']++;
    }
    string ans;
    string opt;
    for (int i = 0; i < 26; i++) {
        while (cnt[i] >= k && ans.empty()) {
            ans += char(i + 'a');
            cnt[i] -= k;
        }
        if (!ans.empty()) {
            string t;
            for (int j = i; j < 26; j++) {
                for (int tt = 0; tt < cnt[j]; tt++) {
                    t += char(j + 'a');
                }
            }
            string s = ans + t;
            if (opt.empty() || opt > s) {
                opt = s;
            }
        }
        while (cnt[i] >= k) {
            ans += char(i + 'a');
            cnt[i] -= k;
        }
        if (!ans.empty()) {
            string t;
            for (int j = i; j < 26; j++) {
                for (int tt = 0; tt < cnt[j]; tt++) {
                    t += char(j + 'a');
                }
            }
            string s = ans + t;
            if (opt.empty() || opt > s) {
                opt = s;
            }
        }
        if (cnt[i]) {
            char last;
            for (int j = i; j < 26; j++) {
                if (k > cnt[j]) {
                    k -= cnt[j];
                    if (cnt[j]) {
                        last = char(j + 'a');
                    }
                } else {
                    last = char(j + 'a');
                    break;
                }
            }
            ans += last;
            if (opt.empty() || opt > ans) {
                opt = ans;
            }
            break;
        }
    }
    cout << opt << '\n';
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