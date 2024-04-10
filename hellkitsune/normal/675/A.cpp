#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

int main() {
    scanf("%d%d%d", &a, &b, &c);
    if (b == a) {
        printf("YES\n");
    } else if (c == 0) {
        printf("NO\n");
    } else if ((c > 0 && b < a) || (c < 0 && b > a)) {
        printf("NO\n");
    } else if (abs(b - a) % abs(c) != 0) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}