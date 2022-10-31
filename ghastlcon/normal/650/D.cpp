#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 800020
using namespace std;

class Question
{
public:
    int v;
    int l;
    int r;
    int i;
};

int a[N];
vector<Question> q[N];
vector<int> v;
int l[N], r[N], f[N], c[N];
int o[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void SetFenwick(int p, int v)
{
    for(; p <= (signed)::v.size(); p += Lowbit(p))
        f[p] = max(f[p], v);

    return;
}

int MaxFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o = max(o, f[p]);

    return o;
}

int main(void)
{
    int n, m, p, x;
    int i, j, o;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    for(i = 1; i <= m; i ++)
    {
        scanf("%d %d", &p, &x);
        q[p].push_back((Question){x, 0, 0, i});
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 1; i <= n; i ++)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).v = lower_bound(v.begin(), v.end(), q[i].at(j).v) - v.begin() + 1;
    }

    for(i = 1, o = 0; i <= n; i ++)
    {
        l[i] = MaxFenwick(a[i] - 1) + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).l = MaxFenwick(q[i].at(j).v - 1) + 1;
        SetFenwick(a[i], l[i]);
        o = max(o, l[i]);
    }
    memset(f, 0, sizeof(f));
    for(i = n; i >= 1; i --)
    {
        r[i] = MaxFenwick(v.size() - a[i]) + 1;
        for(j = 0; j < (signed)q[i].size(); j ++)
            q[i].at(j).r = MaxFenwick(v.size() - q[i].at(j).v) + 1;
        SetFenwick(v.size() - a[i] + 1, r[i]);
    }

    for(i = 1; i <= n; i ++)
        if(l[i] + r[i] - 1 == o)
            c[l[i]] ++;
    // for(i=1;i<=n;i++)printf("%d ",l[i]);puts("");
    // for(i=1;i<=n;i++)printf("%d ",r[i]);puts("");

    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)q[i].size(); j ++)
            ::o[q[i].at(j).i] = max(l[i] + r[i] - 1 == o && c[l[i]] == 1 ? o - 1 : o, q[i].at(j).l + q[i].at(j).r - 1);
    for(i = 1; i <= m; i ++)
        printf("%d\n", ::o[i]);

    return 0;
}