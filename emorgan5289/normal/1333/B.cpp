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
        debug(t);
        int n; fin >> n;
        vector<int> a(n), b(n);
        for (auto& x : a) fin >> x;
        for (auto& x : b) fin >> x;
        bool hasp = 0, hasn = 0;
        for (int i = 0; i < n; i++) {

            debug(b[i], a[i]);
            if (b[i] > a[i] && !hasp) {
                cout << "NO\n"; goto next;
            }
            if (b[i] < a[i] && !hasn) {
                cout << "NO\n"; goto next;
            }

            if (a[i] > 0)
                hasp = 1;
            if (a[i] < 0)
                hasn = 1;
        }
        cout << "YES\n";
        next:;
    }
}