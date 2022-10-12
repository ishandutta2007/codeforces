#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n); for (auto& x : a) cin >> x;
        vector<int> p(n), s(n);
        for (int i = 0; i < n; i++)
            p[i] = min(i == 0 ? inf : p[i-1], a[i]);
        for (int i = n-1; i >= 0; i--)
            s[i] = max(i == n-1 ? -inf : s[i+1], a[i]);
        bool v = p[0] > s[n-1];
        debug(p, s);
        for (int i = 1; i < n; i++)
            v = v || p[i-1] > s[i];
        cout << (v ? "NO" : "YES") << "\n";
    }
}