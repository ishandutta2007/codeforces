#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long Int;

struct team
{
    Int players;
    Int a,b,c;

    bool operator<( const team& other ) const
    {
        return players>other.players;
    }
};

team teams[101];
Int tL=0;
vector<Int> Graph[101];
Int Component[101];
Int cL;
bool TFO[101];

void DFS(Int ver)
{
    if (TFO[ver])
    return;

    cL++;
    Component[cL]=ver;
    TFO[ver]=true;

    Int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);
    }

    return;
}

int main()
{
    Int n,m;
    Int i;
    Int a,b;

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    for (i=0;i<=100;i++)
    {
        TFO[i]=false;
    }

    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            cL=0;
            DFS(i);

            if (cL>3)
            {
                printf("-1\n");
                return 0;
            }
            else if (cL==3)
            {
                tL++;
                teams[tL].players=3;
                teams[tL].a=Component[1];
                teams[tL].b=Component[2];
                teams[tL].c=Component[3];
            }
            else if (cL==2)
            {
                tL++;
                teams[tL].players=2;
                teams[tL].a=Component[1];
                teams[tL].b=Component[2];
            }
            else
            {
                tL++;
                teams[tL].players=1;
                teams[tL].a=Component[1];
            }
        }
    }

    sort(teams+1,teams+1+tL);

    while(teams[tL].players==1)
    {
        for (i=1;i<=tL-1;i++)
        {
            if (teams[i].players==2)
            {
                teams[i].players=3;
                teams[i].c=teams[tL].a;
                tL--;
                break;
            }
            else if (teams[i].players==1)
            {
                teams[i].players=2;
                teams[i].b=teams[tL].a;
                tL--;
                break;
            }
        }
    }

    for (i=1;i<=tL;i++)
    {
        if (teams[i].players!=3)
        {
            printf("-1\n");
            return 0;
        }
    }

    for (i=1;i<=tL;i++)
    {
        printf("%I64d %I64d %I64d\n",teams[i].a,teams[i].b,teams[i].c);
    }

    return 0;
}