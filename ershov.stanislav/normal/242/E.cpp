#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void build(int tree[], int d[], int v, int tl, int tr, int a[]) {
    d[v] = 0;
    if (tl == tr) tree[v] = a[tl];
    else {
        int mid = (tl+tr)/2;
        build(tree, d, v*2, tl, mid, a);
        build(tree, d, v*2+1, mid+1, tr, a);
        tree[v] = tree[2*v]+tree[2*v+1];
    }
}

void push(int tree[], int d[], int v, int l) {
    d[2*v] ^= d[v];
    d[2*v+1] ^= d[v];
    if (d[v]) tree[v] = l-tree[v];
    d[v] = 0;
}

void update(int tree[], int d[], int v, int tl, int tr, int l, int r) {
    if (l > r) return;
    if (tl == l && tr == r) d[v] ^= 1;
    else {
        push(tree, d, v, tr-tl+1);
        int mid = (tl+tr)/2;
        update(tree, d, 2*v, tl, mid, l, min(r, mid));
        update(tree, d, 2*v+1, mid+1, tr, max(l, mid+1), r);
        tree[v] = 0;
        if (d[2*v] == 0) tree[v] += tree[2*v];
        else tree[v] += mid-tl+1-tree[2*v];
        if (d[2*v+1] == 0) tree[v] += tree[2*v+1];
        else tree[v] += tr-mid-tree[2*v+1];
    }
}

int sum(int tree[], int d[], int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    else if (tl == l && tr == r && d[v] == 0) return tree[v];
    else if (tl == l && tr == r && d[v] == 1) return tr-tl+1-tree[v];
    else {
        int mid = (tl+tr)/2;
        push(tree, d, v, tr-tl+1);
        return sum(tree, d, 2*v, tl, mid, l, min(r, mid)) + sum(tree, d, 2*v+1, mid+1, tr, max(l, mid+1), r);
    }
}

int main()
{
    int n, m, *a[20];
    int* tree[20];
    int* d[20];
    cin >> n;
    for (int i=0; i<20; i++) {
        a[i] = new int[n];
        tree[i] = new int[4*n];
        d[i] = new int[4*n];
    }
    for (int i=0; i<n; i++) {
        int b;
        cin >> b;
        for (int j=0; j<20; j++) {
            a[j][i] = b&1;
            b >>=  1;
        }
    }
    for (int i=0; i<20; i++) build(tree[i], d[i], 1, 0, n-1, a[i]);
    cin >> m;
    for (int i=0; i<m; i++) {
        int type, l, r, x;
        cin >> type;
        if (type == 1) {
            cin >> l >> r;
            long long int res = 0;
            for (int j=0; j<20; j++) {
                res <<= 1;
                res += sum(tree[19-j], d[19-j], 1, 0, n-1, l-1, r-1);
            }
            cout << res << endl;
        } else {
            cin >> l >> r >> x;
            for (int j=0; j<20; j++) {
                if ((x>>j)&1 == 1) update(tree[j], d[j], 1, 0, n-1, l-1, r-1);
            }
        }
    }
    return 0;
}