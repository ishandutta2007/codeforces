#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, b[N], a[N];
inline void Gen(int b1, int b2, int b3) {
    a[1] = (b3 - b2 + b1) / 2;
    a[2] = b1 - a[1];
    a[3] = b2 - a[2];
    // assert(a[3] + a[1] == b[3]);
}
inline void Finish() {
    puts("YES");
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    puts("");
    exit(0);
}
set<int> st;
int flag, vis[N], flagnum;
inline void Dfs1(int x, int rm, int sm) {
    if (!rm) {
        if (st.count(sm)) flag = sm;
        st.insert(sm);
        return;
    }
    if (x > n) return;
    if (!flag) Dfs1(x + 1, rm - 1, sm + b[x]);
    if (!flag) Dfs1(x + 1, rm, sm);
}
vector<int> cho[2];
inline void Dfs2(int x, int rm, int sm) {
    if (!rm) {
        if (sm == flag) {
            for (int i = 1; i <= n; ++i) if (vis[i]) cho[flagnum].push_back(i);
            ++flagnum;
        }
        return;
    }
    if (x > n) return;
    if (flagnum < 2) { vis[x] = 1; Dfs2(x + 1, rm - 1, sm + b[x]); vis[x] = 0; }
    if (flagnum < 2) Dfs2(x + 1, rm, sm);
}
int main() {
    // int seed;
    // srand(seed = time(0));
    scanf("%d", &n);
    // n = 20;
    vector<int> g[2];
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
        // while ((b[i] = rand() % (int)1e6) % 2 == 0);
        // if (rand() % 20 == 0) b[i] = rand() % (int)1e6;
        // printf("%d ", b[i]);
        g[b[i] & 1].push_back(b[i]);
    }
    // puts("");
    int cnt = g[0].size();
    if (n == 3) {
        if (cnt == 1 || cnt == 3) {
            Gen(b[1], b[2], b[3]);
            Finish();
        }
    } else if (n > 3) {
        if (cnt >= 1) {
            if (cnt >= 3) {
                Gen(g[0][0], g[0][1], g[0][2]);
                int tot = 3;
                for (int i = 3; i < g[0].size(); ++i) a[++tot] = g[0][i] - a[1];
                for (auto x: g[1]) a[++tot] = x - a[1];
            } else {
                Gen(g[0][0], g[1][0], g[1][1]);
                int tot = 3;
                for (int i = 1; i < g[0].size(); ++i) a[++tot] = g[0][i] - a[1];
                for (int i = 2; i < g[1].size(); ++i) a[++tot] = g[1][i] - a[1];
            }
            Finish();
        }
    }
    for (int i = 1; i <= n / 2; ++i) {
        st.clear();
        // cerr << "!! " << i << endl;
        Dfs1(1, i, 0);
        if (flag) {
            Dfs2(1, i, 0);
            for (auto x: cho[0]) vis[x] = 1;
            for (auto x: cho[1]) vis[x] = 1;
            a[1] = 0;
            int tot = 1;
            for (int i = 0; i < cho[0].size(); ++i) {
                a[tot + 1] = b[cho[0][i]] - a[tot];
                ++tot;
                a[tot + 1] = b[cho[1][i]] - a[tot];
                ++tot;
            }
            --tot;
            for (int i = 1; i <= n; ++i) if (!vis[i]) a[++tot] = b[i] - a[1];
            Finish();
        }
    }
    puts("NO");
    return 0;
}