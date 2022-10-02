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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
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
const int MAXN = 3228;






string t, o, r;
char ans[MAXN][2];
int cnt[26];
int cnt1[26];
int cnt2[26];
vector<int> can[26][2];
vector<int> where[26];


void solve() {
    cin >> t >> o >> r;
    for (int i = 0; i < MAXN; i++) {
        ans[i][0] = 'Z';
        ans[i][1] = 'Z';
    }
    sort(all(t));
    for (int i = 0; i < sz(t); i++) {
        ans[i][0] = t[i]; 
        where[t[i] - 'A'].pb(i);
    }
    for (int i = 0; i < sz(t); i++) {
        cnt[t[i] - 'A']++;
    }
    for (auto x: o) {
        cnt1[x - 'A']++;
    }
    for (auto y: r) {
        cnt2[y - 'A']++;
    }
    int have = sz(t);
    int ld = min(sz(o), sz(r));
    for (char c = 0; c < 26; c++) {
        int opt = -1;
        int pl = 0;
        int pl1 = 0;
        for (int len = 0; len <= min(cnt[c], cnt1[c]); len++) {
            for (int len1 = 0; len1 <= min(cnt[c] - len, cnt2[c]); len1++) {
                int val = len + len1 + min(cnt1[c] - len, cnt2[c] - len1);
                if (val > opt && len + len1 <= ld) {
                    opt = val;
                    pl = len;
                    pl1 = len1;
                }
            }
        }
        ld -= pl + pl1;
        cnt[c] -= pl + pl1;
        cnt1[c] -= pl;
        cnt2[c] -= pl1;
        have -= pl + pl1;
        for (int i = 0; i < pl1; i++) {
            can[c][0].pb(where[c].back());
            where[c].pop_back();
        }
        for (int i = 0; i < pl; i++) {
            can[c][1].pb(where[c].back());

            where[c].pop_back();
        }
    }
    for (char c = 0; c < 26; c++) {
        while (cnt1[c] && cnt2[c] && have) {
            cnt1[c]--;
            cnt2[c]--;
            have--;
            for (char c1 = 0; c1 < 26; c1++) {
                if (cnt[c1]) {
                    cnt[c1]--;
                    int d = where[c1].back();
                    where[c1].pop_back();
                    ans[d][1] = char(c + 'A');
                    break;
                }
            }
        }
    }
    vector<char> rem, ram;
    for (char c = 0; c < 26; c++) {
        for (int i = 0; i < cnt1[c]; i++) {
            rem.pb(char('A' + c));
        }
        for (int i = 0; i < cnt2[c]; i++) {
            ram.pb(char('A' + c));
        }
    }
    for (char c = 0; c < 26; c++) {
        while (!can[c][0].empty() && !rem.empty()) {
            auto d = rem.back();
            rem.pop_back();
            ans[can[c][0].back()][1] = d;
            can[c][0].pop_back();
        }
        while (!can[c][1].empty() && !ram.empty()) {
            auto d = ram.back();
            ram.pop_back();
            ans[can[c][1].back()][1] = d;
            can[c][1].pop_back();
        }
    }
    for (char c = 0; c < 26; c++) {
        while (!where[c].empty() && sz(rem) + sz(ram) > 0) {
            int f = where[c].back();
            where[c].pop_back();
            if (sz(rem) > sz(ram)) {
                auto d = rem.back();
                rem.pop_back();
                ans[f][1] = d;
            } else {
                auto d = ram.back();
                ram.pop_back();
                ans[f][1] = d;
            }
        }
    }
    int tot = sz(t);
    for (int i = 0; i < max(sz(rem), sz(ram)); i++) {
        ans[tot + i][0] = (i < sz(rem) ? rem[i]: 'Z');
        ans[tot + i][1] = (i < sz(ram) ? ram[i]: 'Z');
    }

    tot += max(sz(rem), sz(ram));
    cout << tot << '\n';
    for (int i = 0; i < tot; i++) {
        cout << ans[i][0] << ans[i][1] << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}