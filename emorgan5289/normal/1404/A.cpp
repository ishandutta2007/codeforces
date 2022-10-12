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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<char> c(k, '?');
        bool valid = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') continue;
            if (c[i%k] == '?' || c[i%k] == s[i])
                c[i%k] = s[i];
            else valid = 0;
        }
        int x = 0, y = 0;
        for (int i = 0; i < k; i++) {
            if (c[i] == '1') x++;
            if (c[i] == '0') y++;
        }
        if (x > k/2 || y > k/2)
            valid = 0;
        cout << (valid ? "YES" : "NO") << "\n";
    }
}