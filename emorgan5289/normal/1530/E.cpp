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
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        string t = "";
        map<char, ll> f;
        for (char c : s) f[c]++;
        char a = s[0], b = 'z';
        for (char c : s)
            if (c < a) a = c;
        for (char c : s)
            if (c < b && c != a) b = c;
        if (f[a] == n) {
            for (int i = 0; i < n; i++)
                cout << a;
            cout << "\n";
            continue;
        }
        if (f[a] == 1) {
            cout << a; f[a]--;
            for (char c = 'a'; c <= 'z'; c++) {
                while (f[c] > 0) cout << c, f[c]--;
            }
            cout << "\n";
            continue;
        }
        char aa = '$';
        for (char c = 'a'; c <= 'z'; c++)
            if (f[c] == 1) {
                aa = c; break;
            }
        if (f[aa] == 1) {
            cout << aa; f[aa]--;
            for (char c = 'a'; c <= 'z'; c++) {
                while (f[c] > 0) cout << c, f[c]--;
            }
            cout << "\n";
            continue;
        }
        t += a; f[a]--;
        if (f[a] > n/2) {
            if (f[a]+f[b] == n-1) {
                while (f[b] > 0) t += b, f[b]--;
                while (f[a] > 0) t += a, f[a]--;
            } else {
                t += b; f[b]--;
                while (f[a] > 0) t += a, f[a]--;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c != a && c != b && f[c] > 0) {
                        t += c; f[c]--; break;
                    }
                }
                for (char c = 'a'; c <= 'z'; c++) {
                    while (f[c] > 0) t += c, f[c]--;
                }
            }
        } else {
            char x = b;
            while (f[a] > 0) {
                t += a; f[a]--;
                while (x <= 'z' && f[x] == 0) x++;
                if (x <= 'z') {
                    t += x; f[x]--;
                }
            }
            for (char c = 'a'; c <= 'z'; c++) {
                while (f[c] > 0) t += c, f[c]--;
            }
        }
        assert(t.size() == s.size());
        for (int i = 1; i < n-1; i++)
            assert(t.substr(i, 2) != t.substr(0, 2));
        cout << t << "\n";
        sort(all(t)); sort(all(s));
        assert(t == s);
    }
}