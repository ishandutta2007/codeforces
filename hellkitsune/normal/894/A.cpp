#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

int main() {
    cin >> s;
    n = s.size();
    int ans = 0;
    forn(i, n) forn(j, i) forn(k, j) {
        if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q') {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}