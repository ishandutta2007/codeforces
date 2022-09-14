#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> p(26);
        for (int i = 0; i < n; i += 1)
            p[s[i] - 'a'].push_back(i);
        vector<int> ans;
        if (s[0] <= s.back())
            for (char c = s[0]; c <= s.back(); c += 1)
                for (int pi : p[c - 'a'])
                    ans.push_back(pi);
        else
            for (char c = s[0]; c >= s.back(); c -= 1) {
                for (int pi : p[c - 'a']) 
                    ans.push_back(pi);
            }
        cout << abs(s[0] - s.back()) << " " << ans.size() << "\n";
        for (int p : ans) cout << p + 1 << " ";
        cout << "\n";
    }
}