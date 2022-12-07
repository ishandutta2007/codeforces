#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[200005];
char to[26], a, b;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    REP(i, 26) to[i] = 'a' + i;
    REP(i, m) {
        scanf(" %c %c", &a, &b);
        int x = -1, y = -1;
        REP(j, 26) {
            if (to[j] == a) x = j;
            if (to[j] == b) y = j;
        }
        swap(to[x], to[y]);
    }
    REP(i, n) s[i] = to[s[i] - 'a'];
    printf("%s\n", s);
    return 0;
}