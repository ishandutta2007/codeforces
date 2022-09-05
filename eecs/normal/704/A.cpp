#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, tot, ans;
set<int> S[maxn];
vector<int> V;

int main() {
    scanf("%d %d", &n, &q);
    int lst = 0;
    while (q--) {
        int op, x;
        scanf("%d %d", &op, &x);
        if (op == 1) {
            S[x].insert(++tot), ans++;
            V.push_back(x);
        } else if (op == 2) {
            ans -= S[x].size(), S[x].clear();
        } else if (op == 3 && x > lst) {
            for (int i = lst; i < x; i++) {
                if (S[V[i]].count(i + 1)) S[V[i]].erase(i + 1), ans--;
            }
            lst = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}