#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long Int;

Int n,m,d;
bool marked[100001];
vector<Int> Graph[100001];
Int MaxDistDown[100001];
Int MaxDistUp[100001];
Int Max1Down[100001];
Int Max2Down[100001];
Int Max1ID[100001];
Int Max2ID[100001];

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

void DFS1(Int ver,Int dad)
{
    Int i;
    Int childval;
    Int d;

    Max1Down[ver]=-1;
    Max2Down[ver]=-1;

    if (!marked[ver])
    MaxDistDown[ver]=-1;
    else
    {
        MaxDistDown[ver]=0;
        Max1Down[ver]=0;
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        DFS1(Graph[ver][i],ver);

        childval=MaxDistDown[ Graph[ver][i] ];

        if (childval!=-1)
        {
            MaxDistDown[ver]=MAX(MaxDistDown[ver],childval+1);

            childval++;
            if (childval>Max1Down[ver])
            {
                Max2Down[ver]=Max1Down[ver];
                Max2ID[ver]=Max1ID[ver];

                Max1Down[ver]=childval;
                Max1ID[ver]=Graph[ver][i];
            }
            else if (childval>Max2Down[ver])
            {
                Max2Down[ver]=childval;
                Max2ID[ver]=Graph[ver][i];
            }
        }
    }

    ///cout<<"MaxDistDown["<<ver<<"]="<<MaxDistDown[ver]<<endl;
    ///cout<<"Max1Down["<<ver<<"]="<<Max1Down[ver]<<endl;
    ///cout<<"Max2Down["<<ver<<"]="<<Max2Down[ver]<<endl;
    ///cout<<"Max1ID["<<ver<<"]="<<Max1ID[ver]<<endl;
    ///cout<<"Max2ID["<<ver<<"]="<<Max2ID[ver]<<endl<<endl;

    return;
}

void DFS2(Int ver,Int dad)
{
    Int i;
    Int val1,val2;

    if (dad!=0)
    {
        ///cout<<"Computing MaxDistUp val for "<<ver<<endl;

        val1=MaxDistUp[dad]+1;

        if (Max1Down[dad]!=0)
        {
            if (Max1ID[dad]==ver)
            {
                if (Max2Down[dad]!=-1)
                val2=Max2Down[dad]+1;
                else
                val2=-1;
            }
            else
            {
                val2=Max1Down[dad]+1;
            }
        }
        else
        {
            val2=1;
        }

        if (Max1Down[dad]==-1 && MaxDistUp[dad]==-1)
        {
            ///cout<<"Dead end -1"<<endl;
            MaxDistUp[ver]=-1;
        }
        else if (Max1Down[dad]==-1)
        {
            ///cout<<"Father's kids are useless, going for the stars"<<endl;
            MaxDistUp[ver]=MaxDistUp[dad]+1;
            ///cout<<"MaxDistUp["<<ver<<"]="<<MaxDistUp[ver]<<endl;
        }
        else if (MaxDistUp[dad]==-1)
        {
            ///cout<<"The sky is full of clouds, our brothers are useful though"<<endl;
            MaxDistUp[ver]=val2;
            ///cout<<"MaxDistUp["<<ver<<"]="<<val2<<endl;
        }
        else
        {
            ///cout<<"Fight between the land and sky"<<endl;
            MaxDistUp[ver]=MAX(val2,MaxDistUp[dad]+1);
            ///cout<<"MaxDistUp["<<ver<<"]="<<MaxDistUp[ver]<<endl;
        }

        ///cout<<endl;
    }
    else
    {
        MaxDistUp[ver]=-1;
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i]==dad)
        continue;

        DFS2(Graph[ver][i],ver);
    }

    return;
}

int main()
{
    Int i;
    Int v;
    Int ctr=0;
    Int a,b;

    memset(marked,false,sizeof(marked));

    scanf("%I64d %I64d %I64d",&n,&m,&d);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&v);

        marked[v]=true;
    }

    for (i=1;i<=n-1;i++)
    {
        scanf("%I64d %I64d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    DFS1(1,0);

    DFS2(1,0);

    for (i=1;i<=n;i++)
    {
        if (MAX(MaxDistDown[i],MaxDistUp[i])<=d)
        {
            ctr++;
        }
    }

    printf("%I64d\n",ctr);

    return 0;
}