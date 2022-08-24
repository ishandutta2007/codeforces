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

int a[100001];

struct TNode {
    int key;
    int left, right;
};

TNode tree[1000000];

void buildTree(int node, int l, int r) {
    tree[node].left = l;
    tree[node].right = r;
    if (r - l == 1) {
        tree[node].key = 0;
        return;
    }
    int m = (l + r) / 2;
    buildTree(2 * node, l, m);
    buildTree(2 * node + 1, m, r);

}

void sset(int node, int i, int x) {
    if (i >= tree[node].right || i < tree[node].left) {
        return;
    }
    if (i == tree[node].left && i + 1 == tree[node].right) {
        tree[node].key = x;
        return;
    }
    sset(2 * node, i, x);
    sset(2 * node + 1, i, x);
    tree[node].key = max(tree[2 * node].key, tree[2 * node + 1].key);
}

int get(int node, int l, int r) {
    if (r <= tree[node].left || l >= tree[node].right) {
        return 0;
    }
    if (l <= tree[node].left && tree[node].right <= r) {
        return tree[node].key;
    }
    return max(get(2 * node, l, r), get(2 * node + 1, l, r));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        --a[i];
    }
    buildTree(1, 0, N);
    for (int i = 0; i < N; ++i) {
        sset(1, a[i], get(1, 0, a[i]) + 1);
    }
    cout << get(1, 0, N) << '\n';

	return 0;
}