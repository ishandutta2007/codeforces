#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct intervaltree
{
    Int L,R;
    Int lnum,rnum;
    Int vals;
};

///524288~1048576
intervaltree IT[1048576];
const Int LEAFOFFSET=524287;
const Int MAXVAL=999999999;
Int n,q;
Int nums[300001];
Int total;
Int lastend;

void Q(Int ver,Int l,Int r)
{
    Int sl=IT[ver].L,sr=IT[ver].R;

    if (sr<l || sl>r)
    {
        return;
    }
    else if (sl>=l && sr<=r)
    {
        total+=IT[ver].vals;

        if (lastend<IT[ver].lnum)
        {
            total--;
        }

        lastend=IT[ver].rnum;

        return;
    }
    else
    {
        Q(2*ver,l,r);
        Q(2*ver+1,l,r);
    }
}

void Update(Int x,Int y)
{
    Int v1,v2;
    Int d;

    v1=x+LEAFOFFSET;
    v2=y+LEAFOFFSET;

    d=IT[v1].lnum;
    IT[v1].lnum=IT[v2].lnum;
    IT[v2].lnum=d;

    d=IT[v1].rnum;
    IT[v1].rnum=IT[v2].rnum;
    IT[v2].rnum=d;

    v1/=2;
    v2/=2;

    while(v1!=v2)
    {
        IT[v1].lnum=IT[v1*2].lnum;
        IT[v1].rnum=IT[v1*2+1].rnum;
        IT[v1].vals=IT[v1*2].vals+IT[v1*2+1].vals-1;
        if (IT[v1*2].rnum>IT[v1*2+1].lnum)
        {
            IT[v1].vals++;
        }

        IT[v2].lnum=IT[v2*2].lnum;
        IT[v2].rnum=IT[v2*2+1].rnum;
        IT[v2].vals=IT[v2*2].vals+IT[v2*2+1].vals-1;
        if (IT[v2*2].rnum>IT[v2*2+1].lnum)
        {
            IT[v2].vals++;
        }

        v1/=2;
        v2/=2;
    }

    while(v1>0)
    {
        IT[v1].lnum=IT[v1*2].lnum;
        IT[v1].rnum=IT[v1*2+1].rnum;
        IT[v1].vals=IT[v1*2].vals+IT[v1*2+1].vals-1;
        if (IT[v1*2].rnum>IT[v1*2+1].lnum)
        {
            IT[v1].vals++;
        }

        v1/=2;
    }

    return;
}

int main()
{
    Int i;
    Int num;
    Int p,x,y;
    Int d;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&num);

        nums[i]=num;

        IT[LEAFOFFSET+num].lnum=i;
        IT[LEAFOFFSET+num].rnum=i;
        IT[LEAFOFFSET+num].vals=1;
        IT[LEAFOFFSET+num].L=num;
        IT[LEAFOFFSET+num].R=num;
    }

    for (i=LEAFOFFSET+n+1;i<=LEAFOFFSET*2+1;i++)
    {
        IT[i].lnum=MAXVAL;
        IT[i].rnum=MAXVAL;
        IT[i].vals=1;
        IT[i].L=i-LEAFOFFSET;
        IT[i].R=i-LEAFOFFSET;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i].lnum=IT[2*i].lnum;
        IT[i].rnum=IT[2*i+1].rnum;
        IT[i].L=IT[2*i].L;
        IT[i].R=IT[2*i+1].R;
        IT[i].vals=IT[2*i].vals+IT[2*i+1].vals-1;

        if (IT[2*i].rnum>IT[2*i+1].lnum)
        {
            IT[i].vals++;
        }
    }

    scanf("%I64d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d %I64d",&p,&x,&y);

        if (p==1)
        {
            total=0;
            lastend=MAXVAL;
            Q(1,x,y);

            printf("%I64d\n",total);
        }
        else
        {
            Update(nums[x],nums[y]);
            d=nums[x];
            nums[x]=nums[y];
            nums[y]=d;
        }
    }
}