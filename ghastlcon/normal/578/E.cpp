#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#define N 100020
using namespace std;

char a[N];
set<int> f[2];

int main(void)
{
    int n;
    int i, p, r, o;
    vector<int> v;
    set<int>::iterator t;

    scanf("%s", a);
    n = (int)strlen(a);
    if(n & 1)
        p = find(a, a + n, count(a, a + n, 'L') > n / 2 ? 'L' : 'R') - a;
    else
        p = 0;

    for(i = 0; i < n; i ++)
        if(i != p)
            f[a[i] == 'R'].insert(i);
    v.push_back(p);
    for(i = 1, o = 0; i < n; i ++)
    {
        r = a[p] == 'L';
        t = f[r].upper_bound(p);
        if(t == f[r].end() || (f[!r].upper_bound(*t) == f[!r].end() && *f[r].begin() < p && *f[r].begin() < *f[!r].begin()))
        {
            t = f[r].begin();
            o ++;
        }
        p = *t;
        f[r].erase(t);
        v.push_back(p);
    }
    printf("%d\n", o);
    for(i = 0; i < n; i ++)
        printf("%d%c", v[i] + 1, " \n"[i == n - 1]);

    return 0;
}