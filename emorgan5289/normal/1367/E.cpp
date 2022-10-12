#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int f[26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        fill(f, f+26, 0);
        for (auto& x : s) f[x-'a']++;
        for (int i = n; i > 0; i--) {
            int w = i/__gcd(i, k), x = 0;
            for (int j = 0; j < 26; j++)
                x += f[j]/w;
            if (x >= __gcd(i, k)) {
                cout << i << "\n";
                break;
            }
        }
    }
}