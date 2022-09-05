#include <bits/stdc++.h>
using namespace std;

int T;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        char op; string s;
        cin >> op >> s;
        reverse(s.begin(), s.end());
        for (char &c : s) {
            if ((c - '0') & 1) c = '1';
            else c = '0';
        }
        while (s.size() < 18) s.push_back('0');
        if (op == '+') mp[s]++;
        else if (op == '-') mp[s]--;
        else printf("%d\n", mp[s]);
    }
    return 0;
}