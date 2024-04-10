#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[10];

int main() {
    cin >> s;
    cnt[1] = cnt[6] = cnt[8] = cnt[9] = 1;
    string t;
    for (char c : s) if (c ^ '0') {
        if (!cnt[c - '0']) t.push_back(c);
        else cnt[c - '0']--;
    }
    int cur = 0;
    for (char c : t) {
        cur = (cur * 10 + c - '0') % 7;
    }
    string h = "1689";
    do {
        int tmp = cur;
        for (char c : h) {
            tmp = (tmp * 10 + c - '0') % 7;
        }
        if (!tmp) { t.append(h); break; }
    } while (next_permutation(h.begin(), h.end()));
    for (char c : s) if (c == '0') {
        t.push_back(c);
    }
    cout << t << '\n';
    return 0;
}