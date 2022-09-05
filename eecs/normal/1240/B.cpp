#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, a[maxn], val[maxn];
bool mark[maxn], _mark[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            V[i].clear(), mark[i] = _mark[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), V[a[i]].push_back(i);
        }
        vector<int> num;
        for (int i = 1; i <= n; i++) if (!V[i].empty()) {
            num.push_back(i);
            mark[V[i][0]] = _mark[V[i].back()] = 1;
        }
        int ans = 0;
        for (int i = 0, j; i < num.size(); i = j) {
            for (j = i + 1; j < num.size() && V[num[j - 1]].back() < V[num[j]][0]; j++);
            ans = max(ans, j - i);
        }
        printf("%d\n", num.size() - ans);
    }
    return 0;
}