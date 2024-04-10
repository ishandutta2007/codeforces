#include <cstdio>
//#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    long long k;
    scanf("%d%I64d", &n, &k);
    while (1) {
        if (n == 1) {
            printf("1\n");
            return 0;
        }
        if (k == (1LL << (n - 1))) {
            printf("%d\n", n);
            return 0;
        }
        if (k > (1LL << (n - 1)))
            k = k - (1LL << (n - 1));
        n--;
    }
    return 0;
}