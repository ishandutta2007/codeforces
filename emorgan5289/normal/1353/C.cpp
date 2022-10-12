#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
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
        ull out = 0;
        ull n; cin >> n;
        for (ull i = 0; i < n/2; i++) {
            out += ((2*i+3)*(2*i+3)-(2*i+1)*(2*i+1))*(i+1);
        }
        cout << out << "\n";
    }
}