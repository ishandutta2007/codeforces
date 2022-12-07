#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct lem
{
    int m, v, id;
};

bool operator < (const lem &a, const lem &b)
{
    if (a.m != b.m)
        return (a.m < b.m);
    return a.v < b.v;
}

vector<lem> s;
int n, k, h, ans[100000], cur[100000];
lem ll;

int main(void)
{
    int i, j, p;
    scanf("%d%d%d", &n, &k, &h);
    s.reserve(n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &ll.m);
        ll.id = i + 1;
        s.push_back(ll);
    }
    for (i = 0; i < n; ++i)
        scanf("%d", &s[i].v);
    sort(s.begin(), s.end());
    double l = 0, r = 1e9 + 5, t;
    for (i = 0; i < 100; ++i)
    {
        t = (l + r) / 2;
        p = 1;
        for (j = 0; j < n; ++j)
            if (s[j].v * t >= h * 1ll * p)
            {
                cur[p++ - 1] = j;
                if (p == k + 1)
                    break;
            }
        if (p == k + 1)
        {
            for (j = 0; j < k; ++j)
                ans[j] = cur[j];
            r = t;
        }
        else
            l = t;
    }
    for (i = 0; i < k; ++i)
        printf("%d ", s[ans[i]].id);
    return 0;
}