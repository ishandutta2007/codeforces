#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector<int> Graph[100111];
bool Linear[100111];
bool StronglyLinear[100111];
int FNL=-1;
vector<int> Kids[100111];

void DFS(int ver,int dad)
{
    int i;
    int kids=0;

    Linear[ver]=true;
    StronglyLinear[ver]=true;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        Kids[ver].push_back(Graph[ver][i]);

        kids++;
        DFS(Graph[ver][i],ver);

        StronglyLinear[ver]=(StronglyLinear[ver]&&StronglyLinear[ Graph[ver][i] ]);
        Linear[ver]=(Linear[ver]&&StronglyLinear[ Graph[ver][i] ]);
    }

    if (kids>2)
    Linear[ver]=false;
    if (kids>1)
    StronglyLinear[ver]=false;

    return;
}

/**
state values:
0 - all is free, one line occupy
1 - all free, one line occupied but direction settled
**/

bool Okay(int ver,int state)
{
    int i;
    int NonLinears=0;
    int Strong=0,Regular=0;
    vector<int> NLK;

    for (i=0;i<Kids[ver].size();i++)
    {
        if (!Linear[ Kids[ver][i] ])
        {
            NonLinears++;
            NLK.push_back(Kids[ver][i]);
        }
        else
        {
            if (StronglyLinear[ Kids[ver][i] ])
            Strong++;
            else
            Regular++;
        }
    }

    if (NonLinears==0)
    return true;
    if (NonLinears>2)
    return false;

    if (state==0)
    {
        if (NonLinears==2)
        return ( Okay(NLK[0],3)&&Okay(NLK[1],3) );

        if (Strong<=1 && Regular==0)
        return Okay(NLK[0],1);
        else
        return Okay(NLK[0],2);
    }
    else if (state==1)
    {
        if (NonLinears==2)
        return ( Okay(NLK[0],3)&&Okay(NLK[1],3) );

        if (Strong==0 && Regular==0)
        return Okay(NLK[0],1);
        else if (Strong==1 && Regular==0)
        return Okay(NLK[0],2);
        else
        return Okay(NLK[0],3);
    }
    else if (state==2)
    {
        if (NonLinears==2)
        return ( Okay(NLK[0],3)&&Okay(NLK[1],3) );
        else
        return Okay(NLK[0],3);
    }
    else if (state==3)
    {
        if (NonLinears==2)
        return false;
        else
        return Okay(NLK[0],3);
    }
}

int main()
{
    int i;
    int a,b;

    scanf("%d",&n);

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    DFS(1,0);

    if (Okay(1,0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}