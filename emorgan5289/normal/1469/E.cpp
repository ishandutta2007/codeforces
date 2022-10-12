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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e6+5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> p(2*n+5), f(2*n+5);
        for (int i = 0; i < s.size(); i++)
            p[i+1] = p[i]+('1'-s[i]);
        for (int i = k; i <= s.size(); i++)
            if (p[i-k] == p[max(i-30, i-k)]) {
                int x = 0;
                for (int j = max(i-30, i-k); j < i; j++)
                    x = 2*x+('1'-s[j]);
                if (x < 2*n+5) f[x]++;
            }
        int x = 0;
        while (f[x]) x++;
        string ans;
        for (int i = 0; i < k-30; i++)
            ans += '0';
        for (int i = min(k, 30)-1; i >= 0; i--)
            ans += x&(1<<i) ? '1' : '0';
        if (x >= 1<<min(k, 30))
            cout << "NO\n";
        else
            cout << "YES\n" << ans << "\n";
    }
}