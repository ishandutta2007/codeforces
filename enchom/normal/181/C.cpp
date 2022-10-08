#include <iostream>
#include <algorithm>
using namespace std;

struct stock
{
    int sell,buy,q;
};
struct item
{
    int prof,q;
};

stock planets[11][101];
int n,m,k;

bool SortEm(item a,item b)
{
    return (a.prof>b.prof);
}

int Profit(int buyplanet,int sellplanet)
{
    item objects[101];
    int i;
    int totalprofit=0;
    int usedspace=0;
    int webuy;
    
    for (i=1;i<=m;i++)
    {
        objects[i].q=planets[buyplanet][i].q;
        objects[i].prof=planets[sellplanet][i].sell-planets[buyplanet][i].buy;
    }
    sort(objects+1,objects+1+m,SortEm);
    
    for (i=1;i<=m;i++)
    {
        if (objects[i].prof<=0)
        break;
        
        if (usedspace+objects[i].q<k)
        {
            usedspace=usedspace+objects[i].q;
            totalprofit=totalprofit+objects[i].q*objects[i].prof;
        }
        else
        {
            webuy=k-usedspace;
            totalprofit=totalprofit+objects[i].prof*webuy;
            break;
        }
    }
    return totalprofit;
}

int main()
{
    string useless;
    int i,j;
    int maxprofit=0;
    int currprofit;
    
    cin>>n>>m>>k;
    
    for (i=1;i<=n;i++)
    {
        cin>>useless;
        for (j=1;j<=m;j++)
        {
            cin>>planets[i][j].buy;
            cin>>planets[i][j].sell;
            cin>>planets[i][j].q;
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i==j)
            continue;
            
            currprofit=Profit(i,j);
            if ( currprofit>maxprofit )
            maxprofit=currprofit;
            
        }
    }
    cout<<maxprofit<<endl;
    return 0;
}