#include <stdio.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    printf("%d\n", ((n - 2) / k + 1) * 2 - ((n - 2) % k == 0));
    for (int i = 1; i < n; ++i) printf("%d %d\n", i, i + k > n ? n : i + k);
    return 0;
}