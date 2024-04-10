#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn], res[maxn];
vector<int> pos[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            pos[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), pos[a[i]].push_back(i);
        }
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            if (!pos[i].empty()) V.push_back(i);
        }
        sort(V.begin(), V.end(), [&](int i, int j) {
            return pos[i].size() < pos[j].size();
        });
        for (int i = 0; i < V.size(); i++) if (!pos[V[i]].empty()) {
            int t = pos[V[i]].size();
            for (int k = 0; k < t; k++) {
                for (int l = i; l + 1 < V.size(); l++) {
                    res[pos[V[l]].back()] = V[l + 1];
                }
                res[pos[V.back()].back()] = V[i];
                for (int l = i; l< V.size(); l++) {
                    pos[V[l]].pop_back();
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d ", res[i]);
        }
        putchar('\n');
    }
    return 0;
}