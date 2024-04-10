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
        int n; cin >> n;
        vector<int> p(n); for (auto& x : p) cin >> x;
        int a = 0, b = 0, i = 0, j = n-1;
        int pa = 0, pb = 0;
        int k = 0;
        while (i <= j) {
            int s = 0;
            while (s <= pa && i <= j) {
                s += p[i];
                a += p[i];
                i++;
            }
            pa = s;
            k++;
            // debug(i, j, a, b);
            if (i > j) break;
            s = 0;
            while (s <= pa && i <= j) {
                s += p[j];
                b += p[j];
                j--;
            }
            pa = s;
            k++;
            // debug(i, j, a, b);
        }
        // debug(t);
        cout << k << " " << a << " " << b << "\n"; 
    }
}