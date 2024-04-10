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
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<vector<char>> a(n, vector<char>(n, '='));
        bool ok = 1;
        for (int i = 0; i < n; i++)
            a[i][i] = 'X';
        vector<int> b;
        for (int i = 0; i < n; i++)
            if (s[i] == '2') b.pb(i);
        if (b.size() > 0 && b.size() < 3) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < b.size(); i++) {
            a[b[i]][b[(i+1)%b.size()]] = '+';
            a[b[(i+1)%b.size()]][b[i]] = '-';
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << a[i][j];
            cout << "\n";
        }
    }
}