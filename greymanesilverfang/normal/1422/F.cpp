#include <cstdio>
#include <algorithm>
#include <map>
#include <stack>
const int LIM = 2e5, MOD = 1e9+7;
const int LOG = 20, N = 1e5+1, MAX = LIM+1;
bool prime[MAX];
int index_cur = 0;

int mul(int x, int y)
{
    return 1LL * x * y % MOD;
}

int pow(int x, long long y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = mul(res, x);
        x = mul(x, x);
        y /= 2;
    }
    return res;
}

struct Node
{
    int l, r, val, vis;
    Node *lc, *rc;
    Node() {}
    Node(int _l, int _r)
    {
        l = _l;
        r = _r;
        val = 1;
        vis = index_cur;
        lc = rc = nullptr;
    }
    void init()
    {
        if (l == r)
            return;
        int m = (l + r) / 2;
        lc = new Node(l, m);
        lc->init();
        rc = new Node(m + 1, r);
        rc->init();
    }
    Node* update(int pos, int val)
    {
        if (pos < l || r < pos || val == 1)
            return this;
        Node *res = this;
        if (vis < index_cur)
        {
            res = new Node(l, r);
            vis = index_cur;
        }
        res->val = mul(val, this->val);
        if (l < r)
        {
            res->lc = lc->update(pos, val);
            res->rc = rc->update(pos, val);
        }
        return res;
    }
    int query(int l, int r)
    {
        if (r < this->l || this->r < l)
            return 1;
        if (l <= this->l && this->r <= r)
            return val;
        return mul(lc->query(l, r), rc->query(l, r));
    }
};
Node *root_cur, *root[N];

struct Prime
{
    int p[LOG], pinv[LOG];
    struct Data
    {
        int pos, val;
    };
    std::stack<Data> s;
    void init(int prime)
    {
        int inv = pow(prime, MOD - 2);
        int exp = 0;
        p[0] = pinv[0] = 1;
        while (p[exp] <= LIM / prime)
        {
            p[exp + 1] = mul(p[exp], prime);
            pinv[exp + 1] = mul(pinv[exp], inv);
            ++exp;
        }
    }
    void push(int pos, int val)
    {
        int cur = 0;
        while (!s.empty() && s.top().val <= val)
        {
            root_cur = root_cur->update(s.top().pos, pinv[s.top().val - cur]);
            cur = s.top().val;
            s.pop();
        }
        if (!s.empty())
            root_cur = root_cur->update(s.top().pos, pinv[val - cur]);
        root_cur = root_cur->update(pos, p[val]);
        s.push({pos, val});
    }
};
std::map<int,Prime> p;

void preprocess()
{
    std::fill(prime, prime + MAX, true);
    for (int i = 2; i * i <= LIM; ++i)
        if (prime[i])
            for (int j = i * i; j <= LIM; j += i)
                prime[j] = false;
    for (int i = 2; i <= LIM; ++i)
        if (prime[i])
            p[i].init(i);
}

int main()
{
    preprocess();
    int n; scanf("%d", &n);
    root_cur = new Node(1, n);
    root_cur->init();
    for (int i = 1; i <= n; ++i)
    {
        index_cur = i;
        int a; scanf("%d", &a);
        for (int j = 2; j * j <= a; ++j)
            if (a % j == 0)
            {
                int cnt = 0;
                while (a % j == 0)
                {
                    a /= j;
                    ++cnt;
                }
                p[j].push(i, cnt);
            }
        if (a > 1)
            p[a].push(i, 1);
        root[i] = root_cur;
    }
    int q; scanf("%d", &q);
    int last = 0;
    for (int i = 1; i <= q; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        int l = (last + x) % n + 1, r = (last + y) % n + 1;
        if (l > r)
            std::swap(l, r);
        last = root[r]->query(l, r);
        printf("%d\n", last);
    }
}