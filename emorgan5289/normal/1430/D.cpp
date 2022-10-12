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
        string s; cin >> s; s += '$';
        vector<int> a;
        char x = '$';
        int b = 0;
        for (auto& c : s) {
            if (c != x) {
                if (x != '$') a.pb(b);
                b = 0, x = c;
            }
            b++;
        }
        int j = 0, c = 0;
        for (int i = 0; i < a.size(); i++) {
            c++;
            while (j < a.size() && a[j] <= 1) j++;
            if (j < a.size()) a[j]--;
            else a[i++] = 0;
            if (i < a.size()) a[i] = 0;
            debug(a, i, j);
        }
        cout << c << "\n";
    }
}