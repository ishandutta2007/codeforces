#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n;
char s[maxn];

int main() {
    scanf("%d %s", &n, s + 1);
    int p = 1;
    while (s[p] == '<') p++;
    int ans = p - 1;
    p = n;
    while (s[p] == '>') p--;
    printf("%d\n", ans + n - p);
    return 0;
}