#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        function<int(string)> check = [&](string s){
            if (s.empty()) return 1;
            if (s[0] == 'a' + s.size() - 1) return check(s.substr(1));
            if (s.back() == 'a' + s.size() - 1) return check(s.substr(0, s.size() - 1));
            return 0;
        };
        string s;
        cin >> s;
        cout << (check(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}