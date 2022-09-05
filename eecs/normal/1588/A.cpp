#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        multiset<int> S;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), S.insert(a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        sort(b + 1, b + n + 1);
        bool flag = 1;
        for (int i = n; i; i--) {
            if (S.count(b[i])) S.erase(S.find(b[i]));
            else if (S.count(b[i] - 1)) S.erase(S.find(b[i] - 1));
            else flag = 0;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}