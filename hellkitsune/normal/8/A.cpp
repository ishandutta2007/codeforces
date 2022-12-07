#include <bits/stdc++.h>

using namespace std;

string s, s1, s2;
bool fw, bw, half, ch = true;

bool solve(string s, string s1, string s2) {
    size_t pos = s.find(s1);
    if (pos == string::npos) {
        return false;
    }
    pos = s.find(s2, pos + (int)s1.length());
    return pos != string::npos;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> s1 >> s2;
    bool fw = solve(s, s1, s2);
    reverse(s.begin(), s.end());
    bool bw = solve(s, s1, s2);
    if (fw && bw) {
        cout << "both" << '\n';
    } else if (fw) {
        cout << "forward" << '\n';
    } else if (bw) {
        cout << "backward" << '\n';
    } else {
        cout << "fantasy" << '\n';
    }
    return 0;
}