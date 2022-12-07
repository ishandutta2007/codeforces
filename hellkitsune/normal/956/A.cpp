#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[55][55];
set<LL> se;
LL tot = 0;

int main() {
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%s", s[i]);
    forn(i, n) {
        LL x = 0;
        forn(j, m) if (s[i][j] == '#') {
            x |= 1ll << j;
        }
        se.insert(x);
    }
    for (LL x : se) {
        if (tot & x) {
            cout << "No" << endl;
            return 0;
        }
        tot |= x;
    }
    cout << "Yes" << endl;
    return 0;
}