#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct node
{
    int val;
    int updval;
};

int n,m;
int a[200001];
vector<int> Graph[200001];
int Real[200001];
int Last[200001];
bool TFO[200001];
int L=0;
node IndexTree[2000001];
int LEAFOFFSET;

void UPDCHECK(int ver)
{
    if (IndexTree[ver].updval!=0 && ver<=LEAFOFFSET)
    {
        IndexTree[2*ver].updval+=IndexTree[ver].updval;
        IndexTree[2*ver+1].updval+=IndexTree[ver].updval;

        if (ver*2>LEAFOFFSET)
        {
            IndexTree[2*ver].val+=IndexTree[ver].updval;
            IndexTree[2*ver+1].val-=IndexTree[ver].updval;
        }
        else
        {
            IndexTree[2*ver].val+=IndexTree[ver].updval;
            IndexTree[2*ver+1].val+=IndexTree[ver].updval;
        }


        IndexTree[ver].updval=0;
    }
}

void Add_Rec(int value,int l,int r,int L,int R,int ver)
{
    UPDCHECK(ver);

    if (R<l || L>r)
    {
        return;
    }
    else if (L>=l && R<=r)
    {
        ///cout<<"Vertex "<<ver<<" working at "<<L<<"~"<<R<<" being hit with "<<value<<endl;
        if (ver>LEAFOFFSET)
        {
            if (L%2==1)
            IndexTree[ver].val+=value;
            else
            IndexTree[ver].val-=value;
        }
        else
        {
            IndexTree[ver].val+=value;
            IndexTree[ver].updval=value;
        }

    }
    else
    {
        Add_Rec(value,l,r,L,(L+R)/2,ver*2);
        Add_Rec(value,l,r,(L+R)/2+1,R,ver*2+1);
    }
}

void Add(int value,int l,int r)
{
    Add_Rec(value,l,r,1,LEAFOFFSET+1,1);
    return;
}

void DFS(int ver)
{
    if (TFO[ver])
    return;

    TFO[ver]=true;

    L++;
    Real[ver]=L;
    Last[ver]=L;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        if (TFO[Graph[ver][i]])
        continue;

        DFS(Graph[ver][i]);

        L++;
        Last[ver]=L;
    }

    return;
}

void MakeReal_Rec(int ver,int goal,int L,int R)
{
    int mid=(L+R)/2;

    UPDCHECK(ver);

    if (L==R)
    return;

    if (goal<=mid)
    {
        MakeReal_Rec(2*ver,goal,L,mid);
    }
    else
    {
        MakeReal_Rec(2*ver+1,goal,mid+1,R);
    }
}

int GetVal(int ver)
{
    MakeReal_Rec(1,ver,1,LEAFOFFSET+1);

    return IndexTree[ver+LEAFOFFSET].val;
}

void PrintTree()
{
    int i;

    for (i=1;i<=n;i++)
    {
        cout<<"Vertex "<<i<<" = "<<GetVal(Real[i])<<endl;
    }

    return;
}

int main()
{
    int i,j;
    int v1,v2;
    int cm,x,val;

    for (i=0;i<=2000000;i++)
    {
        IndexTree[i].val=0;
        IndexTree[i].updval=0;
    }

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i=1;i<=n-1;i++)
    {
        scanf("%d %d",&v1,&v2);

        Graph[v1].push_back(v2);
        Graph[v2].push_back(v1);
    }

    DFS(1);

    LEAFOFFSET=1;
    while(LEAFOFFSET<L)
    LEAFOFFSET*=2;

    LEAFOFFSET--;

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&cm,&x);

        if (cm==1)
        {
            scanf("%d",&val);

            if (Real[x]%2==0)
            val=-val;

            ///cout<<"Updating "<<Real[x]<<" to "<<Last[x]<<" by "<<val<<endl;
            Add(val,Real[x],Last[x]);

            ///PrintTree();
        }
        else
        {
            printf("%d\n",GetVal(Real[x])+a[x]);
        }
    }

    return 0;
}

/**
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4
**/