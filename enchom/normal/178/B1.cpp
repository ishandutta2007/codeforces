#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct rb
{
    int a,b;
};

struct merch
{
    int warehouse,town,tax;
};

merch merchants[100001];
vector<int> graph[100001];
rb rebra[100001];
int TFO[100001];
int tL,tail[100001];

int main()
{
    int n,m;
    int a,b;
    int i,j,in;
    int uk;
    int p,k;
    
    scanf("%d %d",&n,&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
        rebra[i].a=a;
        rebra[i].b=b;
    }
    scanf("%d",&k);
    for (i=1;i<=k;i++)
    {
        scanf("%d %d",&a,&b);
        merchants[i].warehouse=a;
        merchants[i].town=b;
        merchants[i].tax=0;
    }
    
    for (i=1;i<=m;i++)
    {
        p=1;
        
        for (j=0;j<=n;j++)
        TFO[j]=0;
        
        for (j=1;j<=n;j++)
        {
            if (TFO[j]==0)
            {
                tL=1;
                tail[1]=j;
                TFO[j]=p;
                uk=1;
                while (uk<=tL)
                {
                    for (in=0;in<graph[ tail[uk] ].size();in++)
                    {
                        if ( TFO[ graph[tail[uk]][in] ]==0 && !( rebra[i].a==tail[uk] && rebra[i].b==graph[tail[uk]][in] ) && !( rebra[i].b==tail[uk] && rebra[i].a==graph[tail[uk]][in] ) )
                        {
                            tL++;
                            tail[tL]=graph[tail[uk]][in];
                            TFO[graph[tail[uk]][in]]=p;
                        }
                    }
                    uk++;
                }
                p++;
            }
        }
        
        for (j=1;j<=k;j++)
        {
            if (TFO[ merchants[j].warehouse ]!=TFO[ merchants[j].town ])
            {
                merchants[j].tax=merchants[j].tax+1;
            }
        }
    }
    for (i=1;i<=k;i++)
    {
        printf("%d\n",merchants[i].tax);
    }
    return 0;
}