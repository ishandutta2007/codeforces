#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n;
pair<int, int> p[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (p[i].second >= cur) cur = p[i].second;
        else cur = p[i].first;
    }
    printf("%d\n", cur);
    return 0;
}