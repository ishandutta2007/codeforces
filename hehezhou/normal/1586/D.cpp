#include <bits/stdc++.h>
using namespace std;
int n, ans[110];
int qwq;
inline int query(vector < int > a) {
    for (auto i : a) if (i > n) return 0;
    printf("?");
    for (auto i : a) printf(" %d", i);
    puts("");
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}
int main() {
    scanf("%d", &n);
    qwq = n + 1;
    vector < int > a(n, 1), b;
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i]) continue;
        vector < int > cur = {i};
        b = a;
        int tmp;
        while (b[i]++, tmp = query(b), tmp != 0 && tmp != i + 1) cur.push_back(tmp - 1);
        for (int i = cur.size(); i --> 0; ) ans[cur[i]] = --qwq;
    }
    printf("!");
    for (int i = 0; i < n; i++) printf(" %d", ans[i]);
    puts("");
}