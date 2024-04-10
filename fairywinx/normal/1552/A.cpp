#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    char lst = 'a';
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    string z = s;
    sort(all(z));
    for (int i = 0; i < n; ++i) {
        if (s[i] != z[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
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