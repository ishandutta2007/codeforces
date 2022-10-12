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

char get(int i) {
    cout << "? 1 " << i+1 << endl;
    char x; cin >> x; return x;
}

int distinct(int l, int r) {
    cout << "? 2 " << l+1 << " " << r+1 << endl;
    int x; cin >> x; return x;
}

void submit(string s) {
    cout << "! " << s << endl;
}

int main() {
    int n; cin >> n;
    string s(n, ' ');
    for (int i = 0; i < n; i++) {
        vector<int> p, v(256);
        for (int j = i-1; j >= 0; j--)
            if (!v[s[j]]) {
                p.pb(j);
                v[s[j]] = 1;
            }
        int k = -1;
        for (int x = 32; x > 0; x /= 2)
            if (k+x < p.size() && distinct(p[k+x], i) == k+x+2)
                k += x;
        s[i] = k+1 == p.size() ? get(i) : s[p[k+1]];
    }
    submit(s);
}