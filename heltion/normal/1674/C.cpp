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
        if (t == "a") cout << "1\n";
        else if (not ranges::count(s, 'a')) cout << "1\n";
        else if (ranges::count(t, 'a')) cout << "-1\n";
        else cout << (1LL << s.size()) << "\n";
    }
}