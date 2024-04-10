#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

int n, k;
vector<int> Graph[200111];

int papa[200111];
int inCtr = 0;
int inVal[200111];
int inLast[200111];
bool dead[200111];

pair<int, int> IT[800111];
int lg[800111];
int LEAFOFFSET;

void DFS(int ver, int dad)
{
    int i;

    inCtr++;
    inVal[ver] = inCtr;
    papa[ver] = dad;
    IT[LEAFOFFSET + inCtr] = make_pair(0, ver);

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i] == dad)
            continue;

        DFS(Graph[ver][i], ver);
    }

    inLast[ver] = inCtr;
}

void Refresh(int ver)
{
    if (lg[ver] != 0)
    {
        IT[ver].first += lg[ver];
        if (ver <= LEAFOFFSET)
        {
            lg[2*ver] += lg[ver];
            lg[2*ver+1] += lg[ver];
        }
        lg[ver] = 0;
    }
}

void recAdd(int ver, int L, int R, int l, int r, int v)
{
    Refresh(ver);

    if (L > r || R < l)
        return;
    else if (L >= l && R <= r)
    {
        lg[ver] += v;
        Refresh(ver);
    }
    else
    {
        recAdd(2*ver, L, (L+R)/2, l, r, v);
        recAdd(2*ver+1, (L+R)/2+1, R, l, r, v);

        if (IT[2*ver].first > IT[2*ver+1].first)
            IT[ver] = IT[2*ver];
        else
            IT[ver] = IT[2*ver+1];
    }
}

void addVal(int L, int R, int v)
{
    recAdd(1, 1, LEAFOFFSET+1, L, R, v);
}

llong calc(llong r, llong b)
{
    return (n - r - b) * (r - b);
}

int main()
{
    int i, j;

    scanf("%d %d", &n, &k);

    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    for (i=1;i<n;i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    DFS(1, 0);

    for (i=1;i<=n;i++)
    {
        addVal(inVal[i], inLast[i], 1);
    }

    llong ans = calc(0, n / 2);
    int bluesLeft = n;

    for (i=1;i<=k;i++)
    {
        int bestVer = IT[1].second;
        int bestBlocks = IT[1].first;

        bluesLeft -= bestBlocks;
        while(bestVer > 0 && !dead[bestVer])
        {
            //printf("Killing %d\n", bestVer);
            addVal(inVal[bestVer], inLast[bestVer], -1);
            dead[bestVer] = true;
            bestVer = papa[bestVer];
        }

        int blueChoice = min(bluesLeft, n / 2);

        //printf("Red taking %d leaves %d for blue who chooses %d, yielding score %lld\n", i, bluesLeft, blueChoice, calc(i, blueChoice));

        ans = max(ans, calc(i, blueChoice));
    }

    printf("%lld\n", ans);

    return 0;
}