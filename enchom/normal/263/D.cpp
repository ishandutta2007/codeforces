#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

vector<Int> Graph[100001];
bool TFO[100001];
Int fallen[100001];
Int cL=0;
Int cycle[100001];
Int stack[100001];
Int sL=0;
Int n,m,k;
bool found=false;

void DFS(Int ver)
{
    Int i,j;
    Int vertex;
    
    sL++;
    stack[sL]=ver;
    fallen[ver]=sL;
    TFO[ver]=true;
    
    for (i=0;i<Graph[ver].size();i++)
    {
        vertex=Graph[ver][i];
        if ( !TFO[vertex] )
        {
            DFS(vertex);
            if (found)
            return;
        }
        else
        {
            if (sL-fallen[vertex]+1>=k+1)
            {
                cL=sL-fallen[vertex]+1;
                for (j=fallen[vertex];j<=sL;j++)
                {
                    cycle[j-fallen[vertex]+1]=stack[j];
                }
                found=true;
                return;
            }
        }
    }
    
    sL--;
    return;
}

int main()
{
    Int i;
    Int a,b;
        
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    for (i=0;i<=100000;i++)
    {
        TFO[i]=false;
        fallen[i]=0;
    }
    for (i=1;i<=n;i++)
    {
        if (!TFO[i])
        {
            DFS(i);
            if (found)
            {
                printf("%I64d\n",cL);
                for (i=1;i<=cL;i++)
                {
                    printf("%I64d",cycle[i]);
                    if (i!=cL)
                    printf(" ");
                    else
                    printf("\n");
                }
                return 0;
            }
        }
    }
    return 0;
}