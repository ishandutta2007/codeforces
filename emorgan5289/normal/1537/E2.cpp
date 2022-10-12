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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

string s;
vector<int> z;

// s[0..x) ^ inf < s[0..y) ^ inf
// where x > y
bool cmp(int x, int y) {
    if (z[y] < x-y)
        return s[y+z[y]] < s[z[y]];
    if (z[x-y] < y)
        return s[z[x-y]] < s[x-y+z[x-y]];
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    cin >> s;
    z = z_function(s);
    int p = 1;
    for (int i = 2; i <= n; i++)
        if (cmp(i, p)) p = i;
    for (int i = 0; i < k; i++)
        cout << s[i%p];
    cout << "\n";
}