#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 500000;
const int LIMIT = 2000000000;

long long tree[1 + 4 * MAXN], lazy[1 + 4 * MAXN];
int where[1 + 4 * MAXN];

struct Point {
    int x;
    int y;
    int c;
    int where;

    int Max() {
        return max(x, y);
    }

    int Min() {
        return min(x, y);
    }
};

Point v[1 + MAXN];
long long sum[1 + MAXN];
int length[1 + MAXN];
long long answer = 0;
int x1 = LIMIT, y1 = LIMIT, x2 = LIMIT, y2 = LIMIT;

inline bool CompareMax(Point a, Point b) {
    return a.Max() < b.Max();
}

inline bool CompareMin(Point a, Point b) {
    return a.Min() < b.Min();
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        tree[node] = sum[left] - length[left];
        where[node] = length[left];
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    if (tree[2 * node] > tree[2 * node + 1]) {
        tree[node] = tree[2 * node];
        where[node] = where[2 * node];
    }
    else {
        tree[node] = tree[2 * node + 1];
        where[node] = where[2 * node + 1];
    }
}

void Propagate(int node) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void Update(int node, int left, int right, int from, int to, int add) {
    if (from <= left && right <= to) {
        lazy[node] += add;
        return;
    }
    int middle = (left + right) / 2;
    Propagate(node);
    if (from <= middle)
        Update(2 * node, left, middle, from, to, add);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right, from, to, add);
    if (tree[2 * node] + lazy[2 * node] > tree[2 * node + 1] + lazy[2 * node + 1]) {
        tree[node] = tree[2 * node] + lazy[2 * node];
        where[node] = where[2 * node];
    }
    else {
        tree[node] = tree[2 * node + 1] + lazy[2 * node + 1];
        where[node] = where[2 * node + 1];
    }
}

void Query(int node, int left, int right, int limit) {
    if (length[right] < limit)
        return;
    if (length[left] >= limit) {
        if (tree[node] + lazy[node] > answer) {
            answer = tree[node] + lazy[node];
            x1 = y1 = limit;
            x2 = y2 = where[node];
        }
        return;
    }
    Propagate(node);
    int middle = (left + right) / 2;
    Query(2 * node, left, middle, limit);
    Query(2 * node + 1, middle + 1, right, limit);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].c);
    sort(v + 1, v + n + 1, CompareMax);
    int nodes = 0;
    for (int i = 1, j; i <= n; i = j) {
        nodes++;
        sum[nodes] = sum[nodes - 1];
        length[nodes] = v[i].Max();
        j = i;
        while (j <= n && v[j].Max() == v[i].Max()) {
            sum[nodes] += v[j].c;
            v[j].where = nodes;
            j++;
        }
    }
    BuildTree(1, 1, nodes);
    sort(v + 1, v + n + 1, CompareMin);
    int before = 0;
    for (int i = 1, j; i <= n; i = j) {
        Update(1, 1, nodes, 1, nodes, v[i].Min() - before);
        Query(1, 1, nodes, v[i].Min());
        j = i;
        while (j <= n && v[j].Min() == v[i].Min()) {
            Update(1, 1, nodes, v[j].where, nodes, -v[j].c);
            j++;
        }
        before = v[i].Min();
    }
    printf("%I64d\n%d %d %d %d\n", answer, x1, y1, x2, y2);
    return 0;
}