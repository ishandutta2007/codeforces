#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#define N 520
using namespace std;

int a[N], b[N];

int main(void)
{
    int t, n;
    int i;
    multiset<pair<int, int> > f;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        for(i = 0; i < n; i ++)
            scanf("%d", &b[i]);

        if(n % 2 && a[n / 2] != b[n / 2])
            printf("No\n");
        else
        {
            f.clear();
            for(i = 0; i < n / 2; i ++)
                f.insert(make_pair(min(a[i], a[n - i - 1]), max(a[i], a[n - i - 1])));
            for(i = 0; i < n / 2; i ++)
            {
                if(!f.count(make_pair(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]))))
                    break;
                f.erase(f.find(make_pair(min(b[i], b[n - i - 1]), max(b[i], b[n - i - 1]))));
            }
            printf("%s\n", i < n / 2 ? "No" : "Yes");
        }
    }
    return 0;
}