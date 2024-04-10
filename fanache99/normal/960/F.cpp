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

const int MAXN = 100000;

struct Node {
    int biggest;
    Node *left, *right;

    Node() {
        biggest = 0;
        left = right = NULL;
    }
};

Node *root[1 + MAXN];

void Update(Node *node, int left, int right, int where, int value) {
    if (left == right) {
        node->biggest = max(node->biggest, value);
        return;
    }
    int middle = (left + right) / 2;
    if (where <= middle) {
        if (!node->left)
            node->left = new Node();
        Update(node->left, left, middle, where, value);
    }
    else {
        if (!node->right)
            node->right = new Node();
        Update(node->right, middle + 1, right, where, value);
    }
    node->biggest = 0;
    if (node->left)
        node->biggest = max(node->biggest, node->left->biggest);
    if (node->right)
        node->biggest = max(node->biggest, node->right->biggest);
}

int Query(Node *node, int left, int right, int from, int to) {
    if (from > to)
        return 0;
    if (from <= left && right <= to)
        return node->biggest;
    int middle = (left + right) / 2, answer = 0;
    if (from <= middle && node->left)
        answer = max(answer, Query(node->left, left, middle, from, to));
    if (middle + 1 <= to && node->right)
        answer = max(answer, Query(node->right, middle + 1, right, from, to));
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, answer = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        root[i] = new Node();
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int x = 1 + Query(root[a], 0, MAXN, 0, c - 1);
        Update(root[b], 0, MAXN, c, x);
        answer = max(answer, x);
    }
    printf("%d\n", answer);
    return 0;
}