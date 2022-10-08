#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;
///
const Int LEAFOFFSET=1023;

struct Fenwick2D
{
    Int Tree2D[2048][2048];

    void Init()
    {
        memset(Tree2D,0,sizeof(Tree2D[0][0])*2048*2048);
    }

    void Update2(Int tr,Int ver,Int v)
    {
        Int ind=ver+LEAFOFFSET;

        Tree2D[tr][ind]=Tree2D[tr][ind]^v;
        ind/=2;

        while(ind>0)
        {
            Tree2D[tr][ind]=Tree2D[tr][2*ind]^Tree2D[tr][2*ind+1];

            ind/=2;
        }

        return;
    }

    void Update(Int x,Int y,Int v)
    {
        Int ind=y+LEAFOFFSET;

        while(ind>0)
        {
            Update2(ind,x,v);

            ind/=2;
        }

        return;
    }

    Int Query2(Int tr,Int ver)
    {
        Int ind=ver+LEAFOFFSET;
        Int XORSUM;

        XORSUM=Tree2D[tr][ind];

        while(ind>1)
        {
            if (ind%2==1)
            {
                XORSUM=XORSUM^Tree2D[tr][ind-1];
            }

            ind/=2;
        }

        return XORSUM;
    }

    Int Query(Int x,Int y)
    {
        Int ind=y+LEAFOFFSET;
        Int XORSUM;

        XORSUM=Query2(ind,x);

        while(ind>1)
        {
            if (ind%2==1)
            {
                XORSUM=XORSUM^Query2(ind-1,x);
            }

            ind/=2;
        }

        return XORSUM;
    }
};

Int n,q;
Fenwick2D Trees[4];

void UPD(Int x,Int y,Int v)
{
    if (x==0 || y==0)
    return;

    if (x%2==0 && y%2==0)
    {
        Trees[0].Update(x,y,v);
    }
    else if (x%2==0 && y%2==1)
    {
        Trees[1].Update(x,y,v);
    }
    else if (x%2==1 && y%2==0)
    {
        Trees[2].Update(x,y,v);
    }
    else
    {
        Trees[3].Update(x,y,v);
    }
}

Int Q(Int x,Int y)
{
    if (x==0 || y==0)
    return 0;

    if (x%2==0 && y%2==0)
    {
        return Trees[0].Query(x,y);
    }
    else if (x%2==0 && y%2==1)
    {
        return Trees[1].Query(x,y);
    }
    else if (x%2==1 && y%2==0)
    {
        return Trees[2].Query(x,y);
    }
    else
    {
        return Trees[3].Query(x,y);
    }
}

int main()
{
    Int i;
    Int cm;
    Int x1,y1,x2,y2;
    Int v;
    Int ans;

    for (i=0;i<=3;i++)
    {
        Trees[i].Init();
    }

    scanf("%I64d %I64d",&n,&q);

    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d %I64d %I64d %I64d",&cm,&x1,&y1,&x2,&y2);

        if (cm==1)
        {
            ans=Q(x2,y2)^Q(x2,y1-1)^Q(x1-1,y2)^Q(x1-1,y1-1);
            printf("%I64d\n",ans);
        }
        else
        {
            scanf("%I64d",&v);

            UPD(x1,y1,v);
            UPD(x2+1,y1,v);
            UPD(x1,y2+1,v);
            UPD(x2+1,y2+1,v);
        }
    }

    return 0;
}