#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
int a[200010];
void rmain() {
    vector < pair < int, int > > ans1;
    vector < int > ans2;
    map < int, int > qwq;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        qwq[a[i]]++;
    }
    for (auto i : qwq) if (i.second % 2) {
        puts("-1");
        return;
    }
    int len = 0;
    auto doit = [&](int l, int r) {
        len += r - l + 1;
        for (int i = l; i <= r; i++) {
            ans1.emplace_back(len + i - l, a[i]);
        }
        ans2.push_back(2 * (r - l + 1));
        len += r - l + 1;
        reverse(a + l, a + r + 1);
    };
    for (int i = 1; i <= n; i += 2) {
        for (int j = i + 1; j <= n; j++) if (a[i] == a[j]) {
            doit(i, j - 1);
            doit(i, j);
            ans2.push_back(2);
            len += 2;
            break;
        }
    }
    printf("%d\n", (int)ans1.size());
    for (auto i : ans1) printf("%d %d\n", i.first, i.second);
    printf("%d\n", (int)ans2.size());
    for (auto i : ans2) printf("%d ", i);
    puts("");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}