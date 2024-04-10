#include <stdio.h>
#include <stdlib.h>

int get()
{
    char c = 0; while (c <= ' ') c = getchar();
    int ans = 0;
    while (c > ' ')
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}

void put(long long n)
{
    if (n)
    {
        long long mp = (long long)1e18;
        while (!(n / mp)) mp /= 10;
        while (mp)
        {
            putchar('0' + n / mp);
            n %= mp;
            mp /= 10;
        }
    }
    else putchar('0');
}

const int maxN = 200000, maxK = 500000;

int v[maxN];
bool used[maxN];

int numSet[maxK];
int numsIn = 0;

int nLst[maxK], sLst[maxK];
int lstSz;

long long res = 0;

void doGenList(int *dl, int dlSz, int rest, int sign)
{
    if (dlSz)
    {
        doGenList(dl + 1, dlSz - 1, rest, sign);
        doGenList(dl + 1, dlSz - 1, rest * dl[0], -sign);
    }
    else
    {
        nLst[lstSz] = rest;
        sLst[lstSz] = sign;
        lstSz++;
    }
}

void genList(int n)
{
    int dl[60]; int dlSz = 0;
    lstSz = 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            dl[dlSz++] = i;
            n /= i;
        }
    if (n != 1) dl[dlSz++] = n;
    doGenList(dl, dlSz, 1, -1);
}

int getCount(int n)
{
    int res = 0;
    for (int i = 0; i < lstSz; i++)
        if (nLst[i] != 1) res += (numSet[nLst[i]] * sLst[i]);
    return numsIn - res;
}

void include(int n)
{
    numsIn++;
    for (int i = 0; i < lstSz; i++)
        if (nLst[i] != 1) numSet[nLst[i]]++;
}

void exclude(int n)
{
    numsIn--;
    for (int i = 0; i < lstSz; i++)
        if (nLst[i] != 1) numSet[nLst[i]]--;
}

int main()
{
    int n = get(), q = get();
    for (int i = 0; i < n; i++)
    {
        int a = get();
        for (int i = 2; i * i <= a; i++)
            while (a % (i * i) == 0) a /= i;
        v[i] = a;
    }
    for (int i = 0; i < q; i++)
    {
        int a = get() - 1;
        genList(v[a]);
        if (used[a])
        {
            exclude(v[a]);
            res -= getCount(v[a]);
        }
        else
        {
            res += getCount(v[a]);
            include(v[a]);
        }
        used[a] = !used[a];
        put(res);
        puts("");
    }
}