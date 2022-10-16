#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

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

const int MAXN = 10;
const int MAXM = 100000;
const int MAXNODES = 262144;

int a[1 + MAXN][1 + MAXM];

struct Block {
    int different;
    int left[1 + MAXN];
    int right[1 + MAXN];
};

Block tree[1 + MAXNODES];
int dad[1 + 4 * MAXN];
int seen[1 + 4 * MAXN], change[1 + 4 * MAXN], number = 0;
int n;

void Initialize() {
    for (int i = 1; i <= 4 * n; i++)
        dad[i] = i;
}

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

bool Join(int a, int b) {
    a = FindDad(a), b = FindDad(b);
    if (a == b)
        return false;
    if (rand() % 2)
        dad[a] = b;
    else
        dad[b] = a;
    return true;
}

Block Merge(Block x, Block y, int where) {
    number++;
    Block answer;
    answer.different = x.different + y.different;
    for (int i = 1; i <= n; i++) {
        x.left[i] += 2 * n;
        x.right[i] += 2 * n;
    }
    Initialize();
    for (int i = 1; i <= n; i++)
        if (a[i][where] == a[i][where + 1])
            if (Join(x.right[i], y.left[i]))
                answer.different--;
    for (int i = 1; i <= n; i++) {
        answer.left[i] = FindDad(x.left[i]);
        answer.right[i] = FindDad(y.right[i]);
        seen[answer.right[i]] = seen[answer.left[i]] = number;
    }
    int small = 0;
    for (int i = 1; i <= 4 * n; i++)
        if (seen[i] == number) {
            small++;
            change[i] = small;
        }
    for (int i = 1; i <= n; i++) {
        answer.left[i] = change[answer.left[i]];
        answer.right[i] = change[answer.right[i]];
    }
    return answer;
}

void BuildTree(int node, int left, int right) {
    if (left == right) {
        tree[node].different = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][left] == a[i - 1][left])
                tree[node].left[i] = tree[node].right[i] = tree[node].left[i - 1];
            else {
                tree[node].different++;
                tree[node].left[i] = tree[node].right[i] = tree[node].left[i - 1] + 1;
            }
        return;
    }
    int middle = (left + right) / 2;
    BuildTree(2 * node, left, middle);
    BuildTree(2 * node + 1, middle + 1, right);
    tree[node] = Merge(tree[2 * node], tree[2 * node + 1], middle);
}

Block total;
int from, to;

void Query(int node, int left, int right) {
    if (from <= left && right <= to) {
        if (!total.different)
            total = tree[node];
        else
            total = Merge(total, tree[node], left - 1);
        return;
    }
    int middle = (left + right) / 2;
    if (from <= middle)
        Query(2 * node, left, middle);
    if (middle + 1 <= to)
        Query(2 * node + 1, middle + 1, right);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    srand(time(0));
    n = Read();
    int m = Read(), q = Read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = Read();
    BuildTree(1, 1, m);
    for (int i = 1; i <= q; i++) {
        from = Read();
        to = Read();
        total.different = 0;
        Query(1, 1, m);
        printf("%d\n", total.different);
    }
    return 0;
}