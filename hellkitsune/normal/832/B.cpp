#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
char s[100005], t[100005];
bool g[26] = {};

bool check(char a, char b) {
    return (a == '?' && g[b - 'a']) || (a == b);
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    forn(i, n) g[s[i] - 'a'] = true;
    scanf("%s%d", s, &q);
    n = strlen(s);

    bool hasAst = false;
    int astPos = -1;
    forn(i, n) if (s[i] == '*') {
        hasAst = true;
        astPos = i;
    }

    forn(_, q) {
        scanf("%s", t);
        int len = strlen(t);
        bool ok = true;
        if (hasAst) {
            if (len < n - 1) {
                ok = false;
            } else {
                forn(i, astPos) if (!check(s[i], t[i])) {
                    ok = false;
                }
                forn(i, n - 1 - astPos) if (!check(s[n - 1 - i], t[len - 1 - i])) {
                    ok = false;
                }
                for (int i = astPos; i < astPos + len - n + 1; ++i) {
                    if (g[t[i] - 'a']) {
                        ok = false;
                    }
                }
            }
        } else {
            if (len != n) {
                ok = false;
            }
            if (ok) forn(i, len) {
                if (!check(s[i], t[i])) {
                    ok = false;
                }
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}