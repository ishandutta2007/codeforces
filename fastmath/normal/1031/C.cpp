#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int sum = 0;
    int ans = 0;
    while (sum + ans + 1 <= a + b) {
        ++ans;
        sum += ans;
    }
    
    if (!a) {
        cout << "0\n";
        cout << ans << '\n';
        for (int i = 1; i <= ans; ++i) cout << i << ' ';
        cout << '\n';
        exit(0);
    }   
    else if (sum <= a) {
        cout << ans << '\n';
        for (int i = 1; i <= ans; ++i) cout << i << ' ';
        cout << '\n';
        cout << "0\n";
        exit(0);
    }
    else {
        vector <int> f, s;
        for (int i = ans; i >= 1; --i) {
            if (i <= a) {
                a -= i;
                f.push_back(i);
            }
            else {
                s.push_back(i);
            }
        }
        cout << f.size() << '\n';
        for (int e : f) cout << e << ' ';
        cout << '\n';
        cout << s.size() << '\n';
        for (int e : s) cout << e << ' ';
        cout << '\n';
    }

    return 0;
}