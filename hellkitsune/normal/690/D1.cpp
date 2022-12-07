#include <bits/stdc++.h>

using namespace std;

int r, c;
string s[100];

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; ++i) {
        cin >> s[i];
    }
    int cnt = 0;
    for (int beg = 0; beg < c; ) if (s[r - 1][beg] != '.') {
        int end = beg + 1;
        while (end < c && s[r - 1][end] != '.') ++end;
        ++cnt;
        beg = end;
    } else {
        ++beg;
    }
    cout << cnt << endl;
    return 0;
}