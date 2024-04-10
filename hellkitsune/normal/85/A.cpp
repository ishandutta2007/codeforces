#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[4][105];

int main() {
    scanf("%d", &n);
    REP(i, 4) s[i][n] = '\0';
    if (n % 2 == 1) {
        s[0][0] = s[1][0] = 'a';
        char c = 'b';
        for (int i = 1; i < n; i += 2) {
            s[0][i] = s[0][i + 1] = c;
            s[1][i] = s[1][i + 1] = c + 1;
            if (c == 'b') c = 'd';
            else c = 'b';
        }
        c = 'f';
        for (int i = 0; i < n - 1; i += 2) {
            s[2][i] = s[2][i + 1] = c;
            s[3][i] = s[3][i + 1] = c + 1;
            if (c == 'f') c = 'h';
            else c = 'f';
        }
        s[2][n - 1] = s[3][n - 1] = 'j';
    } else {
        char c = 'a';
        for (int i = 0; i < n; i += 2) {
            s[0][i] = s[0][i + 1] = s[3][i] = s[3][i + 1] = c;
            if (c == 'a') c = 'b';
            else c = 'a';
        }
        s[1][0] = s[2][0] = 'c';
        s[1][n - 1] = s[2][n - 1] = 'd';
        c = 'e';
        for (int i = 1; i < n - 1; i += 2) {
            s[1][i] = s[1][i + 1] = c;
            s[2][i] = s[2][i + 1] = c + 1;
            if (c == 'e') c = 'g';
            else c = 'e';
        }
    }
    REP(i, 4) printf("%s\n", s[i]);
    return 0;
}