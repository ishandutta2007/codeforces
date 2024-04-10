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
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<int> a(n); for (auto& x : a) fin >> x;
        int m = 0;
        vector<int> b(2*n, 0);
        vector<int> v(n);
        for (int i = 0; i < n-1; i++) {
            m = max(m, a[i]);
            if (b[a[i]])
                break;
            b[a[i]] = 1;
            if (m == i+1)
                v[i] = 1;
        }
        vector<int> out;
        m = 0;
        b.assign(2*n, 0);
        for (int i = n-1; i >= 1; i--) {
            m = max(m, a[i]);
            if (b[a[i]])
                break;
            b[a[i]] = 1;
            if (m == (n-i) && v[i-1])
                out.pb(i);
        }
        cout << out.size() << "\n";
        for (auto& x : out) {
            cout << x << " " << n-x << "\n";
        }
    }
}