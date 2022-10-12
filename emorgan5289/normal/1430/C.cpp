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
        vector<int> a(n); iota(all(a), 1);
        while (a.size() > 1) {
            ll x = a.back(); a.pop_back();
            a.back() = (a.back()+x+1)/2;
        }
        cout << a.back() << "\n";
        a.resize(n), iota(all(a), 1);
        while (a.size() > 1) {
            ll x = a.back(); a.pop_back();
            cout << x << " " << a.back() << "\n";
            a.back() = (a.back()+x+1)/2;
        }
    }
}