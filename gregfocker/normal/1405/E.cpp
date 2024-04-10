#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = (int) 3e5 + 7;
int n;
int q;
int a[N];
int p[N];
int mnpre[N];
int top;
int sol[N];
int tree[N];

void add(int x)
{
    while (x < N)
    {
        tree[x]++;
        x += x & (-x);
    }
}

int cnt(int x)
{
    int sol = 0;
    while (x)
    {
        sol += tree[x];
        x -= x & (-x);
    }
    return sol;
}

struct Q
{
    int i;
    int lim;
    int r;
};

bool operator < (Q a, Q b)
{
    return a.lim < b.lim;
}

struct T
{
    int negmx;
    int posmin;
};

T operator + (T a, T b)
{
    return {max(a.negmx, b.negmx), min(a.posmin, b.posmin)};
}

T t[4 * N];
int lazy[4 * N];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        if (a[tl] >= 0)
        {
            t[v] = {-N, a[tl]};
        }
        else
        {
            t[v] = {a[tl], N};
        }
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

void push(int v, int tl, int tr)
{
    if (lazy[v])
    {
        t[v].negmx += lazy[v];
        t[v].posmin += lazy[v];
        if (tl < tr)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void addpos(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        lazy[v]++;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    addpos(2 * v, tl, tm, l, r);
    addpos(2 * v + 1, tm + 1, tr, l, r);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void addneg(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl || t[v].negmx < 0)
    {
        return;
    }
    if (tl == tr)
    {
        t[v].negmx = -N;
        t[v].posmin = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    addneg(2 * v, tl, tm, l, r);
    addneg(2 * v + 1, tm + 1, tr, l, r);
    t[v] = t[2 * v] + t[2 * v + 1];
}

int last0(int v, int tl, int tr)
{
    push(v, tl, tr);
    if (t[v].posmin > 0)
    {
        return 0;
    }
    if (tl == tr)
    {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int x = last0(2 * v + 1, tm + 1, tr);
    if (x == 0)
    {
        x = last0(2 * v, tl, tm);
    }
    return x;
}

void sim()
{
    build(1, 1, n);
    while (1)
    {
        int i = last0(1, 1, n);
        if (i)
        {
            p[++top] = i;
            addpos(1, 1, n, i, n);
            addneg(1, 1, n, i, n);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen ("input", "r", stdin);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= i;
    }
    sim();
    mnpre[1] = p[1];
    for (int i = 2; i <= top; i++)
    {
        mnpre[i] = min(mnpre[i - 1], p[i]);
    }
    vector<Q> qs;
    for (int i = 1; i <= q; i++)
    {
        int x, y, l, r;
        cin >> x >> y;
        l = x + 1;
        r = n - y;
        int lo = 1, hi = top, lim = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (mnpre[mid] >= l)
            {
                lim = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        qs.push_back({i, lim, r});
    }
    sort(qs.begin(), qs.end());
    int pos = 0;
    for (auto &it : qs)
    {
        while (pos < it.lim)
        {
            pos++;
            add(p[pos]);
        }
        sol[it.i] = cnt(it.r);
    }
    for (int i = 1; i <= q; i++)
    {
        cout << sol[i] << "\n";
    }
    cout << "\n";
}