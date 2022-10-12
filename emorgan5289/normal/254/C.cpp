#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#else
#include "../../debug.cpp"
#endif


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, t; cin >> s >> t;
    ll n = s.size();
    map<char, ll> fs, ft;
    for (char c : s) fs[c]++;
    for (char c : t) ft[c]++;
    ll ans = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        debug(c, fs[c], ft[c]);
        if (fs[c] > ft[c]) ans += fs[c]-ft[c];
    }
    for (int i = 0; i < n; i++) {
        bool upd = 0;
        for (char c = 'A'; c <= 'Z'; c++)
            if (fs[s[i]] > ft[s[i]] && fs[c] < ft[c] && (c < s[i] || ft[s[i]] == 0)) {
                fs[s[i]]--;
                s[i] = c;
                ft[c]--;
                upd = 1;
                break;
            }
        if (!upd) {
            fs[s[i]]--;
            ft[s[i]]--;
        }
    }
    cout << ans << "\n" << s << "\n";
}