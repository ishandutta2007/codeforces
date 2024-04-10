#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct node
{
    int vals[3];
};

node IT[800111];
int LEAFOFFSET;
int n,q;

char s[200111];

node Merge(node a,node b)
{
    node c;
    int i;

    for (i=0;i<=2;i++)
    {
        c.vals[i] = a.vals[i] + b.vals[i];
    }

    return c;
}

int convert(char ch)
{
    if (ch == 'R')
        return 0;
    else if (ch == 'S')
        return 1;
    else
        return 2;
}

void update(int ind,int val)
{
    ind += LEAFOFFSET;
    IT[ind].vals[0] = 0;
    IT[ind].vals[1] = 0;
    IT[ind].vals[2] = 0;
    IT[ind].vals[val] = 1;

    ind /= 2;

    while(ind > 0)
    {
        IT[ind] = Merge(IT[2*ind], IT[2*ind+1]);
        ind /= 2;
    }

    return;
}

int firstRec(int ver,int shape)
{
    if (ver > LEAFOFFSET)
        return ver - LEAFOFFSET;

    if (IT[2*ver].vals[shape] > 0)
    {
        return firstRec(2*ver, shape);
    }
    else
    {
        return firstRec(2*ver+1, shape);
    }
}

int getFirst(int shape)
{
    if (IT[1].vals[shape] == 0)
        return n+1;
    else
        return firstRec(1,shape);
}

int lastRec(int ver,int shape)
{
    if (ver > LEAFOFFSET)
        return ver - LEAFOFFSET;

    if (IT[2*ver+1].vals[shape] > 0)
        return lastRec(2*ver+1, shape);
    else
        return lastRec(2*ver, shape);
}

int getLast(int shape)
{
    if (IT[1].vals[shape] == 0)
        return 0;
    else
        return lastRec(1,shape);
}

int sumRec(int ver,int L,int R,int l,int r,int shape)
{
    if (L > r || R < l)
        return 0;
    else if (L >= l && R <= r)
        return IT[ver].vals[shape];
    else
        return sumRec(2*ver,L,(L+R)/2,l,r,shape) + sumRec(2*ver+1,(L+R)/2+1,R,l,r,shape);
}

int getSum(int L, int R, int shape)
{
    return sumRec(1,1,LEAFOFFSET+1,L,R,shape);
}

pair<int,int> cross(pair<int,int> a,pair<int,int> b)
{
    pair<int,int> res;

    res = a;

    if (b.first > res.first)
        res.first = b.first;
    if (b.second < res.second)
        res.second = b.second;

    if (res.first < 1)
        res.first = 1;
    if (res.second > n)
        res.second = n;

    return res;
}

int countWinners(int shape)
{
    vector< pair<int,int> > leftFine;
    vector< pair<int,int> > rightFine;
    int loses = (shape-1+3) % 3;
    int beats = (shape+1) % 3;
    int indLoses, indBeats;
    int ans = 0;

    ///Lefts
    indLoses = getFirst(loses);
    indBeats = getFirst(beats);

    if (IT[LEAFOFFSET+1].vals[shape] == 1) //Is first
    {
        if (indLoses < indBeats)
        {
            leftFine.push_back(make_pair(1, indLoses-1));
            leftFine.push_back(make_pair(indBeats+1, n));
        }
        else
        {
            leftFine.push_back(make_pair(1, n));
        }
    }
    else
    {
        leftFine.push_back(make_pair(indBeats+1, n));
    }

    ///Rights
    indLoses = getLast(loses);
    indBeats = getLast(beats);

    if (IT[LEAFOFFSET+n].vals[shape] == 1) //Is last
    {
        if (indLoses > indBeats)
        {
            rightFine.push_back(make_pair(indLoses+1, n));
            rightFine.push_back(make_pair(1, indBeats-1));
        }
        else
        {
            rightFine.push_back(make_pair(1,n));
        }
    }
    else
    {
        rightFine.push_back(make_pair(1, indBeats-1));
    }

    int i,j;

    for (i=0;i<leftFine.size();i++)
    {
        for (j=0;j<rightFine.size();j++)
        {
            pair<int,int> interval = cross(leftFine[i], rightFine[j]);

            if (interval.first <= interval.second)
            ans += getSum(interval.first, interval.second, shape);
        }
    }

    return ans;
}

int getAnswer()
{
    int i;
    int ans = 0;

    for (i=0;i<=2;i++)
    {
        ans += countWinners(i);
    }

    return ans;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&q);

    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    scanf("%s",s+1);

    for (i=1;i<=n;i++)
    {
        IT[i+LEAFOFFSET].vals[ convert(s[i]) ] = 1;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i] = Merge(IT[2*i], IT[2*i+1]);
    }

    printf("%d\n",getAnswer());

    for (i=1;i<=q;i++)
    {
        char inp[4];
        int ind;

        scanf("%d",&ind);
        scanf("%s",inp);

        update(ind, convert(inp[0]));

        printf("%d\n",getAnswer());
    }

    return 0;
}