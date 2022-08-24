#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

struct TNode {
    int left, right;
    int L, R;
    long long s1, s2, sum;
    long long val;
};

TNode tree[1000000];
int treeSize = 0;

int a[300000];
long long f[300000], fs[300000];;
const long long P = 1000000000;

void push(TNode &node) {
    if (node.R - node.L == 1) {
        node.val = 0;
        return;
    }
    long long val = node.val;
    TNode &left = tree[node.left], &right = tree[node.right];
    left.sum = (left.sum + val * (left.R - left.L)) % P;
    left.val = (left.val + val) % P;
    right.sum = (right.sum + val * (right.R - right.L)) % P;
    right.val = (right.val + val) % P;
    left.s1 = (left.s1 + val * fs[left.R - left.L]) % P;
    left.s2 = (left.s2 + val * (fs[left.R - left.L + 1] - 1)) % P;
    right.s1 = (right.s1 + val * fs[right.R - right.L]) % P;
    right.s2 = (right.s2 + val * (fs[right.R - right.L + 1] - 1)) % P;
    node.val = 0;
}

void relax(TNode &node) {
    if (node.R - node.L == 1) {
        return;
    }

    TNode &left = tree[node.left], &right = tree[node.right];
    node.sum = (left.sum + right.sum) % P;
    node.s1 = (left.s1 + f[left.R - left.L] * right.s1 + f[left.R - left.L + 1] * right.s2) % P;
    node.s2 = (left.s2 + f[left.R - left.L + 1] * right.s1 + f[left.R - left.L + 2] * right.s2) % P;
}

void change(int p, int x, int v) {
    TNode &node = tree[p];
    if (node.L > x || node.R <= x) {
        return;
    }
    if (node.R - node.L == 1) {
        node.sum = node.s1 = v;
        return;
    }
    push(node);
    change(node.left, x, v);
    change(node.right, x, v);
    relax(node);
}

void changeInt(int p, int l, int r, int x) {
    TNode &node = tree[p];
    if (node.L >= r || l >= node.R) {
        return;
    }
    if (l <= node.L && node.R <= r) {
        node.val = (node.val + x) % P;
        node.sum = (node.sum + x * (node.R - node.L)) % P;
        node.s1 = (node.s1 + x * fs[node.R - node.L]) % P;
        node.s2 = (node.s2 + x * (fs[node.R - node.L + 1] - 1)) % P;
        return;
    }
    push(node);
    changeInt(node.left, l, r, x);
    changeInt(node.right, l, r, x);
    relax(node);
}

long long fsum(int p, int l, int r) {
    TNode &node = tree[p];
    if (node.L >= r || l >= node.R) {
        return 0;
    }
    if (l <= node.L && node.R <= r) {
        return (f[node.L - l + 2] * node.s1 + f[node.L - l + 3] * node.s2) % P;
    }
    push(node);
    return (fsum(node.left, l, r) + fsum(node.right, l, r)) % P;
}

int buildTree(int L, int R) {
    int p = treeSize++;
    TNode &node = tree[p];
    node.L = L;
    node.R = R;
    if (R - L == 1) {
        node.sum = a[L];
        node.s1 = a[L];
        node.s2 = 0;
        return p;
    }
    int M = (L + R) / 2;
    node.left = buildTree(L, M);
    node.right = buildTree(M, R);
    relax(node);
    return p;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    f[0] = 1;
    f[1] = 0;
    fs[1] = 1;
    fs[2] = 1;
    for (int i = 2; i <= N + 10; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % P;
        fs[i + 1] = (fs[i] + f[i]) % P;
    }
    buildTree(0, N);
    for (int i = 0; i < M; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, v;
            scanf("%d%d", &x, &v);
            --x;
            change(0, x, v);
        }
        if (t == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            --l;
            printf("%d\n", (int)fsum(0, l, r));
        }
        if (t == 3) {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            --l;
            changeInt(0, l, r, d);
        }
    }

	return 0;
}