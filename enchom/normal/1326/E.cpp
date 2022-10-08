#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int p[300111];
int q[300111];
int whereis[300111];

struct node
{
    int sum = 0;
    int maxsuf = 0;
    int minpref = 0;

    node(): sum(0), maxsuf(0), minpref(0) {}
};

node mergeNodes(node A, node B)
{
    node C;

    C.sum = A.sum + B.sum;
    C.maxsuf = max(B.maxsuf, A.maxsuf + B.sum);
    C.minpref = min(A.minpref, A.sum + B.minpref);

    return C;
}

node IT[1200111];
int LEAFOFFSET;
int maxbomb;

node minPrefRec(int ver, int L, int R, int l, int r)
{
    if (L > r || R < l)
    {
        node empt;
        return empt;
    }
    else if (L >= l && R <= r)
    {
        return IT[ver];
    }
    else
    {
        return mergeNodes( minPrefRec(2*ver, L, (L+R)/2, l, r), minPrefRec(2*ver+1, (L+R)/2+1, R, l, r) );
    }
}

int getMinPref(int L)
{
    node r = minPrefRec(1, 1, LEAFOFFSET+1, L, n);
    return r.minpref;
}

node maxSufRec(int ver, int L, int R, int l, int r)
{
    if (L > r || R < l)
    {
        node empt;
        return empt;
    }
    else if (L >= l && R <= r)
    {
        return IT[ver];
    }
    else
    {
        return mergeNodes(maxSufRec(2*ver, L, (L+R)/2, l, r), maxSufRec(2*ver+1, (L+R)/2+1, R, l, r));
    }
}

int getMaxSuf(int R)
{
    node r = maxSufRec(1, 1, LEAFOFFSET+1, 1, R);
    return r.maxsuf;
}

bool isDead(int cur)
{
    int pos = whereis[cur];
    int bmbs = -getMinPref(pos);
    int safety = getMaxSuf(pos-1);

    //cout<<"testing "<<cur<<endl;
    //cout<<"has "<<bmbs<<" bombs and "<<safety<<" safety"<<endl;

    return bmbs > safety;
}

void changeVal(int ind, int val)
{
    ind += LEAFOFFSET;

    IT[ind].sum += val;
    IT[ind].maxsuf += val;
    IT[ind].minpref += val;
    ind /= 2;

    while(ind > 0)
    {
        IT[ind] = mergeNodes(IT[2*ind], IT[2*ind+1]);
        ind /= 2;
    }
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
        scanf("%d",&p[i]);
        whereis[ p[i] ] = i;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&q[i]);
    }

    int curAlive = n;

    for (i=1;i<=n;i++)
    {
        //cout<<"Bomb "<<i<<endl;

        while(isDead(curAlive))
        {
            changeVal(whereis[curAlive], 1);
            curAlive--;
        }

        changeVal(q[i], -1);

        printf("%d",curAlive);
        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}