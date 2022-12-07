#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define pb push_back
#define mp make_pair

int tt;
int n, r, sum;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &tt);
    for (int test = 0; test < tt; ++test) {
        scanf("%d%d", &n, &r), --r;
        int sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x;
            scanf("%d", &x), --x;
            sum = (sum + n - x) % n;
        }
        printf("%d\n", (sum + r) % n + 1);
    }
    return 0;
}