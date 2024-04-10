#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct request
{
    char d; int p, v;
};

bool cmp(request a, request b)
{
    return a.p < b.p;
}

bool acmp(request a, request b)
{
    return a.p > b.p;
}

bool canunite(request a, request b)
{
    return (a.d == b.d) && (a.p == b.p);
}

request unite(request a, request b)
{
    request c; c.d = a.d; c.p = a.p; c.v = a.v + b.v; return c;
}

int geti()
{
    int d; scanf("%d", &d); return d;
}

char getc()
{
    char c = 0; while (c <= ' ') c = getchar(); return c;
}

request getr()
{
    request d; d.d = getc(), d.p = geti(), d.v = geti(); return d;
}

int main()
{
    int n = geti(), m = geti();
    vector<request> s, b;
    for (int i = 0; i < n; i++)
    {
        request r = getr();
        if (r.d == 'S') s.push_back(r); else b.push_back(r);
    }
    sort(s.begin(), s.end(), cmp);
    sort(b.begin(), b.end(), acmp);
    vector<request> s1, b1;
    if (s.size() != 0)
    {
        s1.push_back(s[0]);
        for (int i = 1; i < s.size(); i++)
            if (canunite(s1[s1.size() - 1], s[i]))
                s1[s1.size() - 1] = unite(s1[s1.size() - 1], s[i]);
            else
                s1.push_back(s[i]);
    }
    if (b.size() != 0)
    {
        b1.push_back(b[0]);
        for (int i = 1; i < b.size(); i++)
            if (canunite(b1[b1.size() - 1], b[i]))
                b1[b1.size() - 1] = unite(b1[b1.size() - 1], b[i]);
            else
                b1.push_back(b[i]);
    }
    for (int i = min(m, (int)s1.size()) - 1; i >= 0; i--)
    {
        if (i != min(m, (int)s1.size()) - 1) printf("\n");
        printf("%c %d %d", s1[i].d, s1[i].p, s1[i].v);
    }
    for (int i = 0; i < min(m, (int)b1.size()); i++)
    {
        if (i != 0 || s1.size() != 0) printf("\n");
        printf("%c %d %d", b1[i].d, b1[i].p, b1[i].v);
    }
}