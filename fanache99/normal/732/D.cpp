#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int last[1 + MAXN];
int order[1 + MAXN];
int required[1 + MAXN];
int v[1 + MAXN];

bool Compare(const int &a, const int &b) {
    return last[a] < last[b];
}

bool Check(int n, int m) {
    int remaining = 0;
    for (int i = 1; i <= m; i++) {
        last[i] = 0;
        order[i] = i;
    }
    for (int i = 1; i <= n; i++)
        last[v[i]] = i;
    last[0] = 0;
    sort(order + 1, order + m + 1, Compare);
    for (int i = 1; i <= m; i++) {
        if (last[order[i]] == 0)
            return false;
        remaining = remaining + last[order[i]] - last[order[i - 1]] - 1;
        if (remaining < required[order[i]])
            return false;
        remaining -= required[order[i]];
    }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &required[i]);
    int left = 1, right = n, answer = -1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (Check(middle, m)) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    printf("%d\n", answer);
    return 0;
}