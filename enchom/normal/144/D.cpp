#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct edge
{
    Int v1,v2,val;
};

struct gr
{
    Int ver,val;
};

vector<gr> Graph[100001];
Int Distances[100001];
bool TFO[100001];
gr Heap[500001];
Int whereis[500001];
Int n,m,s;
vector<edge> edges;

void Update(Int ind)
{
    Int papa=ind/2;
    Int v1,v2;
    Int d;

    while(papa>0)
    {
        if (Heap[papa].val>Heap[ind].val)
        {
            v1=Heap[papa].ver;
            v2=Heap[ind].ver;

            d=whereis[v1];
            whereis[v1]=whereis[v2];
            whereis[v2]=d;

            d=Heap[papa].val;
            Heap[papa].val=Heap[ind].val;
            Heap[ind].val=d;

            d=Heap[papa].ver;
            Heap[papa].ver=Heap[ind].ver;
            Heap[ind].ver=d;
        }
        else
        {
            break;
        }

        ind=papa;
        papa=ind/2;
    }

    return;
}

gr RemoveTop()
{
    gr ret=Heap[1];
    Int dad,son1,son2;
    Int v1,v2,d;

    Heap[1].val=999999999;

    dad=1;
    son1=2;
    son2=3;

    while(dad<=200000)
    {
        if (Heap[son1].val<Heap[son2].val)
        {
            v1=Heap[dad].ver;
            v2=Heap[son1].ver;

            d=whereis[v1];
            whereis[v1]=whereis[v2];
            whereis[v2]=d;

            d=Heap[dad].val;
            Heap[dad].val=Heap[son1].val;
            Heap[son1].val=d;

            d=Heap[dad].ver;
            Heap[dad].ver=Heap[son1].ver;
            Heap[son1].ver=d;

            dad=son1;
        }
        else
        {
            v1=Heap[dad].ver;
            v2=Heap[son2].ver;

            d=whereis[v1];
            whereis[v1]=whereis[v2];
            whereis[v2]=d;

            d=Heap[dad].val;
            Heap[dad].val=Heap[son2].val;
            Heap[son2].val=d;

            d=Heap[dad].ver;
            Heap[dad].ver=Heap[son2].ver;
            Heap[son2].ver=d;

            dad=son2;
        }

        son1=dad*2;
        son2=dad*2+1;
    }

    return ret;
}

void Djikstra(Int sver)
{
    Int i,j;
    Int nver;
    gr top;

    for (i=0;i<=100000;i++)
    {
        TFO[i]=false;
    }

    for (i=0;i<=500000;i++)
    {
        Heap[i].val=999999999;
        Heap[i].ver=i;
        whereis[i]=i;
    }

    Distances[s]=0;
    Heap[s].val=0;
    Update(s);

    for (i=1;i<=n;i++)
    {
        top=RemoveTop();

        Distances[top.ver]=top.val;

        TFO[top.ver]=true;

        for (j=0;j<Graph[top.ver].size();j++)
        {
            nver=Graph[top.ver][j].ver;

            if (!TFO[nver])
            {
                if (Heap[ whereis[nver] ].val > top.val+Graph[top.ver][j].val)
                {
                    Heap[ whereis[nver] ].val=top.val+Graph[top.ver][j].val;
                    Update(whereis[nver]);
                }
            }
        }
    }

    return;
}

int main()
{
    Int i;
    Int a,b,c;
    gr help;
    Int dist;
    edge help2;
    Int V1,V2,VAL;
    Int p1,p2;
    Int counter=0;
    Int d2;

    scanf("%I64d %I64d %I64d",&n,&m,&s);

    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d",&a,&b,&c);

        help2.v1=a;
        help2.v2=b;
        help2.val=c;
        edges.push_back(help2);

        help.ver=a;
        help.val=c;

        Graph[b].push_back(help);

        help.ver=b;

        Graph[a].push_back(help);
    }

    scanf("%I64d",&dist);

    Djikstra(s);

    for (i=0;i<edges.size();i++)
    {
        V1=edges[i].v1;
        V2=edges[i].v2;
        VAL=edges[i].val;

        p1=-1;
        if (VAL+Distances[V1]>=dist && Distances[V1]<dist) ///Try out the first one
        {
            p1=dist-Distances[V1];
            d2=VAL-p1+Distances[V2];

            if (d2>=dist && p1!=VAL && p1!=0)
            {
                counter++;
            }
        }

        if (VAL+Distances[V2]>=dist && Distances[V2]<dist)
        {
            p2=VAL-(dist-Distances[V2]);
            d2=p2+Distances[V1];

            if (d2>=dist && p2!=0 && p2!=VAL)
            {
                if (p1!=p2)
                {
                    counter++;
                }
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        if (Distances[i]==dist)
        {
            counter++;
        }
    }

    printf("%I64d\n",counter);

    return 0;
}