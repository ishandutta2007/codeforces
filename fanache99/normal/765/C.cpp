#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    if (a < k && b < k) {
        printf("-1\n");
        return 0;
    }
    if (a < k && b % k) {
        printf("-1\n");
        return 0;
    }
    if (b < k && a % k) {
        printf("-1\n");
        return 0;
    }
    int answer = a / k + b / k;
    printf("%d\n", answer);
    return 0;
}