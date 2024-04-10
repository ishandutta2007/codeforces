#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int tree[4000010];
int ans[1000001];
int bits;
int n;

void build_tree(int i=1, int val=0, int bc=0) {
    if (bc == bits) {
        if (val <= n) tree[i] = 1;
        return;
    }

    build_tree(2*i, val<<1, bc+1);
    build_tree(2*i+1, (val<<1) + 1, bc+1);
    tree[i] = tree[2*i] + tree[2*i+1];
}

void query(int targ, int i=1, int val=0, int bc=0) {
    tree[i]--;
    if (bits == bc) {
        ans[targ] = val;
        return;
    }

    if (targ & (1<<(bits-bc-1))) {
        if (tree[2*i]) {
            query(targ, 2*i, val<<1, bc+1);
        }
        else {
            query(targ, 2*i+1, (val<<1) + 1, bc+1);
        }
    }
    else {
        if (tree[2*i+1]) {
            query(targ, 2*i+1, (val<<1) + 1, bc+1);
        }
        else {
            query(targ, 2*i, val<<1, bc+1);
        }
    }
}

int main() {
    scanf("%d", &n);

    for (bits = 1; ((1<<bits)-1) < n; bits++);

    build_tree();
    long long cnt = 0;
    for (int i = 0; i <= n; i++) {
        query(i);
        cnt += i ^ ans[i];
    }

    cout << cnt << endl;
    for (int i = 0; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}