#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#define N 100020
#define int unsigned long long
using namespace std;

int s;
int a[N];
map<int, int> f;
vector<pair<int, int> > v;

int Rand(void)
{
    int o;

    o = s;
    s = (s * 7 + 13) % 1000000007;

    return o;
}

int Power(int x, int y, int p)
{
    int o;

    x %= p;
    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = o * x % p;
        x = x * x % p;
    }

    return o % p;
}

void ClipODT(int l, int r)
{
    map<int, int>::iterator p, q;

    p = f.upper_bound(l);
    -- p;
    if(p -> first != l)
    {
        // puts("Detect");
        f[l] = p -> second;
    }

    q = f.upper_bound(r + 1);
    -- q;
    if(q -> first - 1 != r)
    {
        // puts("Detect");
        f[r + 1] = q -> second;
    }

    return;
}

void AddODT(int l, int r, int x)
{
    map<int, int>::iterator p, q;

    ClipODT(l, r);
    p = f.lower_bound(l    );
    q = f.lower_bound(r + 1);

    for(; p != q; ++ p)
        p -> second += x;

    return;
}

void SetODT(int l, int r, int x)
{
    map<int, int>::iterator p, q;

    ClipODT(l, r);
    // p = f.lower_bound(l    );
    // q = f.lower_bound(r + 1);
    f[l] = x;

    // printf("(%I64u, %I64u)\n", p -> first, p -> second);
    // if(p != q)
    //     for(++ p; p != q; ++ p)
    //     {
    //         printf("Erase %I64u\n", p -> first);
    //         f.erase(p);
    //     }
    while(true)
    {
        q = f.upper_bound(l);
        if(q -> first > r)
            break;
        f.erase(q);
    }

    return;
}

int KthODT(int l, int r, int k)
{
    map<int, int>::iterator p, q, x, t;
    int i;

    ClipODT(l, r);
    p = f.lower_bound(l    );
    q = f.lower_bound(r + 1);

    v.clear();
    for(t = x = p, ++ x; t != q; ++ t, ++ x)
        v.push_back(make_pair(t -> second, x -> first - t -> first));
    sort(v.begin(), v.end());

    for(i = 0; i < (signed)v.size(); i ++)
    {
        if(v.at(i).second >= k)
            return v.at(i).first;
        k -= v.at(i).second;
    }

    throw;
}

int SqrODT(int l, int r, int x, int y)
{
    map<int, int>::iterator p, q, t;
    int o;

    ClipODT(l, r);
    p = f.lower_bound(l    );
    q = f.lower_bound(r + 1);

    for(o = 0, t = p, ++ t; p != q; ++ p, ++ t)
    {
        // printf("Section %I64u : long %I64u\n", p -> second, t -> first - p -> first);
        o = (o + Power(p -> second, x, y) * (t -> first - p -> first) % y) % y;
    }

    return o;
}

signed main(void)
{
    int n, m, x;
    int p, l, r, a, b;
    int i;

    scanf("%I64u %I64u %I64u %I64u", &n, &m, &s, &x);
    for(i = 0; i < n; i ++)
    {
        ::a[i] = Rand() % x + 1;
        if(!i || ::a[i] != ::a[i - 1])
            f[i] = ::a[i];
    }
    f[n] = -1;

    // for(i = 0; i < n; i ++) cout << ::a[i] << ' '; cout << endl;

    while(m --)
    {
        p = Rand() % 4;
        l = Rand() % n;
        r = Rand() % n;
        if(l > r)
            swap(l, r);
        if(p == 2)
            a = Rand() % (r - l + 1) + 1;
        else
            a = Rand() % x + 1;
        if(p == 3)
            b = Rand() % x + 1;

        // printf("%I64u %I64u %I64u %I64u %I64u\n", p, l, r, a, b);

        switch(p)
        {
        case 0:
            AddODT(l, r, a);
            break;

        case 1:
            SetODT(l, r, a);
            break;

        case 2:
            printf("%I64u\n", KthODT(l, r, a));
            break;

        case 3:
            printf("%I64u\n", SqrODT(l, r, a, b));
            break;

        default:
            throw;
        }
    }

    return 0;
}