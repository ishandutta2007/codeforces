#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef pair<int, int> pii;

vector<pii> a, b;
int x, y, f = 1, n, m;

set<int> l1[15], l2[15], l;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if(x > y) swap(x, y);
        a.emplace_back(x, y);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        if(x > y) swap(x, y);
        b.emplace_back(x, y);
    }

    for(int i = 0; i < n; i++) {
        pii p = a[i];
        for(int j = 0; j < m; j++) {
            pii q = b[j];
            if(p == q) continue;

            if(p.first == q.first) {
                l1[i].insert(p.first);
                l2[j].insert(p.first);
                l.insert(p.first);
            } else if(p.first == q.second) {
                l1[i].insert(p.first);
                l2[j].insert(p.first);
                l.insert(p.first);
            } else if(p.second == q.first) {
                l1[i].insert(p.second);
                l2[j].insert(p.second);
                l.insert(p.second);
            } else if(p.second == q.second) {
                l1[i].insert(p.second);
                l2[j].insert(p.second);
                l.insert(p.second);
            }
        }
    }

    assert(l.size() > 0);
    f = *(l.begin());
    if(l.size() > 1) {
        f = 0;

        for(int i = 0; i < n; i++)
            if(l1[i].size() > 1)
                f = -1;

        for(int i = 0; i < m; i++)
            if(l2[i].size() > 1)
                f = -1;
    }

    printf("%d\n", f);
    return 0;
}