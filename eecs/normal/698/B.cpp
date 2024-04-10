#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, tim, vis[maxn], a[maxn];
vector<vector<int>> cyc;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        tim++;
        bool flag = 1;
        vector<int> V;
        vector<int> C;
        for (int j = i; j; j = a[j]) {
            if (vis[j] == tim) {
                for (int k = 0; k < V.size(); k++) if (j == V[k]) {
                    for (int l = k; l < V.size(); l++) C.push_back(V[l]);
                    break;
                }
                cyc.push_back(C); break;
            }
            if (vis[j]) break;
            vis[j] = tim, V.push_back(j);
        }
    }
    bool flag = 0;
    for (auto &V : cyc) {
        if (V.size() == 1) { flag = 1; break; }
    }
    if (!flag) {
        printf("%d\n", cyc.size());
        for (int i = 0; i + 1 < cyc.size(); i++) {
            a[cyc[i][0]] = cyc[i + 1][0];
        }
        a[cyc.back()[0]] = cyc.back()[0];
    } else {
        printf("%d\n", cyc.size() - 1);
        for (int i = 0; i < cyc.size(); i++) if (cyc[i].size() == 1) {
            for (int j = 0; j < cyc.size(); j++) if (i ^ j) {
                a[cyc[j][0]] = cyc[i][0];
            }
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}