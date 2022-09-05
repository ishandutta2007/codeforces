#include <bits/stdc++.h>
using namespace std;

int cnt[26];
char t[2][26];

int main() {
    string s;
    cin >> s;
    for (char c : s) cnt[c - 'A']++;
    for (int i = 0; i < 26; i++) if (cnt[i] > 1) {
        int pos1 = -1, pos2;
        for (int j = 0; j < s.size(); j++) if (s[j] == i + 'A') {
            if (!~pos1) pos1 = j;
            else pos2 = j;
        }
        if (abs(pos1 - pos2) == 1) puts("Impossible"), exit(0);
        t[0][(pos2 - pos1 - 1) / 2] = i + 'A';
        int r = 0, c = (pos2 - pos1 - 1) / 2;
        for (int j = pos1 - 1; ~j; j--) {
            if (!r && c == 12) r++;
            else if (r && !c) r--;
            else if (!r) c++;
            else c--;
            t[r][c] = s[j];
        }
        r = 0, c = (pos2 - pos1 - 1) / 2;
        for (int j = pos1 + 1; j < s.size(); j++) if (j ^ pos2) {
            if (!r && !c) r++, c = 0;
            else if (r && c == 12) r--;
            else if (!r) c--;
            else c++;
            t[r][c] = s[j];
        }
        printf("%s\n%s\n", t[0], t[1]); break;
    }
    return 0;
}