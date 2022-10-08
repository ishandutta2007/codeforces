#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;

int n,m,p;

struct monst
{
    int A,D;
    int win;

    bool operator<(const monst &other) const
    {
        return make_pair(A,make_pair(D,win)) < make_pair(other.A,make_pair(other.D,other.win));
    }
};

pair<int,int> att[200111];
pair<int,int> def[200111];

pair<int,int> attack[200111];
pair<int,int> defense[200111];
int L;

monst monsters[200111];

llong IT[800111];
llong lg[800111];
int LEAFOFFSET = 1;

void Refresh(int ver)
{
    if (lg[ver] != 0)
    {
        IT[ver] += lg[ver];
        if (ver <= LEAFOFFSET)
        {
            lg[2*ver] += lg[ver];
            lg[2*ver+1] += lg[ver];
        }
        lg[ver] = 0;
    }
}

llong getMax()
{
    Refresh(1);
    return IT[1];
}

void recAdd(int ver,int L,int R,int l,int r,int val)
{
    Refresh(ver);

    if (L > r || R < l)
        return;
    else if (L >= l && R <= r)
    {
        lg[ver] = val;
        Refresh(ver);
    }
    else
    {
        recAdd(2*ver, L, (L+R)/2, l, r, val);
        recAdd(2*ver+1, (L+R)/2+1, R, l, r, val);
        IT[ver] = max(IT[2*ver], IT[2*ver+1]);
    }
}

void add(int ind, int val)
{
    recAdd(1, 1, LEAFOFFSET+1, ind, m, val);
}

int getDefense(int d)
{
    int l = 1, r = m, mid, best = -1;

    while(l <= r)
    {
        mid = (l + r) / 2;

        if (defense[mid].first > d)
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return best;
}

int main()
{
    int i,j;

    scanf("%d %d %d",&n,&m,&p);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&att[i].first,&att[i].second);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&def[i].first,&def[i].second);
    }

    for (i=1;i<=p;i++)
    {
        scanf("%d %d %d",&monsters[i].A,&monsters[i].D,&monsters[i].win);
    }

    sort(att+1,att+1+n);
    L = 1;
    attack[1] = att[1];
    for (i=2;i<=n;i++)
    {
        if (att[i].first == attack[L].first)
            continue;

        while(L > 0 && attack[L].second >= att[i].second)
            L--;
        L++;
        attack[L] = att[i];
    }
    n = L;

    sort(def+1,def+1+m);
    L = 1;
    defense[1] = def[1];
    for (i=2;i<=m;i++)
    {
        if (def[i].first == defense[L].first)
            continue;

        while(L > 0 && defense[L].second >= def[i].second)
            L--;
        L++;
        defense[L] = def[i];
    }
    m = L;

    sort(monsters+1,monsters+1+p);

    LEAFOFFSET = 1;
    while(LEAFOFFSET < m)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    for (i=1;i<=m;i++)
    {
        IT[i + LEAFOFFSET] = -defense[i].second;
    }
    for (i=LEAFOFFSET+m+1;i<=2*LEAFOFFSET+1;i++)
    {
        IT[i] = -1000000001LL;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i] = max(IT[2*i], IT[2*i+1]);
    }

    llong ans = - attack[1].second - defense[1].second;

    int mp = 1;
    for (i=1;i<=n;i++)
    {
        int curAtt = attack[i].first;
        int curOffset = attack[i].second;

        while(mp <= p && monsters[mp].A < curAtt)
        {
            int ind = getDefense(monsters[mp].D);

            if (ind != -1)
                add(ind, monsters[mp].win);

            mp++;
        }

        llong score = getMax() - curOffset;

        ans = max(ans, score);
    }

    printf("%lld\n",ans);

    return 0;
}