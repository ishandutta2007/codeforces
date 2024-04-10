#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[10005];
string t;
int n;
bool can[10005][4] = {};
set<string> ma;

int main() {
    scanf("%s", s);
    n = strlen(s);
    REP(i, n - 5) s[i] = s[i + 5];
    n -= 5;
    s[n] = '\0';
    t = string(s);
    if (n >= 2) {
        ma.insert(t.substr(n - 2, 2));
        can[n - 2][2] = true;
    }
    if (n >= 3) {
        ma.insert(t.substr(n - 3, 3));
        can[n - 3][3] = true;
    }
    for (int i = n - 2; i >= 0; --i) {
        if (can[i][2] && i - 2 >= 0) {
            if (t.substr(i - 2, 2) != t.substr(i, 2)) {
                ma.insert(t.substr(i - 2, 2));
                can[i - 2][2] = true;
            }
        }
        if (can[i][3] && i - 3 >= 0) {
            if (t.substr(i - 3, 3) != t.substr(i, 3)) {
                ma.insert(t.substr(i - 3, 3));
                can[i - 3][3] = true;
            }
        }
        if (can[i][2] && i - 3 >= 0) {
            ma.insert(t.substr(i - 3, 3));
            can[i - 3][3] = true;
        }
        if (can[i][3] && i - 2 >= 0) {
            ma.insert(t.substr(i - 2, 2));
            can[i - 2][2] = true;
        }
    }
    printf("%d\n", (int)ma.size());
    for (string s : ma) {
        printf("%s\n", s.c_str());
    }
    return 0;
}