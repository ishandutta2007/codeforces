#include <iostream>
#include <stdio.h>
using namespace std;
#define LIMIT 10000000

int gcd(int a,int b)
{
    int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

int n;
int nums[501];
int cost[501];

pair<int,int> possibles[LIMIT+1];
int L=0;

int bestcost[LIMIT+1];

int main()
{
    int i,j;
    int nod;
    int newval;
    int newcost;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&cost[i]);
    }

    for (i=1;i<=n;i++)
    {
        if (L==0)
        {
            L++;
            possibles[L]=make_pair(nums[i],cost[i]);

            if (nums[i]<LIMIT)
            bestcost[ nums[i] ]=cost[i];
        }
        else
        {
            j=L;
            for (;j>=1;j--)
            {
                newval=gcd(possibles[j].first,nums[i]);
                newcost=possibles[j].second+cost[i];

                //cout<<"Pushing "<<nums[i]<<" on "<<possibles[j].first<<" with result "<<newval<<endl;

                if (newval==possibles[j].first)
                continue;

                if (newval<LIMIT)
                {
                    if (bestcost[newval]<=newcost && bestcost[newval]!=0)
                    continue;

                    if (bestcost[newval]>newcost || bestcost[newval]==0)
                    {
                        //cout<<"Upgrading best cost of "<<newval<<" to "<<newcost<<endl;
                        bestcost[newval]=newcost;
                    }
                }

                if (newval==1)
                continue;

                L++;
                possibles[L]=make_pair(newval,newcost);

                //cout<<"Adding "<<newval<<" of cost "<<newcost<<endl;
            }

            if (nums[i]<LIMIT)
            {
                if (bestcost[ nums[i] ]<=cost[i] && bestcost[ nums[i] ]!=0)
                continue;

                if (bestcost[ nums[i] ]>cost[i] || bestcost[ nums[i] ]==0)
                {
                    bestcost[ nums[i] ]=cost[i];
                }
            }

            if (nums[i]==1)
            continue;

            L++;
            possibles[L]=make_pair(nums[i],cost[i]);
        }
    }

    if (bestcost[1]!=0)
    printf("%d\n",bestcost[1]);
    else
    printf("-1\n");

    return 0;
}