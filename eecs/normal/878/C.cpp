#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int n, K;

struct node {
    int mx[10], mn[10], sz;
    bool operator < (const node &o) const {
        for (int i = 0; i < K; i++) {
            if (mx[i] > o.mn[i]) return 0;
        }
        return 1;
    }
};
set<node> S;

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        node a;
        for (int j = 0; j < K; j++) {
            scanf("%d", &a.mx[j]), a.mn[j] = a.mx[j];
        }
        a.sz = 1;
        auto it1 = S.lower_bound(a), it2 = S.upper_bound(a);
        while (it1 != it2) {
            a.sz += it1->sz;
            for (int j = 0; j < K; j++) {
                a.mx[j] = max(a.mx[j], it1->mx[j]);
                a.mn[j] = min(a.mn[j], it1->mn[j]);
            }
            S.erase(it1++);
        }
        S.insert(a);
        printf("%d\n", S.rbegin()->sz);
    }
    return 0;
}