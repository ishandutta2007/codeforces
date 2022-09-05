#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, a[maxn], b[maxn];
char s[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%s", s + 1);
    sort(a + 1, a + n + 1);
    int l = 1, r = n;
    for (int i = n; i; i--) {
        if (s[i] == s[i - 1]) b[i] = l++;
        else b[i] = r--;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %c\n", a[b[i]], (b[i] & 1) ^ (n & 1) ^ (s[n] == 'R') ? 'R' : 'L');
    }
    return 0;
}