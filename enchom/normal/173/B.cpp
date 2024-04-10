#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long Int;

struct cell
{
    char roc;
    Int ind;
    Int cost;
};

bool rows[1001],columns[1001];
cell tail[1000001];
Int tL=0;
char chamber[1001][1001];

int main()
{
    Int n,m;
    Int i,j;
    char input;
    Int uk;
    
    cin>>n>>m;
    
    for (i=0;i<=1000;i++)
    {
        rows[i]=false;
        columns[i]=false;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%c",&input);
            if (input==10)
            j--;
            else
            chamber[i][j]=input;
        }
    }
    rows[n]=true;
    tL=1;
    tail[1].roc='r';
    tail[1].ind=n;
    tail[1].cost=0;
    uk=1;
    while (uk<=tL)
    {
        if (tail[uk].roc=='r')
        {
            if (tail[uk].ind==1)
            {
                cout<<tail[uk].cost<<endl;
                return 0;
            }
            for (i=1;i<=m;i++)
            {
                if (chamber[ tail[uk].ind ][i]=='#')
                {
                    if (!columns[i])
                    {
                        columns[i]=true;
                        tL++;
                        tail[tL].roc='c';
                        tail[tL].ind=i;
                        tail[tL].cost=tail[uk].cost+1;
                        ///cout<<"column "<<i<<" will cost "<<tail[tL].cost<<" because of row "<<tail[uk].ind<<endl;
                    }
                }
            }
        }
        if (tail[uk].roc=='c')
        {
            for (i=1;i<=n;i++)
            {
                if (chamber[i][ tail[uk].ind ]=='#')
                {
                    if (!rows[i])
                    {
                        rows[i]=true;
                        tL++;
                        tail[tL].roc='r';
                        tail[tL].ind=i;
                        tail[tL].cost=tail[uk].cost+1;
                        ///cout<<"row "<<i<<" will cost "<<tail[tL].cost<<" because of column "<<tail[uk].ind<<endl;
                    }
                }
            }
        }
        uk++;
    }
    cout<<-1<<endl;
    return 0;
}