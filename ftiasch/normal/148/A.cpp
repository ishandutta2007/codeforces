#include <cstdio>
using namespace std;

int a, b, c, d, n;

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    int result = 0;
    for (int i = 1; i <= n; ++ i) {
        result += i % a == 0 
            || i % b == 0
            || i % c == 0
            || i % d == 0;
    }
    printf("%d\n", result);
    return 0;
}