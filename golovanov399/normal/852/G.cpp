#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

set<string> ans;

void get_res(string& s, int pos, unordered_map<string, int>& mapa) {
    if (pos == s.length()) {
        ans.insert(s);
        return;
    }
    if (s[pos] != '?') {
        return get_res(s, pos + 1, mapa);
    }
    for (char c = 'a'; c <= 'e'; ++c) {
        s[pos] = c;
        get_res(s, pos + 1, mapa);
    }
    char c = s[pos];
    s.erase(s.begin() + pos);
    get_res(s, pos, mapa);
    s.insert(s.begin() + pos, '?');
    return;
}

void solve(bool read) {
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mapa;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++mapa[s];
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        ans.clear();
        get_res(s, 0, mapa);
        int res = 0;
        for (auto& q : ans) {
            res += mapa[q];
        }
        cout << res << endl;
    }

}