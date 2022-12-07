#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[30];
bool used[26] = {};
int nx[26] = {};
int indeg[26] = {};

int main() {
    scanf("%d", &n);
    memset(nx, -1, sizeof nx);
    REP(i, n) {
        scanf("%s", s);
        int len = strlen(s);
        REP(j, len) used[s[j] - 'a'] = true;
        REP(j, len - 1) {
            nx[s[j] - 'a'] = s[j + 1] - 'a';
            ++indeg[s[j + 1] - 'a'];
        }
    }
    string ans;
    REP(i, 26) if (used[i] && !indeg[i]) {
        for (int c = i; c != -1; c = nx[c]) {
            ans += char(c + 'a');
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}