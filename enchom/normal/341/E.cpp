#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef int Int;

struct move
{
    Int b1,b2;
};

Int boxes[1001];
Int n;
vector<move> moves;
Int cb[4];
Int L;

void MakeMove(Int ind1,Int ind2)
{
    move help;

    help.b1=ind1;
    help.b2=ind2;

    moves.push_back(help);

    boxes[ind2]-=boxes[ind1];
    boxes[ind1]*=2;

    return;
}

void EmptyOneBox()
{
    Int A,B,C;
    Int i;
    Int d;
    Int q,r;
    Int curbit;

    if (boxes[ cb[1] ]==boxes[ cb[2] ])
    {
        MakeMove(cb[1],cb[2]);

        return;
    }
    if (boxes[ cb[1] ]==boxes[ cb[3] ])
    {
        MakeMove(cb[1],cb[3]);

        return;
    }
    if (boxes[ cb[2] ]==boxes[ cb[3] ])
    {
        MakeMove(cb[2],cb[3]);

        return;
    }

    if (boxes[ cb[1] ]>boxes[ cb[2] ])
    {
        d=cb[1];
        cb[1]=cb[2];
        cb[2]=d;
    }

    if (boxes[ cb[2] ]>boxes[ cb[3] ])
    {
        d=cb[2];
        cb[2]=cb[3];
        cb[3]=d;
    }

    if (boxes[ cb[1] ]>boxes[ cb[2] ])
    {
        d=cb[1];
        cb[1]=cb[2];
        cb[2]=d;
    }

    A=boxes[ cb[1] ];
    B=boxes[ cb[2] ];
    C=boxes[ cb[3] ];

    q=B/A;

    i=0;

    while(q>0)
    {
        curbit=q&(1<<i);

        if (curbit>0)
        {
            MakeMove(cb[1],cb[2]);
            B-=A;
            A=A*2;

            q=q-(1<<i);
        }
        else
        {
            MakeMove(cb[1],cb[3]);
            C-=A;
            A=A*2;
        }

        i++;
    }

    if (A!=0 && B!=0 && C!=0)
    {
        EmptyOneBox();
    }

    return;
}

int main()
{
    Int i;
    Int nonzero=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&boxes[i]);

        if (boxes[i]>0)
        nonzero++;
    }

    if (nonzero<2)
    {
        printf("-1\n");
        return 0;
    }

    L=3;
    while(L==3)
    {
        L=0;

        for (i=1;i<=n;i++)
        {
            if (boxes[i]!=0)
            {
                L++;
                cb[L]=i;

                if (L==3)
                {
                    break;
                }
            }
        }

        if (L==3)
        {
            EmptyOneBox();
        }
    }

    printf("%d\n",(Int)moves.size());

    for (i=0;i<moves.size();i++)
    {
        printf("%d %d\n",moves[i].b1,moves[i].b2);
    }

    return 0;
}