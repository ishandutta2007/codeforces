#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string x;

bool pal(string x) {
    forn(i, x.length()) {
        if (x[i] != x[(int)x.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> x;
    forn(_, 20) {
        if (pal(x)) {
            cout << "YES" << endl;
            return 0;
        }
        x = string(1, '0') + x;
    }
    cout << "NO" << endl;
    return 0;
}