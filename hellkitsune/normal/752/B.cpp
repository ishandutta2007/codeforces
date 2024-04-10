#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<char, char> PII;

char s[1005], t[1005];
int n;

char to[256];

vector<PII> ans;

int main() {
    scanf("%s%s", s, t);
    n = strlen(s);
    for (char c = 'a'; c <= 'z'; ++c) {
        to[int(c)] = c;
    }
    forn(i, n) {
        to[int(s[i])] = t[i];
        to[int(t[i])] = s[i];
    }
    forn(i, n) {
        if (to[int(s[i])] != t[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (to[int(to[int(c)])] != c) {
            cout << -1 << endl;
            return 0;
        }
        if (to[int(c)] != c) {
            char cc = to[int(c)];
            if (cc > c) {
                ans.pb(mp(c, cc));
            }
        }
    }
    cout << int(ans.size()) << endl;
    for (PII x : ans) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}