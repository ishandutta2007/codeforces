#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#define N 200020
using namespace std;

class State
{
public:
    int l;
    int r;
    int i;

    State(int _l = 0, int _r = 0, int _i = 0) : l(_l), r(_r), i(_i)
    {
        return;
    }
};

class Value
{
public:
    long long x;
    long long y;

    Value(long long _x = 0, long long _y = 0) : x(_x), y(_y)
    {
        return;
    }

    bool operator<(Value that) const
    {
        return this -> x != that.x ? this -> x < that.x : this -> y > that.y;
    }
};

pair<long long, long long> a[N];
vector<pair<long long, long long> > v;
Value f[N];
State q[N];
int l, r;

long long Ceil(long long x, long long y)
{
    return (x + y - 1) / y;
}

Value Cost(int x, int y)
{
    long long t;

    t = Ceil(a[y].first - f[x].y, a[x].second);

    return Value(f[x].x + t, f[x].y + t * a[x].second - a[y].first);
}

int BSFind(int x, int n)
{
    int l, m, r;

    for(l = x, r = n; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(Cost(x, m) < Cost(q[::r - 1].i, m))
            r = m;
        else
            l = m;
    }

    return r;
}

int main(void)
{
    int n;
    int i, p;

    scanf("%d", &n);
    scanf("%lld", &a[n].first);
    a[n].second = LLONG_MAX;
    for(i = 0; i < n; i ++)
        scanf("%lld %lld", &a[i].second, &a[i].first);
    n ++;
    sort(a, a + n);
    for(i = 0; i < n; i ++)
    {
        if(!v.empty() && v.back().first == a[i].first)
            v.pop_back();
        else if(!v.empty() && v.back().second >= a[i].second)
            continue;
        v.push_back(a[i]);
    }

    copy(v.begin(), v.end(), a);
    n = (int)v.size();
    // a[n].first = s;
    // for(i=0;i<n;i++)printf("[%d,%d] ",a[i].first,a[i].second);puts("");

    q[r ++] = State(1, n - 1, 0);
    for(i = 1; i < n; i ++)
    {
        // f[i].x = LLONG_MAX;
        // for(int j = 0; j < i; j ++)
        //     if(Cost(j, i) < f[i])
        //     {
        //         f[i] = Cost(j, i);
        //         p = j;
        //     }
        // printf("%d : %d\n", i, p);
        // printf("%d : at least %lld time, left %lld\n", i, f[i].x, f[i].y);
        for(; l < r && q[l].r < i; l ++)
            ;
        if(l == r)
            throw;

        f[i] = Cost(q[l].i, i);
        for(; l < r && q[r - 1].l > i && Cost(i, q[r - 1].l) < Cost(q[r - 1].i, q[r - 1].l); r --)
            ;
        if(l == r)
            throw;

        p = BSFind(i, n);
        if(p != n)
        {
            q[r - 1].r = p - 1;
            q[r ++] = State(p, n - 1, i);
        }
    }
    printf("%lld\n", f[n - 1].x);

    return 0;
}