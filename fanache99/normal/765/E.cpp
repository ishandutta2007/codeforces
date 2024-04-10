#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int MAXN = 200000;

vector<int> g[1 + MAXN];
int best;
int down[1 + MAXN], up[1 + MAXN], dad[1 + MAXN];
bool isDown[1 + MAXN], isUp[1 + MAXN];

void GetDown(int node, int father) {
    if (father && g[node].size() == 1) {
        down[node] = 1;
        isDown[node] = true;
        return;
    }
    int first = 0, second = 0, sons = 0, which;
    for (auto &son : g[node])
        if (son != father) {
            sons++;
            which = son;
            GetDown(son, node);
            if (down[son] == -1)
                down[node] = -1;
            else
                if (!first)
                    first = down[son];
                else
                    if (first != down[son])
                        second = down[son];
        }
    if (sons == 1) {
        if (isUp[node])
            isUp[which] = true;
        if (isDown[which])
            isDown[node] = true;
    }
    if (!down[node] && !second)
        down[node] = 1 + first;
    else
        down[node] = -1;
}

bool okLeft[1 + MAXN], okRight[1 + MAXN];

void GetUp(int node, int father) {
    dad[node] = father;
    for (int i = 0; i < g[node].size(); i++)
        if (g[node][i] == father) {
            swap(g[node][i], g[node].back());
            g[node].pop_back();
        }
    for (auto &son : g[node])
        up[son] = -1;
    if (!father || up[node] != -1)
        if (g[node].size() == 1)
            if (father)
                up[g[node][0]] = up[node] + 1;
            else
                up[g[node][0]] = 1;
        else {
            okLeft[0] = true;
            for (int i = 1; i < g[node].size(); i++)
                if (!okLeft[i - 1] || down[g[node][i - 1]] == -1 || (i != 1 && down[g[node][i - 1]] != down[g[node][i - 2]]))
                    okLeft[i] = false;
                else
                    okLeft[i] = true;
            okRight[g[node].size() - 1]= true;
            for (int i = g[node].size() - 2; i >= 0; i--)
                if (!okRight[i + 1] || down[g[node][i + 1]] == -1 || (i != g[node].size() - 2 && down[g[node][i + 1]] != down[g[node][i + 2]]))
                    okRight[i] = false;
                else
                    okRight[i] = true;
            for (int i = 0; i < g[node].size(); i++)
                if (okLeft[i] && okRight[i])
                    if (i == 0 || i == g[node].size() - 1 || down[g[node][i - 1]] == down[g[node][i + 1]])
                        if (!father || ((i == 0 || up[node] == down[g[node][i - 1]]) && (i == g[node].size() - 1 || up[node] == down[g[node][i + 1]])))
                            if (father)
                                up[g[node][i]] = up[node] + 1;
                            else
                                if (i == 0)
                                    up[g[node][i]] = down[g[node][1]] + 1;
                                else
                                    up[g[node][i]] = down[g[node][0]] + 1;
        }
    for (auto &son : g[node])
        GetUp(son, node);
}

void Try(int node) {
    if (node != 1 && up[node] == -1)
        return;
    int first = 0, second = 0, third = 0;
    if (node != 1)
        first = up[node];
    for (auto &son : g[node]) {
        if (down[son] == -1)
            return;
        if (!first)
            first = down[son];
        else
            if (first != down[son])
                if (!second)
                    second = down[son];
                else
                    if (second != down[son])
                        third = down[son];
    }
    if (third)
        return;
    int x = first + second;
    while (x % 2 == 0)
        x /= 2;
    best = min(best, x);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    isUp[1] = true;
    GetDown(1, 0);
    GetUp(1, 0);
    best = n + 1;
    for (int i = 1; i <= n; i++)
        Try(i);
    if (best == n + 1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", best);
    return 0;
}