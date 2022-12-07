#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[200005];
int ans = 0;

char rev(char c) {
    if (c == 'L') return 'R';
    if (c == 'R') return 'L';
    if (c == 'U') return 'D';
    if (c == 'D') return 'U';
    return '-';
}

int main() {
    scanf("%d%s", &n, s);
    char c1 = '-', c2 = '-';
    for (int beg = 0; beg < n; ) {
        int end = beg + 1;
        while (end < n && s[end] == s[beg]) {
            ++end;
        }
        char c = s[beg];
        beg = end;
        if (c == c1 || c == c2) {
            continue;
        }
        if (c1 == '-') {
            c1 = c;
            ++ans;
        } else if (c2 == '-' && c1 != rev(c)) {
            c2 = c;
        } else {
            c2 = '-';
            c1 = c;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}