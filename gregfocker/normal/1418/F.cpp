#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 70;
int t[4 * N];

void upd(int v, int tl, int tr, int i, int x)
{
    if (tr < i || i < tl)
    {
        return;
    }
    if (tl == tr)
    {
        t[v] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i, x);
    upd(2 * v + 1, tm + 1, tr, i, x);
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        return N;
    }
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int n;
int m;
int len;
ll first;
ll last;
vector<int> d[N];
int pos[N];
ll asol[N];
ll bsol[N];
int l[N];
int r[N];

void upd(int i, int x)
{
    upd(1, 1, len, i, x);
}

int get(int l, int r)
{
    return get(1, 1, len, l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m >> first >> last;
    len = max(n, m);
    for (int i = 1; i <= len; i++)
    {
        for (int j = i; j <= len; j += i)
        {
            d[j].push_back(i);
        }
        upd(i, 1);
    }
    for (int i = 1; i <= len; i++)
    {
        d[i].push_back(N);
    }
    for (ll x = 1; x <= len; x++)
    {
        l[x] = min((ll) m + 1, max((ll) 1, (first + x - 1) / x));
        r[x] = max((ll) 0, min((ll) m, last / x));
    }
    for (int b = 1; b <= len; b++)
    {
        for (int x = b; x <= len; x += b)
        {
            upd(x, d[x][++pos[x]]);
        }
        for (int x = b; x <= len; x += b)
        {
            if (l[x] > r[x])
            {
                continue;
            }
            int a = get(l[x], r[x]);
            if (a != N && (ll) a * x <= (ll) n * b)
            {
                asol[x] = a;
                bsol[x] = b;
            }
        }
    }
    for (ll x1 = 1; x1 <= n; x1++)
    {
        ll as = asol[x1];
        ll bs = bsol[x1];
        if (as == 0)
        {
            cout << "-1\n";
            continue;
        }
        ll x2 = as * x1 / bs;
        ll y1;
        if (l[x1] % as == 0)
        {
            y1 = l[x1];
        }
        else
        {
            y1 = l[x1] + as - l[x1] % as;
        }
        ll y2 = bs * y1 / as;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    }
}