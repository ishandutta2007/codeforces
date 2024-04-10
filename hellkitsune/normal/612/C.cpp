#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
char s[1000005], t[1000005];
int ans = 0;

int main() {
    scanf("%s", s);
    n = strlen(s);
    m = 0;
    REP(i, n) if (s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<') {
        t[m++] = s[i];
    } else {
        if (m == 0) {
            printf("Impossible\n");
            return 0;
        }
        char a = t[m - 1];
        char b = s[i];
        if (b == '}') b = '{';
        if (b == ')') b = '(';
        if (b == ']') b = '[';
        if (b == '>') b = '<';
        if (a != b) ++ans;
        --m;
    }
    if (m != 0) printf("Impossible\n");
    else printf("%d\n", ans);
    return 0;
}