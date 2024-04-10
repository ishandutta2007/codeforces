#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct SegmentTree {
    struct Node {
        int aa;
        int ab;
        int ac;
        int bb;
        int bc;
        int cc;
    };

    int n;
    vector<Node> t;

    explicit SegmentTree(int sz) {
        n = sz;
        t.resize(n * 4);
    }

    void Init(int v, char ch) {
        t[v].aa = t[v].ab = t[v].ac = t[v].bb = t[v].bc = t[v].cc = 0;
        if (ch == 'a') {
            t[v].aa = 1;
        }
        if (ch == 'b') {
            t[v].bb = 1;
        }
        if (ch == 'c') {
            t[v].cc = 1;
        }
    }

    void Merge(int v, int l, int r) {
        t[v].aa = t[l].aa + t[r].aa;
        t[v].bb = t[l].bb + t[r].bb;
        t[v].cc = t[l].cc + t[r].cc;
        t[v].ab = min(t[l].aa + t[r].ab, t[l].ab + t[r].bb);
        t[v].bc = min(t[l].bb + t[r].bc, t[l].bc + t[r].cc);
        t[v].ac = min({t[l].ab + t[r].bc, t[l].ac + t[r].cc, t[l].aa + t[r].ac});
    }

    void Build(int v, int tl, int tr, const string& str) {
        if (tl == tr) {
            Init(v, str[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        Build(v * 2, tl, tm, str);
        Build(v * 2 + 1, tm + 1, tr, str);
        Merge(v, v * 2, v * 2 + 1);
    }

    void Update(int v, int tl, int tr, int pos, char ch) {
        if (tl == tr) {
            Init(v, ch);
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            Update(v * 2, tl, tm, pos, ch);
        } else {
            Update(v * 2 + 1, tm + 1, tr, pos, ch);
        }
        Merge(v, v * 2, v * 2 + 1);
    }

    void Print(int v, int tl, int tr) {
        int tm = (tl + tr) / 2;
        if (tl != tr) {
            Print(v * 2, tl, tm);
            Print(v * 2 + 1, tm + 1, tr);
        }
        cout << tl + 1 << ' ' << tr + 1 << ' ' << t[v].aa << ' ' << t[v].bb << ' ' << t[v].cc << ' ' << t[v].ab << ' ' << t[v].bc << ' ' << t[v].ac << ' ' << v << '\n';
    }

    void Print() {
        Print(1, 0, n - 1);
    }

    void Build(const string& str) {
        Build(1, 0, n - 1, str);
    }

    void Update(int pos, char ch) {
        Update(1, 0, n - 1, pos, ch);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    SegmentTree segment_tree(n);
    segment_tree.Build(s);
    while (q--) {
        int pos;
        char ch;
        cin >> pos >> ch;
        --pos;
        segment_tree.Update(pos, ch);
        cout << segment_tree.t[1].ac << '\n';
        // segment_tree.Print();
    }
    return 0;
}

/*
6 12
aaabcc
4 b
4 b
2 b
 */