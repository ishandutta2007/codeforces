#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 305;
int n;
char c[N][N], d[N][N];

int solve(string s) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            d[i][j] = c[i][j];
            if (c[i][j] != '.' && s[(i+j)%3] != '.' && s[(i+j)%3] != c[i][j])
                d[i][j] = s[(i+j)%3], ans++;
        }
    return ans;
}

vector<string> opts = {"XO.", "OX.", "X.O", "O.X", ".XO", ".OX"};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n+2; i++)
            for (int j = 0; j < n+2; j++)
                c[i][j] = '.';
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> c[i][j];
        string m = opts[0];
        for (auto& s : opts)
            if (solve(s) < solve(m)) m = s;
        solve(m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << d[i][j];
            cout << "\n";
        }
    }
}