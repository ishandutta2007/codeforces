#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n;
char s[maxn], t[maxn], tmp[maxn];
vector<int> ans;

void move(int x) {
    if (x == 1) return;
    ans.push_back(n);
    ans.push_back(x - 1);
    ans.push_back(1);
    tmp[1] = s[x];
    for (int i = 1; i < x; i++) tmp[i + 1] = s[i];
    for (int i = x + 1; i <= n; i++) tmp[i] = s[i];
    reverse(tmp + x + 1, tmp + n + 1);
    for (int i = 1; i <= n; i++) s[i] = tmp[i];
}

int main() {
    scanf("%d %s %s", &n, s + 1, t + 1);
    for (int i = n; i; i--) {
        bool flag = 0;
        for (int j = n - i + 1; j <= n; j++) {
            if (s[j] == t[i]) {
                flag = 1, move(j); break;
            }
        }
        if (!flag) printf("-1\n"), exit(0);
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}