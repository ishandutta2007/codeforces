#include <iostream>
# include <algorithm>
using namespace std;

const int Maxn = 1000007;

string s;

struct Node {
    int cnt, open, close;
    Node() {
        cnt = open = close = 0;
    }
    Node(int a, int b, int c) {
        cnt = a;
        open = b;
        close = c;
    }
    Node operator + (const Node &other) const {
        int tmp = min(this -> open, other.close);
        Node ans;
        ans.cnt = this -> cnt + other.cnt + tmp;
        ans.open = this -> open + other.open - tmp;
        ans.close = this -> close + other.close - tmp;
        return ans;
    }
};
struct segment_tree {
    Node t[4 * Maxn];
    void build(int v, int l, int r) {
        if (l == r) {
            if (s[l - 1] == '(')
                t[v] = Node(0, 1, 0);
            else
                t[v] = Node(0, 0, 1);
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m);
        build(2 * v + 1, m + 1, r);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    Node get(int ql, int qr, int v, int l, int r) {
        if (qr < l || r < ql) return Node(0, 0, 0);
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) >> 1;
        return get(ql, qr, 2 * v, l, m) + get(ql, qr, 2 * v + 1, m + 1, r);
    }
};

int main()
{
    cin >> s;
    int n = (int)s.size();
    segment_tree tree;
    tree.build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << 2 * tree.get(a, b, 1, 1, n).cnt << endl;
    }
    return 0;
}