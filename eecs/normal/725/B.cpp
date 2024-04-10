#include <bits/stdc++.h>
using namespace std;

int num[6] = {4, 5, 6, 3, 2, 1};

int main() {
    long long n = 0;
    char ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    long long ans = (n - 1) / 4 * (4 + 2 * 6);
    if (n % 4 == 1) {
        ans += num[ch - 'a'];
    } else if (n % 4 == 2) {
        ans += 7 + num[ch - 'a'];
    } else if (n % 4 == 3) {
        ans += num[ch - 'a'];
    } else {
        ans += 7 + num[ch - 'a'];
    }
    printf("%lld\n", ans);
    return 0;
}