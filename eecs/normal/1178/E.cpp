#include <bits/stdc++.h>
using namespace std;

string s;
int tot;
char t[1000010];

void solve(int l, int r) {
    if (l > r) return;
    if (r - l >= 3) {
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (s[l] != ch && s[l + 1] != ch) continue;
            if (s[r] != ch && s[r - 1] != ch) continue;
            t[++tot] = ch;
            solve(l + 2, r - 2);
            t[++tot] = ch; break;
        }
    } else {
        t[++tot] = s[l];
    }
}

int main() {
    cin >> s;
    solve(0, s.length() - 1);
    printf("%s\n", t + 1);
    return 0;
}