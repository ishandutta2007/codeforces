#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int main() {
    cin >> s;
    int bad = 0;
    int n = s.size();
    forn(i, n / 2) if (s[i] != s[n - 1 - i]) {
        ++bad;
    }
    if (bad == 1 || (bad == 0 && n % 2 == 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}