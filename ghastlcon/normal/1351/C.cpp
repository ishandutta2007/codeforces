#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#define N 100020
using namespace std;

char a[N];
set<pair<pair<int, int>, pair<int, int> > > f;

int main(void)
{
    int t;
    int i, x, y, p, q, o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%s", a);
        f.clear();
        for(i = o = x = y = 0; a[i]; i ++)
        {
            p = x;
            q = y;
            if(a[i] == 'S')
                x ++;
            else if(a[i] == 'N')
                x --;
            else if(a[i] == 'E')
                y ++;
            else
                y --;
            o += f.count(make_pair(min(make_pair(p, q), make_pair(x, y)), max(make_pair(p, q), make_pair(x, y)))) ? 1 : 5;
            f.insert(make_pair(min(make_pair(p, q), make_pair(x, y)), max(make_pair(p, q), make_pair(x, y))));
        }
        printf("%d\n", o);
    }

    return 0;
}