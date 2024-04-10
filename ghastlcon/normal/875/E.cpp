#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#define N 100020
#define INFINITE 1000000000
#pragma GCC optimize("O3")
using namespace std;

int n;
int a[N];
set<int> f;

bool Check(int x)
{
    int i;

    f.clear();
    f.insert(a[0]);
    for(i = 1;i < n + 2;i ++)
    {
        for(;!f.empty() && abs((*f. begin()) - a[i]) > x;f.erase(*f. begin()))
            ;
        for(;!f.empty() && abs((*f.rbegin()) - a[i]) > x;f.erase(*f.rbegin()))
            ;

        if(f.empty())
            return false;
        f.insert(a[i]);
    }

    return true;
}

int BSFind(void)
{
    int l, m, r;

    for(l = -1, r = INFINITE;l + 1 < r;)
        if(Check(m = (l + r) / 2))
            r = m;
        else
            l = m;

    return r;
}

int main() //2330.cpp
{
    int i;

    scanf("%d", &n);
    for(i = 0;i < n + 2;i ++)
        scanf("%d", &a[i]);
    printf("%d\n", BSFind());

    return 0;
}