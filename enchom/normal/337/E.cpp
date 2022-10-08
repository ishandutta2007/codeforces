#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long Int;

struct node
{
    vector<Int> children;
    Int father;
    Int val;
};

Int nums[9];
Int n;
node nodes[10];
Int L=0;
Int minvers=999999;
Int factorizations[9][101];
Int fL[9];

void Batrak(Int curnum)
{
    Int i;

    if (curnum>n)
    {
        ///cout<<"Found assignation"<<endl<<endl;

        Int ctr=L,rval;
        Int cur;
        Int j;
        bool bad=false;

        for (i=1;i<=L;i++)
        {
            if (nodes[i].val!=-1)
            {
                rval=1;
                for (j=0;j<nodes[i].children.size();j++)
                {
                    rval=rval*nodes[ nodes[i].children[j] ].val;
                }

                if (nodes[1].val==-1)
                {
                    cur=i-1;
                }
                else
                {
                    cur=i;
                }

                ///cout<<"Working on "<<nodes[i].val<<" a.k.a "<<cur<<endl;

                ///cout<<"Got rval="<<rval<<endl<<endl;

                if (fL[cur]==1 && rval==1)
                {
                    continue;
                }

                for (j=1;j<=fL[cur];j++)
                {
                    ///cout<<"Find divisor = "<<factorizations[cur][j]<<endl;
                    if (rval%factorizations[cur][j]==0)
                    {
                        rval/=factorizations[cur][j];
                    }
                    else
                    {
                        ctr++;
                        ///cout<<"ctr="<<ctr<<endl<<endl;
                    }
                }

                if (rval>1)
                {
                    bad=true;
                    break;
                }
            }
        }

        if (bad)
        return;

        if (ctr<minvers)
        minvers=ctr;
    }
    else
    {
        for (i=1;i<=L;i++)
        {
            if (nodes[i].val==-1 || nodes[i].val%nums[curnum]==0)
            {
                ///cout<<nums[curnum]<<" becomes a child of "<<nodes[i].val<<endl;
                L++;
                nodes[L].children.clear();
                nodes[L].father=i;
                nodes[L].val=nums[curnum];

                nodes[i].children.push_back(L);

                Batrak(curnum+1);

                nodes[i].children.pop_back();
                L--;
            }
        }
    }

    return;
}

void Factorize(Int k)
{
    Int num=nums[k];
    Int i;

    fL[k]=0;

    for (i=2;i*i<=nums[k];i++)
    {
        while (num%i==0)
        {
            num/=i;
            fL[k]++;
            factorizations[k][ fL[k] ]=i;
        }
    }

    if (num>1)
    {
        fL[k]++;
        factorizations[k][ fL[k] ]=num;
    }

    return;
}

int main()
{
    Int i;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    sort(nums+1,nums+1+n);
    reverse(nums+1,nums+1+n);

    for (i=1;i<=n;i++)
    {
        Factorize(i);
    }

    L=1;
    nodes[1].val=-1;
    nodes[1].father=-1;

    ///cout<<"Root is infinite"<<endl<<endl;

    Batrak(1);

    L=1;
    nodes[1].children.clear();
    nodes[1].val=nums[1];
    nodes[1].father=-1;

    ///cout<<"Root is "<<nums[1]<<endl<<endl;

    Batrak(2);

    printf("%I64d\n",minvers);

    return 0;
}