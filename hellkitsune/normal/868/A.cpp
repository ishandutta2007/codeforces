#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n;
string t[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> n;
    forn(i, n) cin >> t[i];
    forn(i, n) if (t[i] == s) {
        cout << "YES" << endl;
        return 0;
    }
    forn(i, n) forn(j, n) {
        if (t[i][1] == s[0] && t[j][0] == s[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}