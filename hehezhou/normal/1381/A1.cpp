#include <bits/stdc++.h>
using namespace std;
int t, n;
char a[100010], b[100010];
int tag[100010];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s%s", a, b);
        vector < int > ans;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i -= 2) {
            if (a[i] == b[cnt]) tag[i] = 1;
            else tag[i] = 0;
            cnt++;
        }
        for (int i = n & 1; i < n; i += 2) {
            if (a[i] != b[cnt]) tag[i] = 1;
            else tag[i] = 0;
            cnt++;
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(i + 1);
            if (tag[i]) ans.push_back(1);
        }
        printf("%d ", ans.size());
        for (auto i : ans) printf("%d ", i);
        puts("");
    }
}