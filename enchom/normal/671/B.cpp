#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int n;
Int k;
int nums[500111];

pair<int,int> groups[500111];
int L=0;

int main()
{
    int i,j;
    int reachnext;
    Int need;
    int cursize;
    int val1,val2;
    Int sum=0;
    Int remk;
    Int canadd;

    scanf("%d %lld",&n,&k);

    remk=k;

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
        sum+=(Int)nums[i];
    }

    sort(nums+1,nums+1+n);

    L=1;
    groups[1]=make_pair(nums[1],1);
    for (i=2;i<=n;i++)
    {
        if (nums[i]==nums[i-1])
        groups[L].second++;
        else
        {
            L++;
            groups[L]=make_pair(nums[i],1);
        }
    }

    ///
    cursize=groups[1].second;
    val1=groups[1].first;

    for (i=1;i<L;i++)
    {
        reachnext=groups[i+1].first-groups[i].first;

        need=(Int)cursize*(Int)reachnext;

        //cout<<"need "<<need<<" to jump from "<<i<<endl;
        //cout<<"Have "<<k<<endl;

        if (need>k)
        {
            canadd=k/(Int)cursize;
            val1+=canadd;

            break;
        }

        k-=need;

        cursize+=groups[i+1].second;
        val1=groups[i+1].first;
    }
    ///

    k=remk;

    ///
    cursize=groups[L].second;
    val2=groups[L].first;

    for (i=L;i>1;i--)
    {
        reachnext=groups[i].first-groups[i-1].first;

        need=(Int)cursize*(Int)reachnext;

        //cout<<"need "<<need<<" to jump from "<<i<<endl;
        //cout<<"Have "<<k<<endl;

        if (need>k)
        {
            canadd=k/(Int)cursize;
            val2-=canadd;

            break;
        }

        k-=need;

        cursize+=groups[i-1].second;
        val2=groups[i-1].first;
    }

    //cout<<val1<<" "<<val2<<endl;

    if (val1>=val2)
    {
        if (sum%(Int)n==0)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    else
    {
        printf("%d\n",val2-val1);
    }

    return 0;
}