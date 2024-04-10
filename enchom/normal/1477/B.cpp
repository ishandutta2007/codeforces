#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

char s[200111];
char f[200111];
int n, q;
vector< pair<int, int> > qs;

int IT[800111];
int lazy[800111];
int LEAFOFFSET;

void Refresh(int ver, int sz)
{
    if (lazy[ver] != -1)
    {
        if (lazy[ver] == 0)
            IT[ver] = 0;
        else
            IT[ver] = sz;

        if (ver <= LEAFOFFSET)
        {
            lazy[2*ver] = lazy[ver];
            lazy[2*ver+1] = lazy[ver];
        }

        lazy[ver] = -1;
    }
}

void setRec(int ver, int L, int R, int l, int r, int val)
{
    Refresh(ver, R - L + 1);

    if (L > r || R < l)
        return;
    else if (L >= l && R <= r)
    {
        lazy[ver] = val;
        Refresh(ver, R - L + 1);
    }
    else
    {
        setRec(2*ver, L, (L+R)/2, l, r, val);
        setRec(2*ver+1, (L+R)/2+1, R, l, r, val);
        IT[ver] = IT[2*ver] + IT[2*ver+1];
    }
}

int getRec(int ver, int L, int R, int l, int r)
{
    Refresh(ver, R - L + 1);

    if (L > r || R < l)
        return 0;
    else if (L >= l && R <= r)
        return IT[ver];
    else
    {
        return getRec(2*ver, L, (L+R)/2, l, r) + getRec(2*ver+1, (L+R)/2+1, R, l, r);
    }
}

int getTotal(int l, int r)
{
    return getRec(1, 1, LEAFOFFSET+1, l, r);
}

void setAll(int l, int r, int val)
{
    setRec(1, 1, LEAFOFFSET+1, l, r, val);
}

int main()
{
    int t, test;
    int i, j;

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &q);

        scanf("%s", s+1);
        scanf("%s", f+1);

        qs.clear();
        for (i=1;i<=q;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            qs.push_back(make_pair(a, b));
        }

        LEAFOFFSET = 1;
        while(LEAFOFFSET < n)
            LEAFOFFSET *= 2;
        LEAFOFFSET--;

        for (i=0;i<=2*LEAFOFFSET+1;i++)
        {
            IT[i] = 0;
            lazy[i] = -1;
        }

        for (i=1;i<=n;i++)
        {
            if (f[i] == '1')
                IT[i + LEAFOFFSET] = 1;
        }

        for (i=LEAFOFFSET;i>=1;i--)
        {
            IT[i] = IT[2*i] + IT[2*i+1];
        }

        bool bad = false;
        for (i=(int)qs.size()-1;i>=0;i--)
        {
            int l = qs[i].first, r = qs[i].second;

            int ones = getTotal(l, r);
            int sz = r - l + 1;

            if (sz % 2 == 0 && ones == sz / 2)
            {
                bad = true;
                break;
            }

            if (ones > sz / 2)
            {
                setAll(l, r, 1);
            }
            else
            {
                setAll(l, r, 0);
            }
        }

        if (bad)
        {
            printf("NO\n");
            continue;
        }

        for (i=1;i<=n;i++)
        {
            if (getTotal(i, i) != s[i] - '0')
            {
                bad = true;
                break;
            }
        }

        if (bad)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}