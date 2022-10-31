#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct ans {
    int all, left, right;
    ans(): all(0), left(0), right(0) {}
    ans(int all, int left, int right): all(all), left(left), right(right) {}
};

struct node {
    node *L, *R;
    ans data;
};

ans upd(ans al, ans ar, int l, int r) {
    ans res;
    int mid = (r+l) / 2;
    res.all = max(al.all, max(ar.all, al.right + ar.left));
    if (al.left == mid-l) {
        res.left = mid-l+ar.left;
    } else res.left = al.left;
    if (ar.right == r-mid) {
        res.right = r-mid+al.right;
    } else res.right = ar.right;
    return res;
}

node * add(node * v, int l, int r, int i) {
    if (l>i || r<=i) return v;
    else {
        node * new_node = new node();
        if (r - l == 1) {
            new_node->data = ans(1, 1, 1);
            return new_node;
        } else {
            int mid = (l + r) / 2;
            new_node->L = add(v->L, l, mid, i);
            new_node->R = add(v->R, mid, r, i);
            new_node->data = upd(new_node->L->data, new_node->R->data, l, r);
            return new_node;
        }
    }
}

ans get(node * v, int vl, int vr, int l, int r) {
    ans res;
    if (vr <= l || vl >= r) return res;
    else {
        if (vl >=l && vr <= r) {
            return ans(v->data.all, v->data.left, v->data.right);
        } else {
            int mid = (vl + vr) / 2;
            res = upd(get(v->L, vl, mid, l, r), get(v->R, mid, vr, l, r), vl, vr);
            return res;
        }
    }
}

node * build (int l, int r) {
    if (r<=l) return NULL;
    else if (r == l+1) return new node();
    else {
        node * new_node = new node();
        int mid = (l+r)/2;
        new_node->L = build(l, mid);
        new_node->R = build(mid, r);
        return new_node;
    }
}

int n, m;
node * trees[111111];
pair<int, int> h[111111];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &n);
    trees[0] = build(1, n+1);
    for (int i = 0; i < n; i++) {
        int hh;
        scanf("%d", &hh);
        h[i] = make_pair(hh, i + 1);
    }
    sort(h, h+n);
    reverse(h, h+n);
    for (int i = 0; i < n; i++) {
        //cout << h[i].first << ' ' << h[i].second << endl;
        trees[i+1] = add(trees[i], 1, n+1, h[i].second);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int L, R, w;
        scanf("%d%d%d", &L, &R, &w);
        int l = 0, r = n+1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            //cout << mid << endl;
            ans v = get (trees[mid], 1, n+1, L, R+1);
            //cout << (v.left) << ' ' << (v.right) << ' ' << (v.all) << endl;
            if (get (trees[mid], 1, n+1, L, R+1).all < w) {
                l = mid;
            } else r = mid;
        }
        printf("%d\n", h[l].first);
    }
    return 0;
}