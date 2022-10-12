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
        int n; cin >> n; n /= 2;
        if (n%2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            const int p = 100000000;
            for (int i = 1; i <= n/2; i++)
                cout << p-(2*i) << " " << p+(2*i) << " ";
            for (int i = 1; i <= n/2; i++)
                cout << p-(2*i)-1 << " " << p+(2*i)+1 << " ";
            cout << "\n";
        }
    }
}