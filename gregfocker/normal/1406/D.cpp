#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#define int ll

int ff(int a, int b)
{
    return max(0LL, a - b);
}

int gg(int a, int b)
{
    return -min(0LL, a - b);
}

const int N = (int) 1e5 + 7;

struct T
{
    int f;
    int g;
    int first;
    int last;
};

int n;
T t[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr)
{
    if (lazy[v])
    {
        t[v].first += lazy[v];
        t[v].last += lazy[v];
        if (tl < tr)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

T operator + (T a, T b)
{
    if (a.f == -1)
    {
        return b;
    }
    if (b.f == -1)
    {
        return a;
    }
    int f = a.f + b.f + ff(a.last, b.first);
    int g = a.g + b.g + gg(a.last, b.first);
    int first = a.first;
    int last = b.last;
    return {f, g, first, last};
}

void add(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        lazy[v] += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, x);
    add(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

void add(int l, int r, int x)
{
    add(1, 1, n, l, r, x);
}

pair<int, int> get()
{
    push(1, 1, n);
    return {t[1].g, t[1].f};
}

int a1;
int f;

int eval(int x)
{
    return max(a1 - x, x + f);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i == 1)
        {
            a1 = x;
        }
        add(i, i, x);
    }
    int q;
    cin >> q;
    pair<int, int> it = get();
  //  cout << it.first << " " << it.second << "\n";
    for (int i = 0; i <= q; i++)
    {
        if (i)
        {
            int l, r, x;
            cin >> l >> r >> x;
            if (l == 1)
            {
                a1 += x;
            }
            add(l, r, x);
        }
        pair<int, int> it = get();
        f = it.first;
        int op = (a1 - f) / 2;
        cout << min(eval(op), min(eval(op - 1), eval(op + 1))) << "\n";
      //  cout << it.first << " " << it.second << "\n";
    }
}