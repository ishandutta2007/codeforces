#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn], a[maxn], b[maxn], nxt[30][maxn];
bool mark[maxn], ban[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), mark[p[i]] = 1;
        nxt[0][i] = p[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int num = count(mark + 1, mark + n + 1, 0);
    int turn = (*max_element(a + 1, a + n + 1) - n) / num;
    for (int k = 1; k < 30; k++) {
        for (int i = 1; i <= n; i++) {
            nxt[k][i] = nxt[k - 1][nxt[k - 1][i]];
        }
    }
    for (int i = n; i; i--) {
        b[i] = i;
        for (int k = 29; ~k; k--) {
            if (turn >> k & 1) b[i] = nxt[k][b[i]];
        }
        V[b[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!V[i].empty()) ban[a[i]] = 1;
    }
    set<int> cand;
    for (int i = 1; i <= n; i++) {
        if (!ban[i]) cand.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (V[b[i]].empty()) {
            int x = *cand.lower_bound(a[b[i]]);
            printf("%d ", x), cand.erase(x);
        } else {
            printf("%d ", a[b[i]]), V[b[i]].clear();
        }
    }
    return 0;
}