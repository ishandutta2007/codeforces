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
    for (int i = 0; ; ++i) {
        int x = c - i * a;
        if (x < 0) break;
        if (x % b == 0) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}