#include <cstdio>
#include <cstring>

using namespace std;

int n, k;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int res = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        int ai;
        scanf("%d", &ai);
        if (ai >= 3 * k) {
            res += ai - 3 * k;
        } else {
            res += ai % k;
        }
    }
    printf("%d\n", res);
    return 0;
}