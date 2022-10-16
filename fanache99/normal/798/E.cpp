#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;
const int MAXN = 500000;
const int MAXNODES = 1048576;

char buffer[SIZE];
int pointer = SIZE;

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

int n, a[1 + MAXN], b[1 + MAXN], order[1 + MAXN], answer[1 + MAXN];
pair<int, int> tree[1 + MAXNODES];
bool seen[1 + MAXN];

void BuildTree(int node, int left, int right) {
    if (left == right) {
        tree[node] = make_pair(b[left], left);
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int where;

void Update(int node, int left, int right) {
    if (left == right) {
        tree[node] = make_pair(0, left);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle);
    else
        Update(2 * node + 1, middle + 1, right);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int from, to;

pair<int, int> Query(int node, int left, int right) {
    if (from > to)
        return make_pair(0, 0);
    if (from <= left && right <= to)
        return tree[node];
    int middle = (left + right) / 2;
    pair<int, int> answer = make_pair(0, 0);
    if (from <= middle)
        answer = max(answer, Query(2 * node, left, middle));
    if (middle + 1 <= to)
        answer = max(answer, Query(2 * node + 1, middle + 1, right));
    return answer;
}

void DFS(int node) {
    where = node;
    Update(1, 1, n);
    seen[node] = true;
    if (b[node] != n + 1 && !seen[b[node]])
        DFS(b[node]);
    while (1) {
        from = 1;
        to = a[node] - 1;
        pair<int, int> current = Query(1, 1, n);
        if (current.first > node)
            DFS(current.second);
        else
            break;
    }
    order[0]++;
    order[order[0]] = node;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] != -1)
            b[a[i]] = i;
        else
            a[i] = n + 1;
    }
    for (int i = 1; i <= n; i++)
        if (!b[i])
            b[i] = n + 1;
    BuildTree(1, 1, n);
    for (int i = 1; i <= n; i++)
        if (!seen[i])
            DFS(i);
    for (int i = 1; i <= n; i++)
        answer[order[i]] = i;
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return  0;
}