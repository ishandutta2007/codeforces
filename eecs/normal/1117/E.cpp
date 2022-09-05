#include <bits/stdc++.h>
using namespace std;

string s, tmp, ans[3];

string ask(string s) {
    cout << "? " << s << endl;
    fflush(stdout);
    string t;
    cin >> t;
    return t;
}

int main() {
    cin >> s;
    int base = 26, n = s.length();
    for (int i = 0; i < 3; i++) {
        string t;
        for (int j = 0; j < n; j++) {
            t.push_back(j % base / (base / 26) + 'a');
        }
        ans[i] = ask(t);
        base *= 26;
    }
    cout << "! ";
    tmp = s;
    for (int i = 0; i < n; i++) {
        int p1 = (ans[2][i] - 'a') * 676;
        int p2 = (ans[1][i] - 'a') * 26;
        int p3 = (ans[0][i] - 'a') * 1;
        tmp[p1 + p2 + p3] = s[i];
    }
    cout << tmp << endl;
    fflush(stdout);
    return 0;
}