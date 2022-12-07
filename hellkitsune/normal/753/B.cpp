#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

vector<int> has;

bool used[4] = {};
int p[4];
int a, b;

void go(int pos) {
    if (pos == 4) {
        forn(i, 4) cout << has[p[i]];
        cout << endl;
        cin >> a >> b;
        if (a == 4) {
            exit(0);
        }
        return;
    }
    forn(i, 4) if (!used[i]) {
        used[i] = true;
        p[pos] = i;
        go(pos + 1);
        used[i] = false;
    }
}

int main() {
    forn(i, 10) {
        forn(j, 4) cout << i;
        cout << endl;
        cin >> a >> b;
        if (a + b > 0) {
            has.pb(i);
        }
    }
    assert(int(has.size()) == 4);
    go(0);
    return 0;
}