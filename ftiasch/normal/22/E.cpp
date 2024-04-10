// Codeforces Beta Round #22
// Problem E -- Scheme
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

#define N 100000

using namespace std;

int n, f[N], d[N], q[N], l[N], ie[N], oe[N];
vector<pair<int, int> > a;

int main()
{
    scanf("%d", &n);
    memset(d, 0, sizeof(d));
    for(int i = 0; i != n; ++ i)
        scanf("%d", f + i), d[-- f[i]] ++;
    int hd = 0, tl = 0, lf = 0;
    for(int i = 0; i != n; ++ i)
        if(!d[i])
            q[tl ++] = i, lf ++;
    while(hd != tl)
        if(!(-- d[f[q[hd ++]]]))
            q[tl ++] = f[q[hd - 1]];
    memset(l, -1, sizeof(l));
    int sz = 0;
    for(int i = 0; i != n; ++ i)
        if(d[i] && l[i] == -1)
        {
            l[ie[sz] = oe[sz] = i] = sz;
            for(int j = f[i]; j != i; j = f[j])
                l[j] = sz;
            sz ++;
        }
    for(int i = tl - 1; i != -1; -- i)
        ie[l[q[i]] = l[f[q[i]]]] = q[i];
    if(!lf && sz == 1)
        printf("0\n");
    else
    {
        a.clear();
        memset(d, 0, sizeof(d));
        for(int i = 0; i != n; ++ i)
            d[f[i]] ++;
        for(int i = 0; i != n; ++ i)
            if(!d[i] && ie[l[i]] != i)
                a.push_back(make_pair(oe[l[i]], i));
        for(int i = 0; i != sz; ++ i)
            a.push_back(make_pair(oe[i], ie[(i + 1) % sz]));
        printf("%d\n", a.size());
        for(vector<pair<int, int> >::iterator iter = a.begin(); iter != a.end(); ++ iter)
            printf("%d %d\n", iter->first + 1, iter->second + 1);
    }
    return 0;
}