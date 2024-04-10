#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int c;
    cin >> c;
    string s;
    cin >> s;
    if (s[3] >= '6') s[3] = '0';
    if (c == 24) {
        if (stoi(s.substr(0, 2)) < 24);
        else s[0] = '0';
    }
    else {
        if (1 <= stoi(s.substr(0, 2)) && stoi(s.substr(0, 2)) <= 12);
        else {
            int cnt = 1e9;
            string x = "";
            for (int i = 1; i <= 12; ++i) {
                string c = to_string(i);
                if (c.size() == 1) c.insert(c.begin(), '0');
                int cur = 0;
                for (int j = 0; j < 2; ++j) {
                    if (c[j] != s[j]) ++cur;
                }
                if (cur < cnt) {
                    cnt = cur;
                    x = c;
                }
            }
            for (int i = 0; i < 2; ++i) s[i] = x[i];
        }
    }
    cout << s << '\n';
}