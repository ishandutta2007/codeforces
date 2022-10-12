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
        ll x = 0, y = 0;
        for (char c : s) {
            if (c == '0') x++;
            else y++;
        }
        if (x < y) {
            swap(x, y);
            for (char& c : s)
                c ^= '0'^'1';
            reverse(all(s));
        }

        debug(s);
        vector<int> d(n+1);
        map<int, int> md;
        md[0] = n;
        for (int i = n-1; i >= 0; i--) {
            d[i] = d[i+1] + (s[i] == '0' ? -1 : 1);
            if (!md.count(d[i]))
                md[d[i]] = i;
        }

        debug(md);

        int i = 0, j = 0, ans = 0;
        // s[0..i) is all 0
        // s[i..j) is all 1
        while (1) {
            while (i < n && s[i] == '0') i++;
            if (j <= i) j = i+1;
            while (j < n && s[j] == '1') j++;
            if (x-i <= y) break;

            int k = (md[d[0]+i]-i)/2;
            debug(i, j, k, s);

            while (j < i+2*k)
                s[j++] = '1';
            while (k--)
                s[i++] = '0';
            ans++;
        }

        debug(s);
        if (!is_sorted(all(s)))
            ans++;

        cout << ans << "\n";
    }
}