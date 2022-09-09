#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        string s, t;
        cin >> s >> t;
        auto f = [&](string s){
            string t;
            function<void(char)> add = [&](char c) {
                if (t.empty()) t.push_back(c);
                else if (t.back() == c) t.pop_back();
                else t.push_back(c);
            };
            for (char c : s) if (c != 'B') add(c);
            return t;
        };
        if ((s.size() - t.size()) & 1) cout << "NO\n";
        else cout << (f(s) == f(t) ? "YES\n" : "NO\n");
    }
}