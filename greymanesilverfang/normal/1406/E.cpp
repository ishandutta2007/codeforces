#include <cstdio>
#include <vector>

int A(int x)
{
    printf("A %d\n", x);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int B(int x)
{
    printf("B %d\n", x);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

void C(int x)
{
    printf("C %d\n", x);
    fflush(stdout);
    return;
}

int solve(const std::vector<std::vector<int>> &v)
{
    int res = 1;
    for (const std::vector<int> &u : v)
    {
        B(u[0]);
        int l = 0, r = u.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (A(u[m]))
                l = m + 1;
            else 
                r = m - 1;
        }
        if (r >= 0)
            res *= u[r];
    }
    return res;
}

int cur;
int solve(const std::vector<int> &v)
{
    if (v.empty())
        return 1;
    int lim = (v.size() + 1) / 2;
    int old = cur;
    for (int i = 0; i < lim; ++i)
        old -= B(v[i]);
    cur = A(1);
    if (old != cur)
        for (int i = 0; i < lim; ++i)
            if (A(v[i]))
                return v[i];
    std::vector<int> u(v.begin() + lim, v.end());
    return solve(u);
}

int solve(int n)
{
    cur = n;
    std::vector<std::vector<int>> l;
    std::vector<int> r;
    for (int i = 2; i <= n; ++i)
    {
        bool isPrime = true;
        for (int j = 2; j <= i / j; ++j)
            if (i % j == 0)
                isPrime = false;
        if (!isPrime)
            continue;
        if (i <= n / i)
        {
            l.resize(l.size() + 1);
            for (int j = i; j <= n; j *= i)
                l.back().push_back(j);
        }
        else 
            r.push_back(i);
    }
    int rgt = solve(r);
    int lft = solve(l);
    return lft * rgt;
}

int main()
{
    int n; scanf("%d", &n);
    C(solve(n));
}