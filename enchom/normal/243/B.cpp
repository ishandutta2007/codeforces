#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct rebro
{
    Int ver1,ver2;
};

rebro rebra[200001];
vector<Int> graph[200001];
Int n,m;
Int h,t;

Int tails[200001];
Int heads[200001];
Int TFO[200001];
Int tL=0;
Int hL=0;

/*Int Interaction(Int v1,Int v2)
{
    Int uk1=0,uk2=0;
    Int counter=0;
    
    while( uk1<graph[v1].size() && uk2<graph[v2].size() )
    {
        if ( graph[v1][uk1]==graph[v2][uk2] )
        {
            counter++;
            uk1++;
        }
        else if ( graph[v1][uk1]<graph[v2][uk2] )
        {
            uk1++;
        }
        else
        {
            uk2++;
        }
    }
    return counter;
}*/

int main()
{
    Int i,j;
    Int a,b;
    Int v1,v2,d;
    Int uk1,uk2;
    Int ans;
    Int NoTry=1;
    Int len=0;
    
    for (i=0;i<=200000;i++)
    TFO[i]=0;
    
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&h,&t);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        len++;
        rebra[len].ver1=a;
        rebra[len].ver2=b;
        
        len++;
        rebra[len].ver1=b;
        rebra[len].ver2=a;
    }
    for (i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    for (i=1;i<=len;i++)
    {
        v1=rebra[i].ver1;
        v2=rebra[i].ver2;
        
        if (graph[v1].size()-1<h || graph[v2].size()-1<t)
        continue;
        
        if ( (graph[v1].size()-1>=h+t && graph[v2].size()-1>=t) || (graph[v2].size()-1>=h+t && graph[v1].size()-1>=h) )
        {
            ///Do it
            tL=0;
            hL=0;
            
            if (graph[v1].size()<graph[v2].size())
            {
                for (j=0;j<graph[v1].size();j++)
                {
                    if (graph[v1][j]==v2)
                    continue;
                
                    hL++;
                    heads[hL]=graph[v1][j];
                    TFO[ graph[v1][j] ]=NoTry;
                
                    if (hL==h)
                    break;
                }
                for (j=0;j<graph[v2].size();j++)
                {
                    if ( graph[v2][j]==v1 )
                    continue;
                    if (TFO[ graph[v2][j] ]==NoTry)
                    continue;
                    
                    tL++;
                    tails[tL]=graph[v2][j];
                    
                    if (tL==t)
                    break;
                }
            }
            else
            {
                for (j=0;j<graph[v2].size();j++)
                {
                    if (graph[v2][j]==v1)
                    continue;
                
                    tL++;
                    tails[tL]=graph[v2][j];
                    TFO[ graph[v2][j] ]=NoTry;
                
                    if (tL==t)
                    break;
                }
                for (j=0;j<graph[v1].size();j++)
                {
                    if ( graph[v1][j]==v2 )
                    continue;
                    if (TFO[ graph[v1][j] ]==NoTry)
                    continue;
                    
                    hL++;
                    heads[hL]=graph[v1][j];
                    
                    if (hL==h)
                    break;
                }
            }
          
            
            printf("YES\n");
            printf("%I64d %I64d\n",v1,v2);
            for (j=1;j<=h;j++)
            {
                printf("%I64d",heads[j]);
                if (j!=h)
                printf(" ");
                else
                printf("\n");
            }
            for (j=1;j<=t;j++)
            {
                printf("%I64d",tails[j]);
                if (j!=t)
                printf(" ");
                else
                printf("\n");
            }
            return 0;
        }
        else
        {
            ///uk1 - h
            ///uk2 - t
            uk1=0;
            uk2=0;
            hL=0;
            tL=0;
            
            while( uk1<graph[v1].size() || uk2<graph[v2].size() )
            {
                if (uk1==graph[v1].size())
                {
                    if (graph[v2][uk2]==v1)
                    {
                        uk2++;
                        continue;
                    }
                    
                    tL++;
                    TFO[ graph[v2][uk2] ]=NoTry;
                    tails[tL]=graph[v2][uk2];
                    uk2++;
                    continue;
                }
                if (uk2==graph[v2].size())
                {
                    if (graph[v1][uk1]==v2)
                    {
                        uk1++;
                        continue;
                    }
                    
                    hL++;
                    TFO[ graph[v1][uk1] ]=NoTry;
                    heads[hL]=graph[v1][uk1];
                    uk1++;
                    continue;
                }
                
                if (graph[v1][uk1]==v2)
                {
                    uk1++;
                    continue;
                }
                if (graph[v2][uk2]==v1)
                {
                    uk2++;
                    continue;
                }
                
                if ( graph[v1][uk1]==graph[v2][uk2] )
                {
                    uk1++;
                    uk2++;
                }
                else if ( graph[v1][uk1]<graph[v2][uk2] )
                {
                    TFO[ graph[v1][uk1] ]=NoTry;
                    hL++;
                    heads[hL]=graph[v1][uk1];
                    uk1++;
                }
                else
                {
                    TFO[ graph[v2][uk2] ]=NoTry;
                    tL++;
                    tails[tL]=graph[v2][uk2];
                    uk2++;
                }
            }
            for (j=0;j<graph[v1].size();j++)
            {
                if ( TFO[ graph[v1][j] ]!=NoTry )
                {
                    if (graph[v1][j]==v2)
                    continue;
                    
                    if (tL<t)
                    {
                        tL++;
                        tails[tL]=graph[v1][j];
                    }
                    else
                    {
                        hL++;
                        heads[hL]=graph[v1][j];
                    }
                }
            }
            if (tL>=t && hL>=h)
            {
                printf("YES\n");
                printf("%I64d %I64d\n",v1,v2);
                for (i=1;i<=h;i++)
                {
                    printf("%I64d",heads[i]);
                    if (i!=h)
                    printf(" ");
                    else
                    printf("\n");
                }
                for (i=1;i<=t;i++)
                {
                    printf("%I64d",tails[i]);
                    if (i!=t)
                    printf(" ");
                    else
                    printf("\n");
                }
                return 0;
            }
            NoTry++;
        }
    }
    printf("NO\n");
    return 0;
}