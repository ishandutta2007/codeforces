#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
const int MAXN = 200000;
const int MAXNODES = 4 * MAXN;
const int DIGITS = 10;

int best[2][DIGITS][1 + MAXNODES + 1];
int v[1 + MAXN];

void Make(int node, int x) {
    int cx = x;
    for (int i = 0; i < DIGITS; i++) {
        best[0][i][node] = best[1][i][node] = INF;
        if (x % 10 != 0)
            best[0][i][node] = cx;
        x /= 10;
    }
}

void Join(int node, int a, int b) {
    for (int i = 0; i < DIGITS; i++) {
        int a0 = best[0][i][a], a1 = best[1][i][a], b0 = best[0][i][b], b1 = best[1][i][b];
        if (a0 < b0) {
            best[0][i][node] = a0;
            best[1][i][node] = min(b0, min(a1, b1));
        }
        else {
            best[0][i][node] = b0;
            best[1][i][node] = min(a0, min(a1, b1));
        }
    }
}

void Build(int node, int left, int right) {
    if (left == right) {
        Make(node, v[left]);
        return;
    }
    int middle = (left + right) / 2;
    Build(2 * node, left, middle);
    Build(2 * node + 1, middle + 1, right);
    Join(node, 2 * node, 2 * node + 1);
}

void Update(int node, int left, int right, int where) {
    if (left == right) {
        Make(node, v[left]);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle, where);
    else
        Update(2 * node + 1, middle + 1, right, where);
    Join(node, 2 * node, 2 * node + 1);
}

void Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        Join(MAXNODES, MAXNODES, node);
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Query(2 * node, left, middle, from, to);
    if (middle + 1 <= to)
        Query(2 * node + 1, middle + 1, right, from, to);
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    Build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int type, a, b;
        scanf("%d%d%d", &type, &a, &b);
        if (type == 1) {
            v[a] = b;
            Update(1, 1, n, a);
        }
        else {
            int answer = 2 * INF;
            Make(MAXNODES, 0);
            Query(1, 1, n, a, b);
            for (int i = 0; i < DIGITS; i++)
                if (best[0][i][MAXNODES] != INF && best[1][i][MAXNODES] != INF)
                    answer = min(answer, best[0][i][MAXNODES] + best[1][i][MAXNODES]);
            if (answer == 2 * INF)
                answer = -1;
            printf("%d\n", answer);
        }
    }
    return 0;
}