#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
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
        int n, k; cin >> n >> k;
        if ((n-k+1)%2 == 1 && (n-k+1) > 0) {
            cout << "YES\n";
            for (int i = 0; i < k-1; i++)
                cout << "1 ";
            cout << (n-k+1) << "\n";
        } else if ((n-2*k+2)%2 == 0 && (n-2*k+2) > 0) {
            cout << "YES\n";
            for (int i = 0; i < k-1; i++)
                cout << "2 ";
            cout << (n-2*k+2) << "\n";
        } else {
            cout << "NO\n";
        }
    }
}