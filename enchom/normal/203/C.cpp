#include <iostream>
#include <algorithm>
using namespace std;

struct client
{
    int space,orgind;
};

client clients[100001];
int cando[100001],cL=0;

bool SortEm(client a,client b)
{
    return (a.space<b.space);
}

int main()
{
    int n,d;
    int lq,hq;
    int i,a,b,filled=0;
    
    cin>>n>>d;
    cin>>lq>>hq;
    for (i=1;i<=n;i++)
    {
        cin>>a>>b;
        clients[i].orgind=i;
        clients[i].space=a*lq+b*hq;
    }
    sort(clients+1,clients+1+n,SortEm);
    for (i=1;i<=n;i++)
    {
        if (clients[i].space<=d)
        {
            if (clients[i].space+filled<=d)
            {
                filled=filled+clients[i].space;
                cL++;
                cando[cL]=clients[i].orgind;
            }
            else
            break;
        }
        else
        break;
    }
    cout<<cL<<endl;
    for (i=1;i<=cL;i++)
    {
        if (i!=cL)
        cout<<cando[i]<<" ";
        else
        cout<<cando[i]<<endl;
    }
    return 0;
}