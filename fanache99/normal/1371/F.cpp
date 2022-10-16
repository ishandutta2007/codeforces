#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500000;

char s[1 + MAXN];

struct Node {
    bool swapped;
    int m01, m10;
    int l1, l0, r1, r0;
    int l10, l01, r10, r01;
};

Node tree[1 + 4 * MAXN];

void swapData(int node) {
    tree[node].swapped ^= 1;
    swap(tree[node].m01, tree[node].m10);
    swap(tree[node].l0, tree[node].l1);
    swap(tree[node].r0, tree[node].r1);
    swap(tree[node].l10, tree[node].l01);
    swap(tree[node].r10, tree[node].r01);
}

void propagate(int node) {
    if (tree[node].swapped) {
        swapData(node);
        swapData(2 * node);
        swapData(2 * node + 1);
    }
}

Node *combine(Node &node, Node leftSon, Node rightSon, int left, int middle, int right) {
    if (leftSon.l0 == middle - left + 1) {
        node.l0 = leftSon.l0 + rightSon.l0;
    } else {
        node.l0 = leftSon.l0;
    }

    if (leftSon.l1 == middle - left + 1) {
        node.l1 = leftSon.l1 + rightSon.l1;
    } else {
        node.l1 = leftSon.l1;
    }

    if (rightSon.r0 == right - middle) {
        node.r0 = rightSon.r0 + leftSon.r0;
    } else {
        node.r0 = rightSon.r0;
    }

    if (rightSon.r1 == right - middle) {
        node.r1 = rightSon.r1 + leftSon.r1;
    } else {
        node.r1 = rightSon.r1;
    }

    if (leftSon.l1 == middle - left + 1) {
        node.l10 = leftSon.l1 + rightSon.l10;
    } else if (leftSon.l10 == middle - left + 1) {
        node.l10 = leftSon.l10 + rightSon.l0;
    } else {
        node.l10 = leftSon.l10;
    }

    if (leftSon.l0 == middle - left + 1) {
        node.l01 = leftSon.l0 + rightSon.l01;
    } else if (leftSon.l01 == middle - left + 1) {
        node.l01 = leftSon.l01 + rightSon.l1;
    } else {
        node.l01 = leftSon.l01;
    }

    if (rightSon.r1 == right - middle) {
        node.r01 = rightSon.r1 + leftSon.r01;
    } else if (rightSon.r01 == right - middle) {
        node.r01 = rightSon.r01 + leftSon.r0;
    } else {
        node.r01 = rightSon.r01;
    }

    if (rightSon.r0 == right - middle) {
        node.r10 = rightSon.r0 + leftSon.r10;
    } else if (rightSon.r10 == right - middle) {
        node.r10 = rightSon.r10 + leftSon.r1;
    } else {
        node.r10 = rightSon.r10;
    }

    node.m01 = max(leftSon.m01, rightSon.m01);
    node.m01 = max(node.m01, leftSon.r01 + rightSon.l1);
    node.m01 = max(node.m01, leftSon.r0 + rightSon.l01);
    node.m01 = max(node.m01, leftSon.r0 + rightSon.l1);

    node.m10 = max(leftSon.m10, rightSon.m10);
    node.m10 = max(node.m10, leftSon.r10 + rightSon.l0);
    node.m10 = max(node.m10, leftSon.r1 + rightSon.l10);
    node.m10 = max(node.m10, leftSon.r1 + rightSon.l0);
}

void build(int node, int left, int right) {
    if (left == right) {
        tree[node].swapped = false;
        tree[node].m01 = tree[node].m10 = 1;
        tree[node].l10 = tree[node].l01 = tree[node].r10 = tree[node].r01 = 1;
        if (s[left] == '<') {
            tree[node].l0 = tree[node].r0 = 1;
            tree[node].l1 = tree[node].r1 = 0;
        } else {
            tree[node].l0 = tree[node].r0 = 0;
            tree[node].l1 = tree[node].r1 = 1;
        }
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    combine(tree[node], tree[2 * node], tree[2 * node + 1], left, (left + right) / 2, right);
}

void update(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        swapData(node);
        return;
    }
    int middle = (left + right) / 2;
    propagate(node);
    if (from <= middle) {
        update(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        update(2 * node + 1, middle + 1, right, from, to);
    }
    combine(tree[node], tree[2 * node], tree[2 * node + 1], left, (left + right) / 2, right);
}

Node answer;
int leftEnd, rightEnd;

void query(int node, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        if (rightEnd == 0) {
            leftEnd = left;
            rightEnd = right;
            answer = tree[node];
        } else {
            combine(answer, answer, tree[node], leftEnd, rightEnd, right);
            rightEnd = right;
        }
        return;
    }
    propagate(node);
    int middle = (left + right) / 2;
    if (from <= middle) {
        query(2 * node, left, middle, from, to);
    }
    if (middle + 1 <= to) {
        query(2 * node + 1, middle + 1, right, from, to);
    }
}

int main(){
    //ifstream cin("input.txt");
    int n, q;
    cin >> n >> q >> (s + 1);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        update(1, 1, n, a, b);
        rightEnd = 0;
        query(1, 1, n, a, b);
        cout << answer.m10 << "\n";
    }
    return 0;
}