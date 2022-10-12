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
    while (t --> 0) { // t goes to zero
        int n; fin >> n;
        string out = "YES";
        int p = 0, c = 0;
        while (n--) {
            // debug(n);
            int a, b; fin >> a >> b;
            if (a >= p && b >= c && (a-p >= b-c)) {
                p = a; c = b;
            } else {
                out = "NO";
            }
        }
        cout << out << "\n";

        next:;
    }
}