#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;
#define INF 999999999

struct tower
{
    Int h;
    Int x;
};

Int father[100001];
Int n;
tower towers[100001];
Int stak[100001];
Int sL=0;
vector<Int> Graph[100001];
vector<Int> ans;

///LCA
Int In[100001];
Int First[100001];
Int WhoIs[100001];
Int InCtr=0;
Int VisitArray[300001];
Int vL=0;

Int Tree[1048576];
Int LEAFOFFSET;

Int CP(Int x1,Int y1,Int x2,Int y2)
{
    return x1*y2-x2*y1;
}

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool IsFine(Int a,Int b,Int c)
{
    Int x1,y1,x2,y2,x3,y3;

    x1=towers[a].x;
    y1=towers[a].h;

    x2=towers[b].x;
    y2=towers[b].h;

    x3=towers[c].x;
    y3=towers[c].h;

    if ( CP(x2-x1,y2-y1,x3-x1,y3-y1)>0 )
    return true;
    else
    return false;
}

void DFS(Int ver)
{
    Int i;

    InCtr++;
    In[ver]=InCtr;
    WhoIs[InCtr]=ver;

    vL++;
    VisitArray[vL]=In[ver];
    First[ver]=vL;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i]);

        vL++;
        VisitArray[vL]=In[ver];
    }

    return;
}

Int GetMIN_rec(Int ver,Int L,Int R,Int l,Int r)
{
    if (R<l || L>r)
    {
        return INF;
    }
    else if (L>=l && R<=r)
    {
        return Tree[ver];
    }
    else
    {
        return MIN( GetMIN_rec(2*ver,L,(L+R)/2,l,r) , GetMIN_rec(2*ver+1,(L+R)/2+1,R,l,r) );
    }
}

Int GetMIN(Int l,Int r)
{
    return GetMIN_rec(1,1,LEAFOFFSET+1,l,r);
}

int main()
{
    Int i;
    Int a,b,c;
    Int q;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&towers[i].x,&towers[i].h);
    }

    sL=1;
    stak[1]=n;
    for (i=n-1;i>=1;i--)
    {
        while(sL>1)
        {
            if ( IsFine(i,stak[sL],stak[sL-1]) )
            {
                sL--;
            }
            else
            break;
        }

        Graph[ stak[sL] ].push_back(i);
        sL++;
        stak[sL]=i;
    }

    DFS(n);

    LEAFOFFSET=1;
    while(vL>LEAFOFFSET)
    {
        LEAFOFFSET*=2;
    }
    LEAFOFFSET--;

    for (i=1;i<=LEAFOFFSET*2+1;i++)
    {
        Tree[i]=INF;
    }

    for (i=1;i<=vL;i++)
    {
        Tree[LEAFOFFSET+i]=VisitArray[i];
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        Tree[i]=MIN(Tree[2*i],Tree[2*i+1]);
    }

    scanf("%I64d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d",&a,&b);

        if (First[a]>First[b])
        {
            c=a;
            a=b;
            b=c;
        }

        ans.push_back( WhoIs[ GetMIN(First[a],First[b]) ] );
    }

    for (i=0;i<(Int)ans.size();i++)
    {
        printf("%I64d",ans[i]);

        if (i!=(Int)ans.size()-1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
/**
6
1 4
2 1
3 2
4 3
6 4
7 4
**/