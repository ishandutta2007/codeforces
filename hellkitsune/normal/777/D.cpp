#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[500005];
string s[500005];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s", buf);
        s[i] = string(buf);
    }
    for (int i = n - 2; i >= 0; --i) {
        bool done = false;
        int len = min(s[i].size(), s[i + 1].size());
        forn(j, len) {
            if (s[i][j] < s[i + 1][j]) {
                done = true;
                break;
            }
            if (s[i][j] > s[i + 1][j]) {
                s[i].resize(j);
                done = true;
                break;
            }
        }
        if (!done && s[i].size() > s[i + 1].size()) {
            s[i].resize(s[i + 1].size());
        }
    }
    forn(i, n) {
        printf("%s\n", s[i].c_str());
    }
    return 0;
}