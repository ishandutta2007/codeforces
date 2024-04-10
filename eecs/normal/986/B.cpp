#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, c[maxn];

void add(int p) {
    for (; p <= n; p += p & -p) c[p]++;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &n);
    long long cnt = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        cnt += i - 1 - sum(x), add(x);
    }
    if (cnt % 2 == 3 * n % 2) puts("Petr");
    else puts("Um_nik");
    return 0;
}