#include <cstdio>
//#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int a = 1, b = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            a = i;
            b = n / i;
        }
    printf("%d %d\n", a, b);
    return 0;
}