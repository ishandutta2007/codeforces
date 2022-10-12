#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n); for (auto& x : p) cin >> x;
        vector<int> b = {0};
        for (int i = 1; i < n; i++)
            if (p[i] != p[i-1]+1)
                b.pb(i);
        b.pb(n);
        for (int i = 0; i < b.size()-1; i++) {
            int x = b[i], y = b[i+1]-1;
            reverse(&p[x], &p[y]+1);
        }
        bool v = 1;
        for (int i = 0; i < n-1; i++)
            v &= p[i] == p[i+1]+1;
        cout << (v ? "Yes" : "No") << "\n";
    }
}