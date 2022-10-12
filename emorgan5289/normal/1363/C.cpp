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
        int n, x; cin >> n >> x;
        int d = 0;
        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            if (u == x || v == x) d++;
        }
        if (d < 2)
            cout << "Ayush\n";
        else
            cout << (n&1 ? "Ashish\n" : "Ayush\n");
    }
}