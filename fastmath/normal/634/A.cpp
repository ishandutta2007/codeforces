#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> a, b;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; if (x) a.push_back(x);
    }   
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; if (x) b.push_back(x);
    }
      
    int pos = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == b[0]) pos = i;
    }   
                             
    string ans = "YES";
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] != a[(pos + i) % (n - 1)]) ans = "NO";
    }   

    cout << ans << '\n';

    return 0;
}