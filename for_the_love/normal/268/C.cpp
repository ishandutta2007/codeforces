#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, i;
int main(){
    scanf("%d%d", &n, &m);
    n = min(n, m);
    printf("%d\n", n + 1);
    for (i = 0; i <= n; i++)
        printf("%d %d\n", i, n - i);
}