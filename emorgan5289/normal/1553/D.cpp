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
        string a, b; cin >> a >> b;
        a += '$', b += '$';
        int n = a.size();
        int i = 0, j = 1;
        int k = 0;
        for (char c : b) {
            while (i < n && (i%2 != k || a[i] != c)) i++;
            while (j < n && (j%2 == k || a[j] != c)) j++;
            k ^= 1;
        }
        cout << (min(i, j) < n ? "YES" : "NO") << "\n";
    }
}