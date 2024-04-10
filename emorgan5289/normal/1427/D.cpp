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

int n, a[52];
vector<vector<int>> out;

void go(vector<int> v) {
    if (v.size() == 1) return;
    debug(v);
    out.pb(v);
    vector<vector<int>> t;
    int i = 0;
    for (auto x : v) {
        t.pb({});
        while (x--) t.back().pb(a[i++]);
    }
    reverse(all(t));
    i = 0;
    for (auto& x : t)
        for (auto& y : x)
            a[i++] = y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool rev = n%2 == 0;
    debug(vector(a, a+n));
    for (int t = 0; t < n-1; t++) {
        vector<int> v;
        if (rev) reverse(a, a+n);
        for (int i = 0; i < t; i++) v.pb(1);
        v.pb(0);
        for (int i = t; i < n; i++) {
            v.back()++;
            if (a[i] == t+1) {
                if (n-1-i > 0) v.pb(n-i-1);
                break;
            }
        }
        if (rev) reverse(a, a+n);
        if (rev) reverse(all(v));
        rev = !rev;
        go(v);
        debug(vector(a, a+n));
    }
    cout << out.size() << "\n";
    for (auto& v : out) {
        cout << v.size();
        for (auto& x : v) cout << " " << x;
        cout << "\n";
    }
}