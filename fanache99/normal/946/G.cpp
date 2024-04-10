#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

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

const int MAXN = 200000;
const int MAXNODES = 1048576;

pair<int, int> vn[1 + 2 * MAXN];
priority_queue<pair<int, int> > Heap[1 + 2 * MAXN];
int v[1 + MAXN], preffix[1 + MAXN], suffix[1 + MAXN], initial[1 + MAXN], start[1 + MAXN], finish[1 + MAXN];
int tree[1 + MAXNODES], toLeft[1 + MAXNODES], toRight[1 + MAXNODES], best[1 + MAXNODES];
bool out[1 + MAXN];

void Normalize(int n) {
    for (int i = 1; i <= n; i++)
        vn[i] = make_pair(v[i] - i, i);
    sort(vn + 1, vn + n + 1);
    int number = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1 || vn[i].first != vn[i - 1].first)
            number++;
        v[vn[i].second] = number;
    }
}

void NormalizeBoth(int n) {
    for (int i = 1; i <= n; i++) {
        vn[2 * i - 1] = make_pair(v[i] - i, i);
        vn[2 * i] = make_pair(v[i] - i + 2, i);
    }
    sort(vn + 1, vn + 2 * n + 1);
    int number = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (i == 1 || vn[i].first != vn[i - 1].first)
            number++;
        if (vn[i].first == v[vn[i].second] - vn[i].second)
            start[vn[i].second] = number;
        else
            finish[vn[i].second] = number;
    }
}

void Update(int node, int left, int right, int where, int value) {
    if (left == right) {
        tree[node] = max(tree[node], value);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        Update(2 * node, left, middle, where, value);
    else
        Update(2 * node + 1, middle + 1, right, where, value);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int Query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to)
        return tree[node];
    int middle = (left + right) / 2, answer = 0;
    if (from <= middle)
        answer = max(answer, Query(2 * node, left, middle, from, to));
    if (middle + 1 <= to)
        answer = max(answer, Query(2 * node + 1, middle + 1, right, from, to));
    return answer;
}

void Merge(int node) {
    best[node] = max(best[2 * node], max(best[2 * node + 1], toLeft[2 * node] + toRight[2 * node + 1]));
    toRight[node] = max(toRight[2 * node], toRight[2 * node + 1]);
    toLeft[node] = max(toLeft[2 * node], toLeft[2 * node + 1]);
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        if (!Heap[left].empty())
            best[node] = toRight[node] = Heap[left].top().first;
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    Merge(node);
}

void AddLeft(int node, int left, int right, int where, int id) {
    if (left == right) {
        toLeft[node] = max(toLeft[node], preffix[id]);
        best[node] = max(toLeft[node], toRight[node]);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        AddLeft(2 * node, left, middle, where, id);
    else
        AddLeft(2 * node + 1, middle + 1, right, where, id);
    Merge(node);
}

void EraseRight(int node, int left, int right, int where, int id) {
    if (left == right) {
        out[id] = true;
        while (!Heap[left].empty() && out[Heap[left].top().second])
            Heap[left].pop();
        if (!Heap[left].empty())
            toRight[node] = Heap[left].top().first;
        else
            toRight[node] = 0;
        best[node] = max(toLeft[node], toRight[node]);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle)
        EraseRight(2 * node, left, middle, where, id);
    else
        EraseRight(2 * node + 1, middle + 1, right, where, id);
    Merge(node);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        initial[i] = v[i];
    }
    Normalize(n);
    for (int i = 1; i <= n; i++) {
        preffix[i] = Query(1, 1, n, 1, v[i]) + 1;
        Update(1, 1, n, v[i], preffix[i]);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--) {
        suffix[i] = Query(1, 1, n, v[i], n) + 1;
        Update(1, 1, n, v[i], suffix[i]);
    }
    for (int i = 1; i <= n; i++)
        v[i] = initial[i];
    NormalizeBoth(n);
    for (int i = n; i >= 2; i--)
        Heap[finish[i]].push(make_pair(suffix[i], i));
    BuildTree(1, 1, 2 * n);
    int answer = n - 1;
    for (int i = 1; i <= n; i++) {
        if (i != 1) {
            AddLeft(1, 1, 2 * n, start[i - 1], i - 1);
            EraseRight(1, 1, 2 * n, finish[i], i);
        }
        answer = min(answer, n - 1 - best[1]);
    }
    printf("%d\n", answer);
    return 0;
}