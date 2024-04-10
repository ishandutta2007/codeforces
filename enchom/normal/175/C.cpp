#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;

struct figure
{
    Int amount,cost;
};

figure types[101];
Int factor[101];

bool SortEm(figure a,figure b)
{
    return (a.cost<b.cost);
}

int main()
{
    Int n,t;
    Int i;
    Int killed=0;
    Int cfactor=1;
    Int uk1,uk2;
    Int points=0;
    
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>types[i].amount>>types[i].cost;
    }
    cin>>t;
    for (i=1;i<=t;i++)
    {
        cin>>factor[i];
    }
    
    sort(types+1,types+1+n,SortEm);
    
    uk1=1;
    uk2=1;
    while (1)
    {
        if (uk1>n)
        break;
        
        if (uk2<=t)
        {
            if (types[uk1].amount>=factor[uk2]-killed)
            {
                types[uk1].amount=types[uk1].amount-(factor[uk2]-killed);
                points=points+(factor[uk2]-killed)*types[uk1].cost*cfactor;
                killed=factor[uk2];
                uk2++;
                cfactor++;
                if (types[uk1].amount==0)
                uk1++;
            }
            else
            {
                points=points+types[uk1].amount*types[uk1].cost*cfactor;
                killed=killed+types[uk1].amount;
                uk1++;
            }
        }
        else
        {
            points=points+types[uk1].amount*types[uk1].cost*cfactor;
            killed=killed+types[uk1].amount;
            uk1++;
        }
    }
    cout<<points<<endl;
    return 0;
}