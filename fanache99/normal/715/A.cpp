#include <cstdio>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long n;
    scanf("%I64d", &n);
    printf("2\n");
    for (long long i = 2; i <= n; i++)
        printf("%I64d\n", (i + 1) * (i + 1) * i - (i - 1));
    return 0;
}