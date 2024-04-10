#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef int Int;

struct upd
{
    bool shouldupd;
    bool updval;
};

const Int LEAFOFFSET=524287;
bool IT[1048576];
bool TFO[500001];
vector<Int> Graph[500001];
Int n,q;
Int id=0;
upd ToUpd[1048576];
Int L[500001],R[500001],father[500001];

void DFS(Int ver)
{
    TFO[ver]=true;

    id++;
    L[ver]=id;

    Int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if ( !TFO[Graph[ver][i]] )
        {
            father[ Graph[ver][i] ]=ver;
            DFS(Graph[ver][i]);
        }
    }

    R[ver]=id;

    return;
}

void Update(Int ver,Int l,Int r,Int L,Int R,bool val)
{
    if (ToUpd[ver].shouldupd)
    {
        IT[ver]=ToUpd[ver].updval;
        ToUpd[ver].shouldupd=false;

        if (ver<=LEAFOFFSET)
        {
            ToUpd[2*ver].shouldupd=true;
            ToUpd[2*ver].updval=ToUpd[ver].updval;

            ToUpd[2*ver+1].shouldupd=true;
            ToUpd[2*ver+1].updval=ToUpd[ver].updval;
        }
    }

    if (R<l || L>r)
    {
        return;
    }
    else if (L>=l && R<=r)
    {
        ToUpd[ver].shouldupd=true;
        ToUpd[ver].updval=val;
        IT[ver]=val;

        ///cout<<"Interval "<<L<<"~"<<R<<" is "<<val<<"-ed"<<endl;

        return;
    }
    else
    {
        Update(2*ver,l,r,L,(L+R)/2,val);
        Update(2*ver+1,l,r,(L+R)/2+1,R,val);

        ///cout<<L<<"~"<<R<<" === "<<IT[2*ver]<<" "<<IT[2*ver+1]<<endl;
        IT[ver]=IT[2*ver]|IT[2*ver+1];
    }
}

bool Query(Int ver,Int l,Int r,Int L,Int R)
{
    if (ToUpd[ver].shouldupd)
    {
        IT[ver]=ToUpd[ver].updval;

        if (ver<=LEAFOFFSET)
        {
            ToUpd[2*ver].shouldupd=true;
            ToUpd[2*ver].updval=ToUpd[ver].updval;

            ToUpd[2*ver+1].shouldupd=true;
            ToUpd[2*ver+1].updval=ToUpd[ver].updval;
        }
    }

    if (R<l || L>r)
    {
        return false;
    }
    else if (L>=l && R<=r)
    {
        ///cout<<"Taking "<<L<<"~"<<R<<" which is "<<IT[ver]<<endl;
        return IT[ver];
    }
    else
    {
        return Query(2*ver,l,r,L,(L+R)/2) | Query(2*ver+1,l,r,(L+R)/2+1,R);
    }
}

bool RangeQuery(Int L,Int R)
{
    return Query(1,L,R,1,LEAFOFFSET+1);
}

void ElementUpdate(Int ver)
{
    Update(1,L[ver],L[ver],1,LEAFOFFSET+1,true);
}

void RangeUpdate(Int ver)
{
    if (RangeQuery(L[ver],R[ver]))
    {
        if (ver!=1)
        {
            Update(1,L[ father[ver] ],L[ father[ver] ],1,LEAFOFFSET+1,true);
        }
    }

    Update(1,L[ver],R[ver],1,LEAFOFFSET+1,false);
}

int main()
{
    Int i;
    Int c,v;
    Int a,b;

    memset(IT,true,sizeof(IT));
    memset(TFO,false,sizeof(TFO));

    scanf("%d",&n);

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);

        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    DFS(1);

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&c,&v);

        if (c==1)
        {
            RangeUpdate(v);
        }
        else if (c==2)
        {
            ElementUpdate(v);
        }
        else
        {
            if (!RangeQuery(L[v],R[v]))
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }

    return 0;
}