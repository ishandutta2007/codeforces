#include <bits/stdc++.h>
using namespace std;
int n;
char s[200010];
vector < int > a[30];
int ans[200010];
int main() {
    scanf("%d%s", &n, s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        int t = -1;
        for (int j = c; j >= 0; j--) {
            if (a[j].size()) {
                t = a[j].back();
                a[j].pop_back();
                break;
            }
        }
        if (t == -1) t = ++cnt;
        a[c].push_back(ans[i] = t);
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++) {
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
}