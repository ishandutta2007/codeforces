#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 128256;

class segtree
{
    private:
        vector <int> tree;
        vector <char> lazy;
        vector <int> val;

        inline void push(int v, int l, int r)
        {
            if (lazy[v])
            {
                if (l != r)
                {
                    int m = (l + r) / 2;
                    tree[v*2] = val[v] * (m - l + 1);
                    val[v*2] = val[v];
                    lazy[v*2] = true;
                    tree[v*2+1] = val[v] * (r - m);
                    val[v*2+1] = val[v];
                    lazy[v*2+1] = true;
                }
                lazy[v] = false;
            }
        }

        void update(int v, int l, int r, int ql, int qr, int num)
        {
            if (ql > qr) return;
            if (ql == l && qr == r)
            {
                tree[v] = num * (qr - ql + 1);
                val[v] = num;
                lazy[v] = true;
            }
            else
            {
                push(v, l, r);
                int m = (l + r) / 2;
                update(v*2,   l,   m, ql, min(qr, m),   num);
                update(v*2+1, m+1, r, max(ql, m+1), qr, num);
                tree[v] = tree[v*2] + tree[v*2+1];
            }
        }

        int sum(int v, int l, int r, int ql, int qr)
        {
            if (ql > qr) return 0;
            if (ql == l && qr == r)
                return tree[v];
            else
            {
                push(v, l, r);
                int m = (l + r) / 2;
                return sum(v*2,   l,   m, ql, min(qr, m)) +
                       sum(v*2+1, m+1, r, max(ql, m+1), qr);
            }
        }

    public:

        segtree() : tree(4 * maxN, 0), lazy(4 * maxN, false), val(4 * maxN, 0) {}

        void update(int l, int r, int num)
        {
            update(1, 0, maxN-1, l, r, num);
        }

        int sum(int l, int r)
        {
            return sum(1, 0, maxN-1, l, r);
        }
};

vector <segtree> trees(26);
vector <int> cnts(26);

int main()
{
    int n, q; cin >> n >> q;
    string s; cin >> s;

    for (int i = 0; i < n; i++)
        trees[s[i] - 'a'].update(i, i, 1);

    for (int i = 0; i < q; i++)
    {
        int l, r, k; cin >> l >> r >> k;
        l--; r--;

        for (int j = 0; j < 26; j++)
            cnts[j] = trees[j].sum(l, r);

        for (int j = 0; j < 26; j++)
            trees[j].update(l, r, 0);

        int rng = l;

        if (k == 1)
        {
            for (int j = 0; j < 26; j++)
            {
                trees[j].update(rng, rng + cnts[j] - 1, 1);
                rng += cnts[j];
            }
        }
        if (k == 0)
        {
            for (int j = 25; j >= 0; j--)
            {
                trees[j].update(rng, rng + cnts[j] - 1, 1);
                rng += cnts[j];
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 26; j++)
            if (trees[j].sum(i, i)) cout << char(j + 'a');
    cout << endl;

    return 0;
}