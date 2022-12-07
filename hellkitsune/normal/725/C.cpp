#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;
char ans[2][13];
int pos;
int was[26];
int from, to;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> s;
    memset(was, -1, sizeof was);
    forn(i, 27) {
        if (was[s[i] - 'A'] != -1) {
            from = was[s[i] - 'A'];
            to = i;
            break;
        }
        was[s[i] - 'A'] = i;
    }
    if (to == from + 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    int cnt = (to - from + 1) / 2;
    forn(i, cnt) {
        ans[0][cnt - 1 - i] = s[from + i];
    }
    int cnt2 = to - from - cnt;
    forn(i, cnt2) {
        ans[1][i] = s[from + cnt + i];
    }
    int pos = cnt, y = 0;
    for (int i = from - 1; i >= 0; --i) {
        if (pos == 13) {
            pos = 12;
            y = 1;
        }
        ans[y][pos] = s[i];
        if (y == 0) ++pos;
        else --pos;
    }
    pos = cnt2, y = 1;
    for (int i = to + 1; i < 27; ++i) {
        if (pos == 13) {
            pos = 12;
            y = 0;
        }
        ans[y][pos] = s[i];
        if (y == 1) ++pos;
        else --pos;
    }

    forn(i, 2) {
        forn(j, 13) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}