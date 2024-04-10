#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s[1] << '\n';
    } else {
        cout << *min_element(all(s)) << '\n';
    }
}

int main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

   SOLVE
}