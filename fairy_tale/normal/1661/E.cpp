#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

string s[3];
int tot = 0;

struct node {
    int p[6], num;

    void init(int idx, int mask)
    {
        if (mask == 0) {
            p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = 0;
            num = 0;
        } else if (mask == 1) {
            p[0] = p[1] = ++tot;
            p[2] = p[3] = p[4] = p[5] = 0;
            num = 1;
        } else if (mask == 2) {
            p[2] = p[3] = ++tot;
            p[0] = p[1] = p[4] = p[5] = 0;
            num = 1;
        } else if (mask == 3) {
            p[0] = p[1] = p[2] = p[3] = ++tot;
            p[4] = p[5] = 0;
            num = 1;
        } else if (mask == 4) {
            p[0] = p[1] = p[2] = p[3] = 0;
            p[4] = p[5] = ++tot;
            num = 1;
        } else if (mask == 5) {
            p[0] = p[1] = ++tot;
            p[2] = p[3] = 0;
            p[4] = p[5] = ++tot;
            num = 2;
        } else if (mask == 6) {
            p[0] = p[1] = 0;
            p[2] = p[3] = p[4] = p[5] = ++tot;
            num = 1;
        } else if (mask == 7) {
            p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = ++tot;
            num = 1;
        }
    }

    void merge(node l, node r)
    {
        num = l.num + r.num;

        for (int i = 0; i < 3; i++) {
            int x = l.p[i << 1 | 1], y = r.p[i << 1];
            if (x > 0 && y > 0) {
                if (x == y) continue;
                num--;
                tot++;
                for (int j = 0; j < 6; j++) {
                    if (l.p[j] == x || l.p[j] == y) l.p[j] = tot;
                }
                for (int j = 0; j < 6; j++) {
                    if (r.p[j] == x || r.p[j] == y) r.p[j] = tot;
                }
            }
        }

        p[0] = l.p[0];
        p[2] = l.p[2];
        p[4] = l.p[4];
        p[1] = r.p[1];
        p[3] = r.p[3];
        p[5] = r.p[5];
    }
} f[maxn << 2];


void init()
{

}

void build(int t, int l, int r)
{
    if (l == r) {
        int mask = 0;
        for (int i = 0; i < 3; i++) {
            if (s[i][l - 1] == '1') mask |= 1 << i;
        }

        f[t].init(l, mask);
        return;
    }

    int mid = (l + r) >> 1;
    build(lson(t), l, mid);
    build(rson(t), mid + 1, r);
    f[t].merge(f[lson(t)], f[rson(t)]);

    //cout << t << ": " << l << " " << r << " == " << f[t].num << endl;
    //for (int i = 0; i < 6; i++) cout << f[t].p[i] << " ";
    //cout << endl;
}

node query(int t, int l, int r, int ll, int rr)
{
    if (ll <= l && r <= rr) return f[t];
    int mid = (l + r) >> 1;

    if (rr <= mid) return query(lson(t), l, mid, ll, rr);
    else if (ll > mid) return query(rson(t), mid + 1, r, ll, rr);

    node ret;
    ret.merge(query(lson(t), l, mid, ll, rr), query(rson(t), mid + 1, r, ll, rr));
    return ret;

}

void solve()
{
    int n, q;
    int l, r;
    node ret;

    cin >> n;
    cin >> s[0] >> s[1] >> s[2];
    cin >> q;

    build(1, 1, n);

    while (q--) {
        cin >> l >> r;
        //cout << l << " ? " << r << endl;
        ret = query(1, 1, n, l, r);
        //for (int i = 0; i < 6; i++) cout << ret.p[i] << " ";
        //cout << endl;
        cout << ret.num << endl;
    }
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}