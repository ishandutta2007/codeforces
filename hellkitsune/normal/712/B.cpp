#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[100005];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    if (n % 2 == 1) {
        printf("-1\n");
        return 0;
    }
    int ud = 0, lr = 0;
    forn(i, n) if (s[i] == 'U') {
        ++ud;
    } else if (s[i] == 'D') {
        --ud;
    } else if (s[i] == 'R') {
        ++lr;
    } else {
        --lr;
    }
    printf("%d\n", (abs(ud) + abs(lr)) / 2);
    return 0;
}