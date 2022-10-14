#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1111;

int n, k, a[N];

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    k --;
    while (a[k] == 0) {
        k = (k + 1) % n;
    }
    printf("%d\n", k + 1);
    return 0;
}