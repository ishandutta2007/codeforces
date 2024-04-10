#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct cool
{
    Int key,times;
    Int incrkey;
};

vector<Int> whereare[1000001];
Int nums[4001];
Int TFO[1000001];
bool generalTFO[1000001];

Int Check(Int k,Int p)
{
    Int val1=nums[k],val2=nums[p];
    Int uk1,uk2;
    Int i;
    Int ctr=2;
    bool OK=false;
    
    uk1=0;
    uk2=0;
    
    for (i=0;i<whereare[val2].size();i++)
    {
        if (whereare[val2][i]>whereare[val1][0])
        {
            uk2=i;
            break;
        }
    }
    
    if (whereare[val2][uk1]<whereare[val1][0])
    return 0;
    
    while(uk1<whereare[val1].size() && uk2<whereare[val2].size())
    {
        if (whereare[val1][uk1]<whereare[val2][uk2])
        {
            OK=false;
            uk1++;
            while(uk1<whereare[val1].size())
            {
                if (whereare[val1][uk1]>whereare[val2][uk2])
                {
                    OK=true;
                    ctr++;
                    break;
                }
                uk1++;
            }
            if (!OK)
            {
                return ctr;
            }
        }
        else
        {
            OK=false;
            uk2++;
            while(uk2<whereare[val2].size())
            {
                if (whereare[val2][uk2]>whereare[val1][uk1])
                {
                    OK=true;
                    ctr++;
                    break;
                }
                uk2++;
            }
            if (!OK)
            {
                return ctr;
            }
        }
    }
    
    return ctr;
}

int main()
{
    Int n;
    Int i,j;
    Int maxlen=2;
    Int len;
    Int locked;
    Int validation=1;
    Int generalvalidation=1;
    Int curval;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
        
        whereare[ nums[i] ].push_back(i);
    }
    
    if (n<=2)
    {
        printf("%I64d\n",n);
        return 0;
    }
    
    for (i=0;i<=1000000;i++)
    {
        generalTFO[i]=false;
        TFO[i]=0;
    }
    
    for (i=1;i<=n;i++)
    {
        locked=nums[i];
        TFO[locked]=validation;
        if (generalTFO[locked])
        {
            validation++;
            continue;
        }
        generalTFO[locked]=true;
        for (j=i+1;j<=n;j++)
        {
            if ( TFO[ nums[j] ]!=validation )
            {
                TFO[nums[j]]=validation;
                len=Check(i,j);
                if (len>maxlen)
                maxlen=len;
            }
        }
        validation++;
    }
    
    for (i=0;i<=1000000;i++)
    {
        if (whereare[i].size()>maxlen)
        maxlen=whereare[i].size();
    }
    
    printf("%I64d\n",maxlen);
    return 0;
}