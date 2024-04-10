#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int t, n, ans, a[MN], dp[MN][2][2][2][2], seen[MN][2][2][2][2], cnt = 1;
char s[MN];

int ok(int a, int b, int c) {
    return (a != b) || (a != c) || (b != c);
}

int solve(int pos, int fst, int snd, int penult, int ult) {
    if(pos == n) return ((ok(penult, ult, fst) && ok(ult, fst, snd)) ? 0 : MN);

    int &x = dp[pos][fst][snd][penult][ult];
    if(seen[pos][fst][snd][penult][ult] == cnt) return x;
    seen[pos][fst][snd][penult][ult] = cnt;
    x = MN;

    if(ok(penult, ult, 0)) x = min(x, solve(pos + 1, fst, snd, ult, 0) + (s[pos] != 'R'));
    if(ok(penult, ult, 1)) x = min(x, solve(pos + 1, fst, snd, ult, 1) + (s[pos] != 'L'));

    return x;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %s", &n, s);

        if(n == 3) {
            if(s[0] == s[1] && s[1] == s[2]) puts("1");
            else puts("0");
            continue;
        }

        ans = MN;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                int tmp = 0;
                if((i == 0 && s[0] == 'L') || (i == 1 && s[0] == 'R')) tmp++;
                if((j == 0 && s[1] == 'L') || (j == 1 && s[1] == 'R')) tmp++;
                cnt++;
                ans = min(ans, solve(2, i, j, i, j) + tmp);
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}