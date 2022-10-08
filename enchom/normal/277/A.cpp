#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

Int OFFSET=101;
bool TFO[1001];
vector<Int> Graph[1001];

void DFS(Int k)
{
    if (TFO[k])
    return;
    
    TFO[k]=true;
    
    Int i;
    
    for (i=0;i<Graph[k].size();i++)
    {
        DFS( Graph[k][i] );
    }
    
    return;
}

int main()
{
    Int n,m;
    Int i,j;
    Int L;
    Int lang;
    Int ctr=0;
    bool availablesource=false;
    
    for (i=0;i<=1000;i++)
    TFO[i]=false;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&L);
        
        if (L>0)
        availablesource=true;
        
        for (j=1;j<=L;j++)
        {
            scanf("%I64d",&lang);
            
            Graph[ lang+OFFSET ].push_back(i);
            Graph[i].push_back( lang+OFFSET );
        }
    }
    
    for (i=1;i<=n;i++)
    {
        if ( !TFO[i] )
        {
            DFS(i);
            ctr++;
        }
    }
    if (availablesource)
    ctr--;
    
    printf("%I64d\n",ctr);
    return 0;
}