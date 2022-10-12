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
        vector<int> p(n+1);
        for (int i = 0; i < n; i++)
            p[i+1] = p[i]+(s[i] == 'a' ? 1 : -1);
        int l = -1, r = -1;
        for (int i = 0; i < n+1; i++)
            for (int j = 0; j < i; j++)
                if (p[i] == p[j]) {
                    l = j+1, r = i;
                }
        cout << l << " " << r << "\n";
    }
}