#include <cstdio>

int main()
{
    int s;
    scanf("%d", &s);
    int len = 2;
    while ((len >> 1) * (len + 1 >> 1) < s) {
        len ++;
    }
    printf("%d\n", len << 1);
}