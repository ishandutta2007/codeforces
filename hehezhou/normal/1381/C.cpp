#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010];
int b[100010];
vector < int > id[100010];
class cmp {
    public:
        inline int operator () (int a, int b) {
            return id[a].size() < id[b].size();
        }
};
int x, y, emp;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &x, &y);
        y -= x;
        for (int i = 1; i <= n + 1; i++) id[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", b + i), id[b[i]].push_back(i);
        for (int i = 1; i <= n + 1; i++) {
            if (id[i].empty()) {
                for (int j = 1; j <= n; j++) a[j] = i;
                emp = i;
                break;
            }
        }
        int l, r;
        l = 1;
        for (int i = 2; i <= n + 1; i++) if (id[i].size() > id[l].size()) l = i;
        r = l == 1 ? 2 : 1;
        while ((r < n + 1 && id[r].size() == 0) || l == r) r++;
        priority_queue < int, vector < int >, cmp > q;
        for (int i = 1; i <= n + 1; i++) q.push(i);
        if (y % 2 && id[l].size() + id[r].size() != n && y >= 3) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            int z = q.top();
            q.pop();
            a[id[x].back()] = y;
            a[id[y].back()] = z;
            a[id[z].back()] = x;
            id[x].pop_back();
            id[y].pop_back();
            id[z].pop_back();
            q.push(x);
            q.push(y);
            q.push(z);
            ::y -= 3;
        }
        int did = 1;
        for (int i = 1; i <= y; i += 2) {
            int x = q.top();
            q.pop();
            int z = q.top();
            q.pop();
            if (id[x].empty() || id[z].empty()) {
                puts("NO");
                goto tag;
            }
            a[id[x].back()] = z;
            a[id[z].back()] = i == y ? -1 : x;
            id[x].pop_back();
            id[z].pop_back();
            q.push(x), q.push(z);
        }
        for (int i = 1; i <= x; i++) {
            while (did <= n && a[did] != emp) did++;
            a[did] = b[did];
        }
        if (did == n + 1) {
            puts("NO");
            goto tag;
        }
        puts("YES");
        for (int i = 1; i <= n; i++) printf("%d%c", a[i] == -1 ? emp : a[i], " \n"[i == n]);
        tag:;
    }
}