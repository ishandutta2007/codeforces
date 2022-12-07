#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[105][105], t[105][105];

void check() {
    if (n % 3 != 0) {
        return;
    }
    int half = n / 3;
    int R = 0, G = 0, B = 0;
    forn(p, 3) {
        char c = s[p * half][0];
        for (int i = p * half; i < (p + 1) * half; ++i) forn(j, m) {
            if (s[i][j] != c) {
                return;
            }
        }
        if (c == 'R') ++R;
        if (c == 'G') ++G;
        if (c == 'B') ++B;
    }
    if (R && G && B) {
        cout << "YES" << endl;
        exit(0);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    check();
    forn(i, n) forn(j, m) {
        t[j][i] = s[i][j];
    }
    swap(n, m);
    forn(i, n) forn(j, m) {
        s[i][j] = t[i][j];
    }
    check();
    cout << "NO" << endl;
    return 0;
}