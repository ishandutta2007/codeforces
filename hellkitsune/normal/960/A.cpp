#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
int cnt[3] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (char c : s) if (c != 'a' && c != 'b' && c != 'c') {
        cout << "NO" << endl;
        return 0;
    }
    forn(i, (int)s.length() - 1) {
        if (s[i] > s[i + 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (char c : s) ++cnt[c - 'a'];
    if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (cnt[2] != cnt[0] && cnt[2] != cnt[1]) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}