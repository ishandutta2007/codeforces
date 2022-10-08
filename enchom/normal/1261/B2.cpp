#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool SA(pair<int,int> A, pair<int,int> B)
{
    if (A.first != B.first)
        return A.first > B.first;
    else
        return A.second < B.second;
}

int n,m;
pair<int,int> a[200111];
int avals[200111];

int pos[200111];
pair<int,int> queries[200111];

int IT[800111];
int LEAFOFFSET;

int answers[200111];

void enable(int ind)
{
    ind += LEAFOFFSET;
    IT[ind] = 1;
    ind /= 2;

    while(ind > 0)
    {
        IT[ind] = IT[2*ind] + IT[2*ind+1];
        ind /= 2;
    }

    return;
}

int recPos(int ver, int L, int R, int pos)
{
    if (L == R)
        return L;

    int mid = (L + R) / 2;

    if (IT[2*ver] >= pos)
        return recPos(2*ver, L, mid, pos);
    else
    {
        pos -= IT[2*ver];
        return recPos(2*ver+1, mid+1, R, pos);
    }
}

int getPos(int pos)
{
    return recPos(1, 1, LEAFOFFSET+1, pos);
}

int main()
{
    int i,j;

    scanf("%d",&n);

    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i].first);
        a[i].second = i;

        avals[i] = a[i].first;
    }

    scanf("%d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&queries[i].first,&pos[i]);

        queries[i].second = i;
    }

    sort(a+1,a+1+n,SA);
    sort(queries+1,queries+1+m);

    int cur = 1;

    for (i=1;i<=n;i++)
    {
        enable(a[i].second);

        while(cur <= m && queries[cur].first == i)
        {
            answers[ queries[cur].second ] = getPos(pos[ queries[cur].second ]);
            cur++;
        }
    }

    for (i=1;i<=m;i++)
    {
        printf("%d\n",avals[ answers[i] ]);
    }

    return 0;
}