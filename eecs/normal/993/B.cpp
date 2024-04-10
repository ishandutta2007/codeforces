#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int, int> p1[15], p2[15];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p1[i].first, &p1[i].second);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &p2[i].first, &p2[i].second);
    }
    int cnt = 0, num;
    bool flag = 1;
    set<int> S;
    for (int i = 1; i <= n; i++) {
        set<int> T;
        for (int j = 1; j <= m; j++) {
            int c = (p1[i].first == p2[j].first) + (p1[i].second == p2[j].first)
                + (p1[i].first == p2[j].second) + (p1[i].second == p2[j].second);
            if (c ^ 1) continue;
            if (p1[i].first == p2[j].first || p1[i].second == p2[j].first) num = p2[j].first;
            else num = p2[j].second;
            cnt++, S.insert(num), T.insert(num);
        }
        flag &= (T.size() <= 1);
    }
    for (int i = 1; i <= m; i++) {
        set<int> T;
        for (int j = 1; j <= n; j++) {
            int c = (p2[i].first == p1[j].first) + (p2[i].second == p1[j].first)
                + (p2[i].first == p1[j].second) + (p2[i].second == p1[j].second);
            if (c ^ 1) continue;
            if (p2[i].first == p1[j].first || p2[i].second == p1[j].first) num = p1[j].first;
            else num = p1[j].second;
            T.insert(num);
        }
        flag &= (T.size() <= 1);
    }
    if (S.size() == 1) printf("%d\n", num);
    else if (flag) puts("0");
    else puts("-1");
    return 0;
}