#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

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

const int MAXN = 100000;
const int MAXLOG = 18;
const int INF = 1000000000;

int n, k, b[1 + MAXN];
int rmq[1 + MAXLOG][1 + MAXN];
int logarithm[1 + MAXN];

void RMQ() {
    for (int i = 2; i <= n; i++)
        logarithm[i] = logarithm[i / 2] + 1;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
}

int RMQQuery(int x, int y) {
    int l = logarithm[y - x + 1];
    return min(rmq[l][x], rmq[l][y - (1 << l) + 1]);
}

int Query(int x, int y) {
    int bx = (x - 1) / n, by = (y - 1) / n;
    x -= bx * n;
    y -= by * n;
    if (bx == by)
        return RMQQuery(x, y);
    if (bx + 1 == by)
        return min(RMQQuery(x, n), RMQQuery(1, y));
    return RMQQuery(1, n);
}

int from, to, change;

struct Node {
    int best;
    int lazy;
    Node *left, *right;

    Node(int _best = 0, int _lazy = 0, Node *_left = NULL, Node *_right = NULL) {
        best = _best;
        lazy = _lazy;
        left = _left;
        right = _right;
    }
};

void TreeUpdate(Node *node, int left, int right) {
    if (from <= left && right <= to) {
        node->lazy = node->best = change;
        return;
    }
    int middle = (left + right) / 2;
    if (node->left == NULL)
        node->left = new Node(Query(left, middle));
    if (node->right == NULL)
        node->right = new Node(Query(middle + 1, right));
    if (node->lazy) {
        node->left->best = node->left->lazy = node->lazy;
        node->right->best = node->right->lazy = node->lazy;
        node->lazy = 0;
    }
    if (from <= middle)
        TreeUpdate(node->left, left, middle);
    if (middle + 1 <= to)
        TreeUpdate(node->right, middle + 1, right);
    node->best = min(node->left->best, node->right->best);
}

int TreeQuery(Node *node, int left, int right) {
    if (from <= left && right <= to)
        return node->best;
    int middle = (left + right) / 2;
    if (node->left == NULL)
        node->left = new Node(Query(left, middle));
    if (node->right == NULL)
        node->right = new Node(Query(middle + 1, right));
    if (node->lazy) {
        node->left->best = node->left->lazy = node->lazy;
        node->right->best = node->right->lazy = node->lazy;
        node->lazy = 0;
    }
    node->best = min(node->left->best, node->right->best);
    int answer = INF;
    if (from <= middle)
        answer = min(answer, TreeQuery(node->left, left, middle));
    if (middle + 1 <= to)
        answer = min(answer, TreeQuery(node->right, middle + 1, right));
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    n = Read();
    k = Read();
    for (int i = 1; i <= n; i++) {
        b[i] = Read();
        rmq[0][i] = b[i];
    }
    RMQ();
    Node *root = new Node(Query(1, n * k));
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int type = Read();
        if (type == 1) {
            from = Read();
            to = Read();
            change = Read();
            TreeUpdate(root, 1, n * k);
        }
        else {
            from = Read();
            to = Read();
            printf("%d\n", TreeQuery(root, 1, n * k));
        }
    }
    return 0;
}