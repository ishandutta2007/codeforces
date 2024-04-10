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
        int n, k; cin >> n >> k;
        string s; cin >> s; sort(all(s));
        if (s[0] != s[k-1]) {
            cout << s[k-1] << "\n"; continue;
        }
        if (s[k] != s[n-1]) {
            cout << s[0] << s.substr(k, n) << "\n"; continue;
        }
        cout << s[0] << s.substr(k, (n-k)/k + (n%k == 0 ? 0 : 1)) << "\n";
    }
}