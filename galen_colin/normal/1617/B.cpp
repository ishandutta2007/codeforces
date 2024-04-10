#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    for (int a = 2; ; a++) {
        int c = 1;
        int b = n - a - c;
        if (std::gcd(a, b) == c) {
            cout << a << ' ' << b << ' ' << c << '\n';
            return;
        }
    }
    // n - 2, 2, 1
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}