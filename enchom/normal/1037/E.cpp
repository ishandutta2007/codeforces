#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m,k;
pair<int,int> edges[500111];

vector<int> unknown;
int activeCounter = 0;
int status[500111];

int friends[500111];

vector<int> toKill;

vector<int> Graph[500111];

vector<int> winners[41];
vector<int> losers[41];

void forceSolve(int l, int mid, int dep)
{
    int i,j;

    toKill.clear();

    for (i=l;i<=mid;i++)
    {
        Graph[ edges[i].first ].push_back(edges[i].second);
        Graph[ edges[i].second ].push_back(edges[i].first);

        //cout<<"Add edge "<<edges[i].first<<"~"<<edges[i].second<<endl;
    }

    for (i=0;i<unknown.size();i++)
    {
        int ver = unknown[i];

        friends[ver] = 0;

        for (j=0;j<Graph[ver].size();j++)
        {
            if (status[ Graph[ver][j] ] != 2)
                friends[ver]++;
        }

        //cout<<"Initially "<<ver<<" has "<<friends[ver]<<" friends"<<endl;

        if (friends[ver] < k)
        {
            toKill.push_back(ver);
        }
    }

    while(!toKill.empty())
    {
        int ver = toKill.back();
        toKill.pop_back();

        //cout<<ver<<" killed"<<endl;

        for (i=0;i<Graph[ver].size();i++)
        {
            if (status[ Graph[ver][i] ] == 3)
            {
                friends[ Graph[ver][i] ]--;
                //cout<<"reducing "<<Graph[ver][i]<<endl;
                if (friends[ Graph[ver][i] ] == k-1)
                {
                    //cout<<"on the line for execution is "<<Graph[ver][i]<<endl;
                    toKill.push_back(Graph[ver][i]);
                }
            }
        }
    }

    winners[dep].clear();
    losers[dep].clear();
    for (i=0;i<unknown.size();i++)
    {
        int ver = unknown[i];

        if (friends[ver] < k)
            losers[dep].push_back(ver);
        else
            winners[dep].push_back(ver);
    }

    for (i=l;i<=mid;i++)
    {
        Graph[ edges[i].first ].pop_back();
        Graph[ edges[i].second ].pop_back();
    }
}

int ANS[500111];

void solve(int l,int r,int dep)
{
    if (l > r)
        return;

    int mid = (l+r) / 2;
    int i;

    //cout<<"Solving "<<l<<"~"<<r<<endl;

    forceSolve(l, mid, dep);

    ANS[mid] = activeCounter + winners[dep].size();

    /*cout<<"ANSWER DETERMINED TO BE "<<ANS[mid]<<" for "<<mid<<endl;
    cout<<"Losers = {";
    for (i=0;i<losers[dep].size();i++)
    {
        cout<<losers[dep][i]<<",";
    }
    cout<<"}"<<endl;
    cout<<"Winners = {";
    for (i=0;i<winners[dep].size();i++)
    {
        cout<<winners[dep][i]<<",";
    }
    cout<<"}"<<endl;

    cout<<"--------------------------------------------------------"<<endl;*/

    if (l == r)
        return;

    unknown.clear();

    for (i=0;i<winners[dep].size();i++)
    {
        unknown.push_back(winners[dep][i]);
    }

    for (i=0;i<losers[dep].size();i++)
    {
        status[ losers[dep][i] ] = 2;
    }

    solve(l, mid-1, dep+1);

    for (i=0;i<winners[dep].size();i++)
    {
        unknown.pop_back();
        status[ winners[dep][i] ] = 1;
        activeCounter++;
    }

    for (i=0;i<losers[dep].size();i++)
    {
        unknown.push_back(losers[dep][i]);
        status[ losers[dep][i] ] = 3;
    }

    for (i=l;i<=mid;i++)
    {
        Graph[ edges[i].first ].push_back(edges[i].second);
        Graph[ edges[i].second ].push_back(edges[i].first);
    }

    solve(mid+1, r, dep+1);

    for (i=l;i<=mid;i++)
    {
        Graph[ edges[i].first ].pop_back();
        Graph[ edges[i].second ].pop_back();
    }

    for (i=0;i<winners[dep].size();i++)
    {
        status[ winners[dep][i] ] = 3;
        activeCounter--;

        unknown.push_back(winners[dep][i]);
    }
}

int main()
{
    //freopen("test.txt","r",stdin);

    int i;

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&edges[i].first,&edges[i].second);
    }

    for (i=1;i<=n;i++)
    {
        unknown.push_back(i);
        status[i] = 3;
    }

    solve(1, m, 0);

    for (i=1;i<=m;i++)
    {
        printf("%d\n",ANS[i]);
    }

    return 0;
}