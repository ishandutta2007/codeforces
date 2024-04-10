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
        int mi = inf, ma = -inf;
        int m = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] != -1 && a[i+1] != -1) {
                m = max(m, abs(a[i]-a[i+1]));
            } else if (a[i] != -1) {
                ma = max(ma, a[i]);
                mi = min(mi, a[i]);
            } else if (a[i+1] != -1) {
                ma = max(ma, a[i+1]);
                mi = min(mi, a[i+1]);
            }
        }
        int k = (mi+ma)/2;
        cout << max(m, ma-k) << " " << k << "\n";
    }
}