#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt;
int n, k;
string s[100];
string t;
string save[100];
bool can[100][100];
int d[100][100];
int pre[100];

bool check(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> tt;
    forn(test, tt) {
        memset(pre, -1, sizeof pre);
        cin >> n;
        forn(i, n) cin >> s[i];
        cin >> k;
        getline(cin, t);
        forn(i, k) forn(j, n) {
            can[i][j] = true;
        }
        forn(i, k) {
            getline(cin, t);
            if (t[0] != '?') {
                int end = 0;
                while (t[end] != ':') {
                    ++end;
                }
                string cur = t.substr(0, end);
                forn(j, n) if (cur == s[j]) {
                    pre[i] = j;
                }
            }
            save[i] = t;
            int len = int(t.size());
            for (int beg = 0; beg < len; ) {
                if (!check(t[beg])) {
                    ++beg;
                    continue;
                }
                int end = beg + 1;
                while (end < len && check(t[end])) {
                    ++end;
                }
                string cur = t.substr(beg, end - beg);
                forn(j, n) if (cur == s[j]) {
                    can[i][j] = false;
                }
                beg = end;
            }
        }
        memset(d, -1, sizeof d);
        if (pre[0] != -1) {
            d[0][pre[0]] = 0;
        } else {
            forn(i, n) {
                if (can[0][i]) {
                    d[0][i] = 0;
                }
            }
        }
        for (int i = 1; i < k; ++i) {
            if (pre[i] != -1) {
                int j = pre[i];
                forn(p, n) if (p != j && d[i - 1][p] != -1) {
                    d[i][j] = p;
                    break;
                }
            } else {
                forn(j, n) if (can[i][j]) {
                    forn(p, n) if (p != j && d[i - 1][p] != -1) {
                        d[i][j] = p;
                        break;
                    }
                }
            }
        }
        int ind = -1;
        forn(i, n) if (d[k - 1][i] != -1) {
            ind = i;
            break;
        }
        if (ind == -1) {
            cout << "Impossible\n";
            continue;
        }
        for (int i = k - 1; i >= 0; --i) {
            if (save[i][0] == '?') {
                save[i] = s[ind] + save[i].substr(1);
            }
            ind = d[i][ind];
        }
        forn(i, k) {
            cout << save[i] << '\n';
        }
    }
    return 0;
}