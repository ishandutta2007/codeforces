#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int h, m, s, from, to;

int main() {
    cin >> h >> m >> s >> from >> to;
    h %= 12;
    from %= 12;
    to %= 12;
    h = h * 3600 + 60 * m + s;
    m = m * 60 + s;
    bool f1 = true, f2 = true;
    for (int i = from * 3600; i != to * 3600; i = (i + 1) % (12 * 3600)) {
        if (i == h) f1 = false;
    }
    for (int i = from * 300; i != to * 300; i = (i + 1) % 3600) {
        if (i == m) f1 = false;
    }
    for (int i = from * 5; i != to * 5; i = (i + 1) % 60) {
        if (i == s) f1 = false;
    }

    for (int i = to * 3600; i != from * 3600; i = (i + 1) % (12 * 3600)) {
        if (i == h) f2 = false;
    }
    for (int i = to * 300; i != from * 300; i = (i + 1) % 3600) {
        if (i == m) f2 = false;
    }
    for (int i = to * 5; i != from * 5; i = (i + 1) % 60) {
        if (i == s) f2 = false;
    }


    if (f1 || f2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}