#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> vs = {"", "", "", "the", "", "buffy", "slayer", "vampire"};
    string s;
    cin >> s;
    if (vs[s.size()].empty()) cout << "none";
    else for (int i = 0; i < s.size(); i += 1)
        cout << char((s[i] - 'a' + vs[s.size()][i] - 'a') % 26 + 'a');
    return 0;
}