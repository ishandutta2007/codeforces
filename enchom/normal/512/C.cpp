#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n;
int nums[301];

vector<int> Graph[301];
int Flow[301][301];
int Cap[301][301];
int MaxFlow=0;
int SOURCE,SINK;

vector<int> Tables[301];
int tL=0;

void AddEdge(int a,int b)
{
    Graph[a].push_back(b);
    Graph[b].push_back(a);

    Cap[a][b]=1;
    Cap[b][a]=0;

    Flow[a][b]=0;
    Flow[b][a]=0;

    return;
}

bool Prime(int a)
{
    int i;

    for (i=2;i*i<=a;i++)
    {
        if (a%i==0)
        return false;
    }

    return true;
}

bool TFO[301];
vector<int> Path;

bool DFS(int ver)
{
    if (TFO[ver])
    return false;

    TFO[ver]=true;

    Path.push_back(ver);

    if (ver==SINK)
    return true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Flow[ver][ Graph[ver][i] ]<Cap[ver][ Graph[ver][i] ])
        {
            if (DFS(Graph[ver][i]))
            return true;
        }
    }

    Path.pop_back();

    return false;
}

void SendFlow()
{
    int i;

    for (i=0;i<(int)Path.size()-1;i++)
    {
        Flow[ Path[i] ][ Path[i+1] ]++;
        Flow[ Path[i+1] ][ Path[i] ]--;
    }

    MaxFlow++;

    return;
}

void Clear()
{
    memset(TFO,false,sizeof(TFO));
    Path.clear();

    return;
}

void GetTable(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;
    Tables[tL].push_back(ver);

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Flow[ver][ Graph[ver][i] ]!=0)
        {
            GetTable(Graph[ver][i]);
        }
    }

    return;
}

int main()
{
    int i,j;
    int evens=0,odds=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);

        if (nums[i]%2==0)
        evens++;
        else
        odds++;
    }

    if (evens!=odds)
    {
        printf("Impossible\n");
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (Prime(nums[i]+nums[j]))
            {
                if (nums[i]%2==0)
                {
                    AddEdge(i,j);
                }
                else
                {
                    AddEdge(j,i);
                }
            }
        }
    }

    SOURCE=n+1;
    SINK=n+2;

    for (i=1;i<=n;i++)
    {
        if (nums[i]%2==0)
        {
            Graph[SOURCE].push_back(i);
            Graph[i].push_back(SOURCE);

            Flow[SOURCE][i]=0;
            Flow[i][SOURCE]=0;

            Cap[SOURCE][i]=2;
            Cap[i][SOURCE]=0;
        }
        else
        {
            Graph[SINK].push_back(i);
            Graph[i].push_back(SINK);

            Flow[SINK][i]=0;
            Flow[i][SINK]=0;

            Cap[i][SINK]=2;
            Cap[SINK][i]=0;
        }
    }

    Clear();
    while(DFS(SOURCE))
    {
        SendFlow();

        Clear();
    }

    if (MaxFlow!=n)
    {
        printf("Impossible\n");
        return 0;
    }

    memset(TFO,false,sizeof(TFO));
    TFO[SINK]=true;
    TFO[SOURCE]=true;

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            tL++;
            GetTable(i);
        }
    }

    printf("%d\n",tL);

    for (i=1;i<=tL;i++)
    {
        printf("%d",Tables[i].size());

        for (j=0;j<Tables[i].size();j++)
        {
            printf(" %d",Tables[i][j]);
        }
        printf("\n");
    }

    return 0;
}