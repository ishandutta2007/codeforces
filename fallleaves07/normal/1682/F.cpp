#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

namespace GTI
{
    char gc(void)
    {
        const int S = 1 << 16;
        static char buf[S], *s = buf, *t = buf;
        if (s == t)
            t = buf + fread(s = buf, 1, S, stdin);
        if (s == t)
            return EOF;
        return *s++;
    }
    ll gti(void)
    {
        ll a = 0, b = 1, c = gc();
        for (; !isdigit(c); c = gc())
            b ^= (c == '-');
        for (; isdigit(c); c = gc())
            a = a * 10 + c - '0';
        return b ? a : -a;
    }
    int gts(char *s)
    {
        int len = 0, c = gc();
        for (; isspace(c); c = gc())
            ;
        for (; c != EOF && !isspace(c); c = gc())
            s[len++] = c;
        s[len] = 0;
        return len;
    }
    int gtl(char *s)
    {
        int len = 0, c = gc();
        for (; isspace(c); c = gc())
            ;
        for (; c != EOF && c != '\n'; c = gc())
            s[len++] = c;
        s[len] = 0;
        return len;
    }
}
using GTI::gti;
using GTI::gtl;
using GTI::gts;

std::vector<int> a, b, tag;
std::vector<ll> s;

const int M = 1e9 + 7;
struct Segt
{
    struct T
    {
        int ls, rs;
        ll sumS, sumT;
        T() : ls(0), rs(0), sumS(0), sumT(0) {}
    };
    static int n;
    std::vector<T> t;
    std::vector<int> root;
    std::map<ll, int> ids;
    int newnode(void)
    {
        t.push_back(T());
        return (int)t.size() - 1;
    }
    void init(int m)
    {
		t.resize(1);
        t.reserve(m * 40);
        root.resize(m + 1);
        int idc = 0;
        for (int i = 0; i <= m; i++)
            ids[s[i]] = 0;
        for (auto &p : ids)
            p.second = ++idc;
        this->n = idc;
        for (int i = 1; i <= m; i++)
            root[i] = insert(root[i - 1], ids[s[i]], 1ll * s[i] % M * tag[i] % M, tag[i]);
    }
#define mid ((l + r) >> 1)
    int insert(int u, int loc, ll vS, ll vT, int l = 1, int r = n)
    {
        int v = newnode();
        t[v] = t[u], t[v].sumS = (t[v].sumS + vS) % M, t[v].sumT = (t[v].sumT + vT) % M;
        if (l < r)
        {
            if (loc <= mid)
                t[v].ls = insert(t[v].ls, loc, vS, vT, l, mid);
            else
                t[v].rs = insert(t[v].rs, loc, vS, vT, mid + 1, r);
        }
        return v;
    }
    ll query(int v, int ql, int qr, ll sl, int l = 1, int r = n)
    {
        if (!v)
            return 0;
        if (ql <= l && qr >= r)
            return (t[v].sumS - 1ll * sl * t[v].sumT) % M;
        ll ret = 0;
        if (ql <= mid)
            ret = (ret + query(t[v].ls, ql, qr, sl, l, mid)) % M;
        if (qr > mid)
            ret = (ret + query(t[v].rs, ql, qr, sl, mid + 1, r)) % M;
        return ret;
    }
#undef mid
    ll query(int l, int r)
    {
        if (l == r)
            return 0;
        int idl = ids[s[l - 1]];
        ll ans = (query(root[r - 1], idl + 1, n, s[l - 1] % M) - query(root[r - 1], 1, idl, s[l - 1] % M)) % M;
        ans -= query(root[l - 1], idl + 1, n, s[l - 1] % M) - query(root[l - 1], 1, idl, s[l - 1] % M);
        ans %= M;
        return ans;
    }
} t;
int Segt::n;

int main(void)
{
    int n = gti(), q = gti();
    a.resize(n + 1), b.resize(n + 1), tag.resize(n + 1), s.resize(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = gti();
    for (int i = 1; i < n; i++)
        tag[i] = a[i + 1] - a[i];
    for (int i = 1; i <= n; i++)
        b[i] = gti(), s[i] = s[i - 1] + b[i];
    t.init(n);
    for (int i = 1; i <= q; i++)
    {
        int l = gti(), r = gti();
        printf("%lld\n", (t.query(l, r) % M + M) % M);
    }
    return 0;
}