#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n;
char s[1000005];

int main() {
    scanf("%s", s);
    n = strlen(s);
    int ans = 0;
    int b = 0;
    for (int i = n - 1; i >= 0; --i) {
        char c = s[i];
        if (c == 'a') {
            ans = (ans + b) % MOD;
            b = (2 * b) % MOD;
        } else {
            b = (b + 1) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}