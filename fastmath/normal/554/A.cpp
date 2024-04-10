#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    set <string> ans;
    for (char c = 'a'; c <= 'z' ; ++c) {
        ans.insert(c + s);
        for (int i = 0; i < n; ++i) {
            ans.insert(s.substr(0, i + 1) + c + s.substr(i + 1, n - i - 1));
        }   
    }

    cout << ans.size() << '\n';
    return 0;
}