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
        vector<int> a(n), b(n), c(n);
        for (auto& x : a) {
            char q; fin >> q;
            x = q-'0';
        }
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                b[i] = 0; c[i] = 0;
            } else if (a[i] == 1) {
                if (flag) {
                    b[i] = 1; c[i] = 0; flag = 0;
                } else {
                    b[i] = 0; c[i] = 1;
                }
            } else if (a[i] == 2) {
                if (flag) {
                    b[i] = 1; c[i] = 1;
                } else {
                    b[i] = 0; c[i] = 2;
                }
            }
        }
        for (auto& x : b) cout << x; cout << "\n"; 
        for (auto& x : c) cout << x; cout << "\n";
    }
}