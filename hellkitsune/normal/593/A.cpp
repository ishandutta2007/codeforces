#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s[100];
char buf[1005];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%s", buf), s[i] = string(buf);
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) for (char d = c + 1; d <= 'z'; ++d) {
        int sum = 0;
        REP(i, n) {
            bool ok = true;
            for (char z : s[i]) if (z != c && z != d) {
                ok = false;
                break;
            }
            if (ok) sum += (int)s[i].length();
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}