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
        int n; cin >> n;
        string s; cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                if (s[i] == '0') x++;
                else y++;
            }
        }
        cout << max(x, y) << "\n";
    }
}