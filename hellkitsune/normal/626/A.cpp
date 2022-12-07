#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[205];
int x, y;

int main() {
    scanf("%d%s", &n, s);
    int ans = 0;
    REP(i, n) {
        x = y = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == 'D') ++y;
            else if (s[j] == 'U') --y;
            else if (s[j] == 'R') ++x;
            else --x;
            if (x == 0 && y == 0) {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}