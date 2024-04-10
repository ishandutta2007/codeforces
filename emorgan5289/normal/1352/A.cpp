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
        int k = 1;
        vector<int> o;
        while (n > 0) {
            if (n%10 != 0) o.pb((n%10)*k);
            k *= 10; n /= 10;
        }
        cout << o.size() << "\n";
        for (auto& x : o) cout << x << " ";
        cout << "\n";
    }
}