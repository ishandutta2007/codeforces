#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, ans, cnt[26];
char s[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        cnt[s[i] - 'A']++;
    }
    int num = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == *max_element(cnt, cnt + 26)) num++;
    }
    printf("%d\n", qp(num, n));
    return 0;
}