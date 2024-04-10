#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long Int;

struct cube
{
    Int color,sz,am,orgind;
};

struct c
{
    Int sz,orgind;
};

cube cubes[100001];
Int n;
vector<c> cubez[100001];
Int L=0;
vector<Int> bad;
bool TFO[100001];

const Int LEAFOFFSET=131071;
pair<Int,Int> IT[262144];

bool SC(cube a,cube b)
{
    return a.color<b.color;
}

void Update(Int ver,Int val)
{
    Int rver=ver+LEAFOFFSET;
    Int ind;

    IT[rver].first+=val;

    ind=rver/2;

    while(ind>0)
    {
        if (IT[2*ind].first>IT[2*ind+1].first)
        {
            IT[ind]=IT[2*ind];
        }
        else
        {
            IT[ind]=IT[2*ind+1];
        }

        ind=ind/2;
    }

    return;
}

Int GetVal(Int ind)
{
    return IT[ind+LEAFOFFSET].first;
}

pair<Int,Int> GetMax()
{
    return IT[1];
}

bool SortC(c a,c b)
{
    return a.sz>b.sz;
}

int main()
{
    Int i;
    Int oldc;
    Int uk=0;
    pair<Int,Int> tmax;
    Int curans;
    Int maxans=0;
    Int curval;
    Int t1,t2;
    c help;
    bool OK=true;

    for (i=LEAFOFFSET+1;i<=2*LEAFOFFSET+1;i++)
    {
        IT[i].first=0;
        IT[i].second=i-LEAFOFFSET;
    }
    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i]=IT[2*i];
    }

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&cubes[i].color,&cubes[i].sz);

        cubes[i].orgind=i;
    }

    sort(cubes+1,cubes+1+n,SC);

    oldc=-1;

    for (i=1;i<=n;i++)
    {
        if (cubes[i].color!=oldc)
        {
            L++;
            help.sz=cubes[i].sz;
            help.orgind=cubes[i].orgind;
            cubez[L].push_back(help);
            oldc=cubes[i].color;
        }
        else
        {
            help.sz=cubes[i].sz;
            help.orgind=cubes[i].orgind;
            cubez[L].push_back(help);
        }
    }

    for (i=1;i<=L;i++)
    {
        sort(cubez[i].begin(),cubez[i].end(),SortC);
    }

    uk=0;
    while(OK)
    {
        if (bad.size()>0)
        bad.clear();

        ///cout<<"New iteration"<<endl<<endl;

        for (i=1;i<=L;i++)
        {
            if (uk>cubez[i].size())
            {
                continue;
            }
            else if (uk==cubez[i].size())
            {
                bad.push_back(i);
                ///cout<<"Identified a bad guy "<<i<<endl<<endl;
            }
            else
            {
                Update(i,cubez[i][uk].sz);
                ///cout<<"Adding cube "<<cubez[i][uk].orgind<<" to the color it belongs"<<endl;
                ///cout<<"Resulting in "<<GetVal(i)<<endl<<endl;
            }
        }

        for (i=0;i<bad.size();i++)
        {
            curval=GetVal( bad[i] );
            Update(bad[i],0-curval-1);

            ///cout<<"Killing value of "<<bad[i]<<endl;
            ///cout<<"It is now "<<GetVal(bad[i])<<endl;

            tmax=GetMax();

            ///cout<<"His determined maximum is in tower "<<tmax.second<<" with value of "<<tmax.first<<endl<<endl;

            if (tmax.first<1)
            {
                OK=false;
                break;
            }
            else
            {
                curans=tmax.first+curval;

                if (curans>maxans)
                {
                    maxans=curans;
                    t1=bad[i];
                    t2=tmax.second;
                }
            }
        }

        uk++;
    }

    printf("%I64d\n",maxans);
    if (cubez[t2].size()>cubez[t1].size())
    {
        printf("%I64d\n",(Int)cubez[t1].size()*2+1);

        for (i=0;i<cubez[t1].size();i++)
        {
            printf("%I64d %I64d ",cubez[t2][i].orgind,cubez[t1][i].orgind);
        }
        printf("%I64d\n",cubez[t2][i].orgind);
    }
    else
    {
        printf("%I64d\n",(Int)cubez[t1].size()*2);

        for (i=0;i<cubez[t1].size();i++)
        {
            printf("%I64d %I64d",cubez[t1][i].orgind,cubez[t2][i].orgind);

            if (i<(Int)cubez[t1].size()-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}