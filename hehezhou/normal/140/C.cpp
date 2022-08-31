#include <bits/stdc++.h>
using namespace std;
priority_queue < pair < int, int > > q;
int n, a[100010];
pair < int, int > tmp[3];
int ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        int now = 1;
        while (i < n && a[i + 1] == a[i]) now++, i++;
        q.push({now, a[i]});
    }
    while (q.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            a[ans * 3 + i] = q.top().second;
            tmp[i] = q.top();
            q.pop();
        }
        sort(a + ans * 3, a + ans * 3 + 3);
        reverse(a + ans * 3, a + ans * 3 + 3);
        ans++;
        for (int i = 0; i < 3; i++) if (tmp[i].first > 1) q.push({tmp[i].first - 1, tmp[i].second});
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans * 3; i++) {
        printf("%d%c", a[i], " \n"[i % 3 == 2]);
    }
}