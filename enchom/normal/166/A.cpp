#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;

struct team
{
    Int problems,t;
};

team teams[100];

bool SortEm(team a,team b)
{
    if (a.problems>b.problems)
    return true;
    else if (a.problems<b.problems)
    return false;
    else
    {
        return (a.t<b.t);
    }
}

int main()
{
    Int n,k;
    Int share=0;
    Int i;
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>teams[i].problems;
        cin>>teams[i].t;
    }
    sort(teams+1,teams+1+n,SortEm);
    for (i=k-1;i>=1;i--)
    {
        if (teams[i].problems==teams[k].problems && teams[i].t==teams[k].t)
        share++;
        else
        break;
    }
    for (i=k+1;i<=n;i++)
    {
        if (teams[i].problems==teams[k].problems && teams[i].t==teams[k].t)
        share++;
        else
        break;
    }
    share++;
    cout<<share<<endl;
    return 0;
}