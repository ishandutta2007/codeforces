#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int M = 1e7;

struct Node {
    int sum;
    bool swp;
    Node* lf;
    Node* rg;

    Node() {};

    Node(int sum, bool swp) : sum(sum), swp(swp) {};
};

int cur = 0;
Node buf[M];

Node* newNode(int sum, bool swp) {
//    cout << "new " << endl;
    buf[cur].sum = sum;
    buf[cur].swp = swp;
    buf[cur].lf = buf[cur].rg = nullptr;
    return &buf[cur++];
}

Node* newNode(int sum, bool swp, Node* lf, Node* rg) {
    buf[cur].sum = sum;
    buf[cur].swp = swp;
    buf[cur].lf = lf;
    buf[cur].rg = rg;
    return &buf[cur++];
}

Node* merge(Node* lf, Node* rg) {
//    cout << "1 merge" << endl;
    Node* res = newNode(lf->sum + rg->sum, false);
//    cout << "2 merge" << endl;
    res->lf = lf;
    res->rg = rg;
//    cout << "3 merge" << endl;
    return res;
}

Node* build(const vector<int>& a, int l, int r) {
    if(r - l == 1)
        return newNode(a[l], false);

    int m = (l + r) / 2;

    return merge(build(a, l, m), build(a, m, r));
}

Node* swap(Node* v, int l, int r, int ql, int qr) {
    if(l >= qr || r <= ql)
        return v;

//    cout << "swap " << l << ' ' << r << ' ' << ql << ' ' << qr << endl;

    if(ql <= l && r <= qr) {
        return newNode(r - l - v->sum, v->swp ^ 1, v->lf, v->rg);
    }

    int m = (l + r) / 2;
    Node* res = merge(swap(v->lf, l, m, ql, qr), swap(v->rg, m, r, ql, qr));

    if(v->swp) {
        res->swp = true;
        res->sum = r - l - res->sum;
    }

    return res;
}

Node* update(Node* v, int l, int r, int i, int x, bool swp) {
    if(i < l || i >= r)
        return v;

//    cout << "update " << l << ' ' << r << ' ' << i << ' ' << x << ' ' << swp << endl;

    if(r - l == 1) {
        return newNode(x ^ swp, false);
    }

    int m = (l + r) / 2;

    swp ^= v->swp;

    Node* res = merge(update(v->lf, l, m, i, x, swp), update(v->rg, m, r, i, x, swp));

    if(v->swp) {
        res->swp = true;
        res->sum = r - l - res->sum;
    }

    return res;
}

int get(Node* v, int l, int r, int ql, int qr, bool swp) {
    if(l >= qr || r <= ql)
        return 0;

//    cout << "get " << l << ' ' << r << ' ' << ql << ' ' << qr << endl;

    if(ql <= l && r <= qr) {
        return (swp ? r - l - v->sum : v->sum);
    }

    swp ^= v->swp;

    int m = (l + r) / 2;

//    cout << m << endl;

    return get(v->lf, l, m, ql, qr, swp) + get(v->rg, m, r, ql, qr, swp);
}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Node*> root;
    root.push_back(build(vector<int>(n * m, 0), 0, n * m));

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int i, j;
            cin >> i >> j;

            i--;
            j--;

            root.push_back(update(root.back(), 0, n * m, i * m + j, 1, false));

        } else if(t == 2) {
            int i, j;
            cin >> i >> j;

            i--;
            j--;

            root.push_back(update(root.back(), 0, n * m, i * m + j, 0, false));
        } else if(t == 3) {
            int i;
            cin >> i;

            i--;

            root.push_back(swap(root.back(), 0, n * m, i * m, (i + 1) * m));
        } else {
            int i;
            cin >> i;

            root.push_back(root[i]);
        }

//cout << "rweg" << endl;
        cout << get(root.back(), 0, n * m, 0, n * m, false) << endl;
    }
}