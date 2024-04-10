#include <bits/stdc++.h>

using namespace std;

const int typeA = 0; // 0 -> 1
const int typeB = 1; // 1 -> 0
int A[100001];

struct ttab
{
    int v[2];
};

vector<ttab> seg;

struct flip
{
    int atLeast, type;
};

ttab combine(ttab a, ttab b)
{
    ttab c;
    c.v[0] = b.v[a.v[0]];
    c.v[1] = b.v[a.v[1]];
    return c;
}

ttab ans[100001];

void init(int idx, int begin, int end)
{
    if (begin == end)
    {
        seg[idx].v[0] = 0;
        seg[idx].v[1] = 1;
    }
    else
    {
        int mid = (begin + end) / 2;
        init(idx * 2, begin, mid);
        init(idx * 2 + 1, mid + 1, end);
        seg[idx] = combine(seg[idx * 2], seg[idx * 2 + 1]);
    }
}

void insert(int idx, int begin, int end, int x, ttab v)
{
    if (x < begin || end < x)
    {
        return;
    }
    if (begin == end)
    {
        seg[idx] = v;
    }
    else
    {
        int mid = (begin + end) / 2;
        insert(idx * 2, begin, mid, x, v);
        insert(idx * 2 + 1, mid + 1, end, x, v);
        seg[idx] = combine(seg[idx * 2], seg[idx * 2 + 1]);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
    }
    vector<vector<pair<ttab, int>>> ev;
    ev.resize(100005);
    vector<flip> f;
    int ff = 0;
    for (int i = 0; i < m; i++)
    {
        char c;
        int x;
        scanf(" %c%d", &c, &x);
        ttab t;
        t.v[0] = 0;
        t.v[1] = 1;
        if (c == '<')
        {
            if (x < 0)
            {
                t.v[1] = 0;
                ev[-x+1].push_back({t, i+1});
            }
            else
            {
                t.v[0] = 1;
                t.v[1] = 0;
                ev[0].push_back({t, i+1});
                t.v[0] = 0;
                t.v[1] = 0;
                ev[x].push_back({t, i+1});
            }
        }
        else
        {
            if (x > 0)
            {
                t.v[0] = 1;
                ev[x+1].push_back({t, i+1});
            }
            else
            {
                t.v[0] = 1;
                t.v[1] = 0;
                ev[0].push_back({t, i+1});
                t.v[0] = 1;
                t.v[1] = 1;
                ev[-x].push_back({t, i+1});
            }
        }
    }
    seg.resize(m * 4);
    init(1, 1, m);
    int idx = 0;
    for (int i = 0; i <= 100000; i++)
    {
        for (auto it: ev[i])
        {
            insert(1, 1, m, it.second, it.first);
        }
        ans[i] = seg[1];
    }
    for (int i = 0; i < n; i++)
    {
        int s, v;
        s = (A[i] < 0);
        v = s ? -A[i] : A[i];
        printf("%d ", ans[v].v[s] ? -v : v);
    }
    printf("\n");
}