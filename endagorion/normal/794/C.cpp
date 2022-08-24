#include <bits/stdc++.h>
char a[300001], b[300001], *t[] = {gets(a), gets(b)};
int n = strlen(a), p[] = {n & 1, 1};

int main() {
    std::sort(a, a + n), std::sort(b, b + n, std::greater<char>());
    while (n--) putchar(*t[p[*t[0] < *t[1]] ^= 1]++);
}