#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];
bool used[26];

int main() {
    scanf("%d%d%s", &n, &k, s);
    char mn = 'z', mx = 'a';
    forn(i, n) {
        mn = min(mn, s[i]);
        mx = max(mx, s[i]);
        used[s[i] - 'a'] = true;
    }
    if (k > n) {
        for (int i = n; i < k; ++i) {
            s[i] = mn;
        }
        s[k] = '\0';
        printf("%s\n", s);
        return 0;
    }
    s[k] = '\0';
    for (int i = k - 1; i >= 0; --i) {
        if (s[i] != mx) {
            for (int j = s[i] - 'a' + 1; j < 26; ++j) {
                if (used[j]) {
                    s[i] = 'a' + j;
                    break;
                }
            }
            for (int j = i + 1; j < k; ++j) {
                s[j] = mn;
            }
            break;
        }
    }
    printf("%s\n", s);
    return 0;
}