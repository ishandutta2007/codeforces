#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[100005];
string s[100005];
bool have[26];
int nx[26];
int deg[26];
string ans;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", buf);
        s[i] = string(buf);
    }
    memset(nx, -1, sizeof nx);
    forn(i, n) {
        for (char c : s[i]) {
            have[c - 'a'] = true;
        }
        forn(j, (int)s[i].size() - 1) {
            int from = s[i][j] - 'a';
            int to = s[i][j + 1] - 'a';
            if (nx[from] != -1 && nx[from] != to) {
                cout << "NO" << endl;
                return 0;
            }
            nx[from] = to;
        }
    }
    forn(i, 26) if (nx[i] != -1) {
        ++deg[nx[i]];
    }
    forn(i, 26) if (have[i] && !deg[i]) {
        for (int j = i; j != -1; j = nx[j]) {
            if (!have[j]) {
                cout << "NO" << endl;
                return 0;
            }
            have[j] = false;
            ans.pb(char('a' + j));
        }
    }
    forn(i, 26) if (have[i]) {
        cout << "NO" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}