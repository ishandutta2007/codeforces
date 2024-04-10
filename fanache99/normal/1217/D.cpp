#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;
const int MAXM = 5000;

pair<int, int> edge[1 + MAXM];
vector<int> g[1 + MAXN];
int inDegree[1 + MAXN], Queue[1 + MAXN];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        edge[i] = make_pair(a, b);
        inDegree[b]++;
    }
    int start = 1, finish = 0;
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0) {
            finish++;
            Queue[finish] = i;
        }
    while (start <= finish) {
        int node = Queue[start];
        start++;
        for (auto &it : g[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                finish++;
                Queue[finish] = it;
            }
        }
    }
    if (finish == n) {
        printf("1\n");
        for (int i = 1; i <= m; i++)
            printf("1 ");
    }
    else {
        printf("2\n");
        for (int i = 1; i <= m; i++)
            if (edge[i].first < edge[i].second)
                printf("1 ");
            else
                printf("2 ");
    }
    return 0;
}