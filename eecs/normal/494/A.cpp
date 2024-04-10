#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n;
char s[maxn];
vector<int> ans;

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') c0++;
        if (s[i] == ')') c1++;
        if (s[i] == '#') c1++, ans.push_back(1);
        if (c0 < c1) puts("-1"), exit(0);
    }
    if (c0 > c1) {
        if (ans.empty()) puts("-1"), exit(0);
        ans.back() += c0 - c1;
    }
    c0 = 0, c1 = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        if (s[i] == '(') c0++;
        if (s[i] == ')') c1++;
        if (s[i] == '#') c1 += ans[j++];
        if (c0 < c1) puts("-1"), exit(0);
    }
    assert(c0 == c1);
    for (int x : ans) printf("%d\n", x);
    return 0;
}