#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000], b[1000], c[1000];
int have[1001];

bool check() {
    int dif = 0;
    forn(i, n) dif += b[i] != c[i];
    return dif == 1;
}

void out() {
    forn(i, n) cout << c[i] << ' ';
    cout << endl;
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) ++have[a[i]];
    int need = -1, ex = -1;
    forn(i, n) if (!have[i + 1]) {
        need = i + 1;
    } else if (have[i + 1] == 2) {
        ex = i + 1;
    }
    forn(i, n) c[i] = a[i];
    forn(i, n) if (c[i] == ex) {
        c[i] = need;
        break;
    }
    if (check()) {
        out();
        return 0;
    }
    forn(i, n) c[i] = a[i];
    for (int i = n - 1; i >= 0; --i) if (c[i] == ex) {
        c[i] = need;
        break;
    }
    assert(check());
    out();
    return 0;
}