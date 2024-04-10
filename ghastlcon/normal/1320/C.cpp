#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#define N 200020
using namespace std;

class Point
{
public:
    int x;
    int y;
    int c;

    Point(int _x = 0, int _y = 0, int _c = 0) : x(_x), y(_y), c(_c)
    {
        return;
    }

    bool operator<(Point that)
    {
        return this -> x < that.x;
    }
};

pair<int, int> a[N], b[N];
Point c[N];
vector<pair<int, int> > v;
pair<int, int> f[N << 2];

void Orderize(pair<int, int> *a, int &n)
{
    int i;

    v.clear();
    sort(a, a + n);
    for(i = 0; i < n; i ++)
    {
        for(; !v.empty() && v.back().second >= a[i].second; v.pop_back())
            ;
        v.push_back(a[i]);
    }
    n = (int)v.size();
    for(i = 0; i < n; i ++)
        a[i] = v[i];

    return;
}

void MaintainSegment(int x)
{
    f[x << 1    ].first  += f[x].second;
    f[x << 1 | 1].first  += f[x].second;
    f[x << 1    ].second += f[x].second;
    f[x << 1 | 1].second += f[x].second;
    f[x].second = 0;

    return;
}

void AddSegment(int x, int l, int r, int s, int t, int v)
{
    int m;

    if(l > t || r < s)
        return;
    if(l >= s && r <= t)
    {
        f[x].first  += v;
        f[x].second += v;

        return;
    }
    if(f[x].second)
        MaintainSegment(x);

    m = (l + r) >> 1;
    AddSegment(x << 1    , l    , m, s, t, v);
    AddSegment(x << 1 | 1, m + 1, r, s, t, v);
    f[x].first = max(f[x << 1].first, f[x << 1 | 1].first);

    return;
}

int main(void)
{
    int n, m, p;
    int i, j, t, o;

    scanf("%d %d %d", &n, &m, &p);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &a[i].first, &a[i].second);
    for(i = 0; i < m; i ++)
        scanf("%d %d", &b[i].first, &b[i].second);
    Orderize(a, n);
    Orderize(b, m);
    // for(i=0;i<n;i++)printf("[%d,%d] ",a[i].first,a[i].second);puts("");
    // for(i=0;i<m;i++)printf("[%d,%d] ",b[i].first,b[i].second);puts("");

    for(i = 0; i < p; i ++)
    {
        scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].c);
        c[i].x ++;
        c[i].y ++;
    }
    sort(c, c + p);

    for(i = 0; i < m; i ++)
        AddSegment(1, 0, m - 1, i, i, -b[i].second);
    for(i = j = 0, o = INT_MIN; i < n; i ++)
    {
        for(; j < p && c[j].x <= a[i].first; j ++)
            AddSegment(1, 0, m - 1, lower_bound(b, b + m, make_pair(c[j].y, -1)) - b, m - 1, c[j].c);
        // printf("at %d : %d\n", i, f[1].first);
        o = max(o, f[1].first - a[i].second);
    }
    printf("%d\n", o);

    return 0;
}