#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <utility>
#define N 300020
using namespace std;

class Node
{
public:
    Node *s[2];
    int v;

    Node(int _v = 0) : v(_v)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

pair<pair<int, int>, int> a[N];
Node *r[N];
int f[N];

void SetSegment(Node *&x, Node *k, int l, int r, int p)
{
    int m;

    if(l == r)
    {
        x = new Node(f[l]);

        return;
    }

    m = (l + r) >> 1;
    x = new Node();
    if(p <= m)
    {
        SetSegment(x -> s[0], k -> s[0], l, m, p);
        x -> s[1] = k -> s[1];
    }
    else
    {
        SetSegment(x -> s[1], k -> s[1], m + 1, r, p);
        x -> s[0] = k -> s[0];
    }
    x -> v = max(x -> s[0] -> v, x -> s[1] -> v);

    return;
}

int MaxSegment(Node *x, int l, int r, int s, int t)
{
    int m;

    if(l > t || r < s)
        return 0;
    if(l >= s && r <= t)
        return x -> v;

    m = (l + r) >> 1;

    return max(MaxSegment(x -> s[0], l, m, s, t), MaxSegment(x -> s[1], m + 1, r, s, t));
}

int main(void)
{
    int n, m, k;
    int u, v, x, y;
    int i, p;

    scanf("%d %d %d", &n, &m, &k);
    for(i = 1; i <= k; i ++)
        scanf("%d %d %d", &a[i].first.first, &a[i].first.second, &a[i].second);
    for(i = 1; i <= n; i ++)
        f[i] = INT_MAX;
    sort(a + 1, a + k + 1);

    r[k + 1] = new Node(INT_MAX);
    r[k + 1] -> s[0] = r[k + 1] -> s[1] = r[k + 1];
    for(i = k; i >= 1; i --)
        if(f[a[i].second] > a[i].first.second)
        {
            f[a[i].second] = a[i].first.second;
            SetSegment(r[i], r[i + 1], 1, n, a[i].second);
        }
        else
            r[i] = r[i + 1];

    while(m --)
    {
        scanf("%d %d %d %d", &u, &v, &x, &y);
        p = lower_bound(a + 1, a + k + 1, make_pair(make_pair(x, -1), -1)) - a;
        if(p == k + 1)
            printf("no\n");
        else
            printf("%s\n", MaxSegment(r[p], 1, n, u, v) <= y ? "yes" : "no");
        fflush(stdout);
    }

    return 0;
}