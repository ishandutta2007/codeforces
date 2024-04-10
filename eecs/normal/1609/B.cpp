#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, ans;
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &q, s + 1);
    auto query = [&](int i) {
        return i >= 1 && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c';
    };
    for (int i = 1; i <= n - 2; i++) {
        ans += query(i);
    }
    while (q--) {
        int i;
        char c[2];
        scanf("%d %s", &i, c);
        ans -= query(i) + query(i - 1) + query(i - 2);
        s[i] = c[0];
        ans += query(i) + query(i - 1) + query(i - 2);
        printf("%d\n", ans);
    }
    return 0;
}